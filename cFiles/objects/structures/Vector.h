#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *data;          // Указатель на данные
    size_t element_size; // Размер элемента
    size_t capacity;     // Вместимость вектора
    size_t size;         // Текущий размер вектора
} Vector;
void vector_init(Vector *vec, size_t element_size) {
    vec->data = NULL;
    vec->element_size = element_size;
    vec->size = 0;
    vec->capacity = 0;
}

// chatgpt  хз мб рабоает
Vector* vector_create(size_t element_size) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (vec == NULL) {
        perror("404");
        exit(EXIT_FAILURE);
    }
    vec->element_size = element_size;
    vec->capacity = 4; // Начальная вместимость
    vec->size = 0;
    vec->data = malloc(vec->capacity * element_size);
    if (vec->data == NULL) {
        perror("ERROR 45");
        free(vec);
        exit(EXIT_FAILURE);
    }
    return vec;
}



int neww(int vs) { 
    if (vs < 8) {
        return 4;
    } else if (vs < 16) {
        return 8;
    } else {
        return (int)(vs * 1.5f); 
    }
}

void vector_resize(Vector *vec) {
    vec->capacity *= neww(vec->size);
    vec->data = realloc(vec->data, vec->capacity * vec->element_size);
    if (vec->data == NULL) {
        perror("ERROR 142");
        exit(EXIT_FAILURE);
    }
}

void vector_push_back(Vector *vec, void *element) {

    if (vec->size >= vec->capacity && vec->data == NULL) {
        vector_resize(vec);
    }
    memcpy((char*)vec->data + (vec->size * vec->element_size), element, vec->element_size);
    vec->size++;
}

void* vector_get(Vector *vec, size_t index) {
    
    if (index >= vec->size) {
        perror("ERROR 404");
        exit(EXIT_FAILURE);
    }
    return (char*)vec->data + (index * vec->element_size);
}
 