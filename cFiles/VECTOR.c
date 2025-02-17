#include "objects/structures/Vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    Vector vec;
    vector_init(&vec, sizeof(int));

    for (int i = 0; i < 10; i++) {
        vector_push_back(&vec, &i); // Добавляем элементы
    }

    for (size_t i = 0; i < vec.size; i++) {
        int *value = (int*)vector_get(&vec, i); // Получаем элемент по индексу
        printf("%d ", *value);
    }
    free(vec.data);
    return 0;
}


