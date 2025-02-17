#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Bool.h"
#include "Pair.h"

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

typedef struct QueuePairts{
    Pairts inf;
    bool initialized;
    struct QueuePairts * next; 
} QueuePairts;

#define QUEUEINT_INIT {0, false, NULL}
#define QUEUESTRING_INIT {NULL, false, NULL}
#define QUEUEQS_INIT {NULL, false, NULL}
#define QUEUEPTS_INIT {PAIRTS_NOPAIRTS, false, NULL}

/*
Функции добавление элементов в очередь
Add new elements into queue functions
*/

void addToQueueInt(QueueInt * q, int n){
    if(q == NULL){
        MWARNING
        return;
    }

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

void addToQueuePairts(QueuePairts *q, Pairts n) { 
    if(q == NULL){
        MWARNING
        return;
    }

    QueuePairts * lastq = q;
    QueuePairts * newqueue = (QueuePairts*)malloc(sizeof(QueuePairts));
    newqueue->inf = n;
    newqueue->next = NULL;
    
    while (lastq->next != NULL)
    {
        lastq = lastq->next;
    }

    if (lastq->initialized != false) {lastq->next = newqueue;}    
    else {q->inf = n; q->initialized = true;}
}

/*
Функции для отображения
Display functions
*/

void printQueueInt(QueueInt * q){
    if (!q->initialized){
        puts("[]");
        return;
    }
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
    if (!q->initialized){
        puts("[]");
        return;
    }
    QueueString *lastq = q;

    printf("[");
    while (lastq != NULL) {
        printf("\"%s\"", lastq->inf);
        if (lastq->next) printf(", ");
        lastq = lastq->next;
    }
    printf("]\n");
}

void printQueuePairts(QueuePairts *q) {
    if (!q->initialized){
        puts("[]");
        return;
    }
    
    QueuePairts *lastq = q;
    printf("[");
    while (lastq != NULL) {
        printf("(%s , \"%s\")", get_name(lastq->inf.first), lastq->inf.second);
        if (lastq->next) printf(", ");
        lastq = lastq->next;
    }
    printf("]\n");
}

/*
Функции для получения значения
Get functions
*/

int getInt(QueueInt * q){
    if (q == NULL) {
        puts("Queue is empty!");
        q->initialized = false;
        return 0;
    }
    
    int newnum = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{ 
        q->inf = 0;
        q->initialized = false;
    }

    return newnum;
}

char * getString(QueueString * q){
    if (q == NULL) {
        puts("Queue is empty!");
        q->initialized = false;
        return "\0";
    }
    
    char * newstr = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{ 
        q->inf = NULL;
        q->initialized = false;
    }

    return newstr;
}

Pairts getPairts(QueuePairts * q){
    if (q == NULL) {
        puts("Queue is not exists!");
        q->initialized = false;
        Pairts newpair = {TYPE_NOTYPE, NULL};
        return newpair;
    }

    Pairts newpair = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{
        Pairts temp = {TYPE_NOTYPE, NULL}; 
        q->inf = temp;
        q->initialized = false;
    }
    return newpair;
}