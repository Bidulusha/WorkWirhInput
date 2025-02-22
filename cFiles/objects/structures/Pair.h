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
    VariablesTypes first;
    char * second;
} Pairts;

typedef struct{
    char * first;
    Pairts second;
} Pairspts;

#define PAIRTS_NOPAIRTS {TYPE_NOTYPE, NULL}
#define PAIRSS_NOPAIRSS {NULL, NULL}