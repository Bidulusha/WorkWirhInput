#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bool.h"

typedef struct QueueInt{
    int inf;
    bool initialized;
    struct QueueInt * next;
} QueueInt;

typedef struct QueueString{
    char * inf;
    bool initialized;
    struct QueueString * next;
} QueueString;

typedef struct QueueQS{ // Queue what have QueueString
    char * QueueString;
    bool initialized;
    struct QueueQS * next;
} QueueQS;

#define QUEUEINT_INIT {0, false, NULL}
#define QUEUEINT_STRING {NULL, false, NULL}

/*
Функции добавление элементов в очередь
Add new elements into queue functions
*/

void addToQueueInt(QueueInt * q, int n){
    QueueInt * lastq = q;
    QueueInt * newqueue = (QueueInt*)malloc(sizeof(QueueInt));
    newqueue->inf = n;
    newqueue->next = NULL;
    
    while (lastq->next != NULL)
    {
        lastq = lastq->next;
    }

    if (lastq->initialized != false) {lastq->next = newqueue;}    
    else {q->inf = n; q->initialized = true;}
    
}

void addToQueueString(QueueString *q, char *n) { 
    QueueString *lastq = q;
    QueueString *newqueue = (QueueString*)malloc(sizeof(QueueString));

    if (!newqueue) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    // Копируем строку в новую область памяти
    newqueue->inf = strdup(n);  // strdup автоматически выделяет память и копирует строку

    if (!newqueue->inf) {
        printf("Ошибка выделения памяти под строку\n");
        free(newqueue);
        return;
    }

    newqueue->next = NULL;

    while (lastq->next != NULL) {
        lastq = lastq->next;
    }

    if (lastq->initialized) {
        lastq->next = newqueue;
    } else {
        q->inf = strdup(n); // Копируем строку в первый узел
        q->initialized = true;
        free(newqueue); // Освобождаем ненужную структуру
    }
}

/*
Функции для отображения
Display functions
*/

void printQueueInt(QueueInt * q){
    QueueInt * lastq = q;

    printf("[");
    while (lastq != NULL) {
        printf("\"%s\"", lastq->inf);
        if (lastq->next) printf(", ");
        lastq = lastq->next;
    }
    printf("]\n");
}

void printQueueString(QueueString *q) {
    QueueString *lastq = q;

    printf("[");
    while (lastq != NULL) {
        printf("\"%s\"", lastq->inf);
        if (lastq->next) printf(", ");
        lastq = lastq->next;
    }
    printf("]\n");
}