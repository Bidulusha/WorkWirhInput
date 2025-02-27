#pragma once

#include "../enums/Types.h"

typedef struct {
    int first;
    int second;
} PairIntInt;

typedef struct{
    int first;
    char * second;
} PairIntSting;

typedef struct {
    char * first;
    int second;
} PairStringInt;

typedef struct{
    VariablesTypes first;
    char * second;
} PairTypesString;

typedef struct{
    char * first;
    PairTypesString second;
} PairStringPairTypesString;

#define PAIRTYPESTRING_NOPAIR {TYPE_NOTYPE, NULL}
#define PAIRSTRINGSTRING_NOPAIR {NULL, NULL}
#define PAIRSTRINGPAIRTYPESSTRING_NOPAIT {NULL, PAIRTYPESTRING_NOPAIR}