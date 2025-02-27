#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Bool.h"
#include "Pair.h"
#include "../Functions/additional.h"

#define DEBUG_TEXT(text) puts("________DEBUG TEXT________"); printf("%s\n", text); 
#define MERROR puts("Memory allocation failed"); exit(1);
#define MWARNING puts("It's not exist");

typedef struct QueueInt{
    int inf;
    struct QueueInt * next;
    struct QueueInt * last;

    void (*print)(struct QueueInt * thisObject);
    void (*add)(struct QueueInt * thisObject, int number);

} QueueInt;

typedef struct QueueString{
    char * inf;
    struct QueueString * next;
    struct QueueString * last;

    void (*print)(struct QueueString * text);

} QueueString;

typedef struct QueueQueueString{ // Queue what has QueueString
    char * QueueString;
    struct QueueQS * next;
    struct QueueQueueString * last;

    void (*print)(struct QueueQueueString * text);

} QueueQueueString;

typedef struct QueuePairts{ // Queue what has PairTypesString
    PairTypesString inf;
    struct QueuePairts * next; 
    struct QueuePairts * last;

    void (*print)(struct QueuePairts * text);

} QueuePairTypesString;

typedef struct QueuePairspts{ // Queue what has PairStringParirTypesString
    PairStringPairTypesString inf;
    struct QueuePairspts * next; 
    struct QueuePairspts * last;

    void (*print)(struct QueuePairspts * text);

} QueuePairStringPairTypesString;

#define QUEUEINT_INIT {0, NULL, NULL, printQueueInt, addToQueueInt}
#define QUEUESTRING_INIT {NULL, NULL, NULL, printQueueString}
#define QUEUEQS_INIT {NULL, NULL, NULL, NULL}
#define QUEUEPTS_INIT {PAIRTYPESSTRING_NOPAI, NULL, NULL, printQueuePairts}
#define QUEUEPSS_INIT {PAIRSS_NOPAIR, NULL, NULL, printQueuePairspts}

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

    if (lastq->last == NULL){
        lastq->inf = n;
        lastq->last = lastq;
    }
    else{
        QueueInt * newqueue = (QueueInt*)malloc(sizeof(QueueInt));
        
        newqueue->inf = n;
        newqueue->next = NULL;

        lastq->last->next = newqueue;
        lastq->last = newqueue;
    }    
}

void addToQueueString(QueueString *q, char * n) { 
    if(q == NULL){
        MWARNING
        return;
    }

    QueueString * lastq = q;
    

    if (lastq->last == NULL){
        lastq->inf = n;
        lastq->last = lastq;
    }
    else{
        QueueString  * newqueue = (QueueString*)malloc(sizeof(QueueString));

        newqueue->inf = strdup(n);
        newqueue->next = NULL;
        newqueue->last = q;

        lastq->last->next = newqueue;
        lastq->last = newqueue;
    }

}

void addToQueuePairTS(QueuePairTypesString *q, PairTypesString n) { 
    
    if(q == NULL){
        MWARNING
        return;
    }

    QueuePairTypesString * lastq = q;
    
    
    if (lastq->last == NULL){
        lastq->inf = n;
        lastq->last = lastq;
    }
    else{
        QueuePairTypesString * newqueue = (QueuePairTypesString*)malloc(sizeof(QueuePairTypesString));
    
        newqueue->inf = n;
        newqueue->next = NULL;
        newqueue->last = q;

        lastq->last->next = newqueue;
        lastq->last = newqueue;
    }

}

void addToQueuePairSPTS(QueuePairStringPairTypesString *q, PairStringPairTypesString n) { 
    if(q == NULL){
        MWARNING
        return;
    }

    QueuePairStringPairTypesString * lastq = q;
    
    
    if (lastq->last == NULL){
        lastq->inf = n;
        lastq->last = lastq;
    }
    else{
        QueuePairStringPairTypesString * newqueue = (QueuePairStringPairTypesString*)malloc(sizeof(QueuePairStringPairTypesString));
    
        newqueue->inf = n;
        newqueue->next = NULL;

        lastq->last->next = newqueue;
        lastq->last = newqueue;
    }

}
/*
Функции для отображения
Display functions
*/

void printQueueInt(QueueInt * q){
    if (!q->last){
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
    if (!q->last){
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

void printQueuePairts(QueuePairTypesString *q) {
    if (!q->last){
        puts("[]");
        return;
    }
    
    QueuePairTypesString *lastq = q;
    printf("[");
    while (lastq != NULL) {
        printf("(%s , \"%s\")", get_name(lastq->inf.first), lastq->inf.second);
        if (lastq->next) printf(", ");
        lastq = lastq->next;
    }
    printf("]\n");
}

void printQueuePairspts(QueuePairStringPairTypesString *q) {
    if (!q->last){
        puts("[]");
        return;
    }
    
    QueuePairStringPairTypesString *lastq = q;
    printf("[");
    while (lastq != NULL) {
        printf("(%s , \"%s\")", lastq->inf.first, lastq->inf.second);
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
    if (!q->last) {
        puts("Queue is empty!");
        return 0;
    }
    
    int newnum = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{ 
        q->inf = 0;
        q->last = NULL;
    }

    return newnum;
}

char * getString(QueueString * q){
    if (!q->last) {
        puts("Queue is empty!");
        return "\0";
    }
    
    char * newstr = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{ 
        q->inf = NULL;
        q->last = NULL;
    }

    return newstr;
}

PairTypesString getPairts(QueuePairTypesString * q){
    if (!q->last) {
        puts("Queue is not exists!");
        PairTypesString newpair = {TYPE_NOTYPE, NULL};
        return newpair;
    }

    PairTypesString newpair = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{
        PairTypesString temp = {TYPE_NOTYPE, NULL}; 
        q->inf = temp;
        q->last = NULL;
    }
    return newpair;
}

PairStringPairTypesString getPairss(QueuePairStringPairTypesString * q){
    if (!q->last) {
        puts("Queue is not exists!");
        PairStringPairTypesString newpair = PAIRSTRINGPAIRTYPESSTRING_NOPAIT;
        return newpair;
    }

    PairStringPairTypesString newpair = q->inf;
    if (q->next != NULL){
        q->inf = q->next->inf;
        q->next = q->next->next;
    }
    else{
        PairStringPairTypesString temp = PAIRSTRINGPAIRTYPESSTRING_NOPAIT; 
        q->inf = temp;
        q->last = NULL;
    }
    return newpair;
}