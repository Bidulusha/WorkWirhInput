#pragma once

#include "../enums/Types.h"

typedef struct {
    int first;
    int second;
} Pairii;

typedef struct{
    int first;
    char * second;
} Pairis;

typedef struct {
    char * first;
    int second;
} Pairsi;

typedef struct{
    char * first;
    char * second;
} Pairss;

typedef struct{
    VariablesTypes first;
    char * second;
} Pairts;

#define PAIRTS_NOPAIRTS {TYPE_NOTYPE, NULL}