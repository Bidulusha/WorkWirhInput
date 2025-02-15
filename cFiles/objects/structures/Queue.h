#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Bool.h"

#define DEBUG_TEXT(text) puts("________DEBUG TEXT________"); printf("%s\n", text); 
#define MERROR puts("Memory allocation failed"); exit(1);
#define MWARNING puts("It's not exist");

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
#define QUEUESTRING_INIT {NULL, false, NULL}

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

void addToQueueString(QueueString *q, char * n) { 
    if(q == NULL){
        MWARNING
        return;
    }

    QueueString * last = q;
    QueueString  * newqueue = (QueueString*)malloc(sizeof(QueueString));

    newqueue->inf = strdup(n);
    newqueue->initialized = true;
    newqueue->next = NULL;

    while(last -> next != NULL){
        last = last->next;
    }

    if(q->initialized){
        last->next = newqueue;
    }
    else{
        q->inf = strdup(n);
        q->initialized = true;
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
        printf("\"%d\"", lastq->inf);
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

char * getString(QueueString * q){
    if (q == NULL) return "\0";
    
    char * newstr = q->inf;
    q->inf = q->next->inf;
    q->next = q->next->next;

    return newstr;
}