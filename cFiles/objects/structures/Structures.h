#include "../enums/Types.h"
#include "../enums/Functions.h"
#include "Bool.h"

typedef struct{ // struct LineObjects
    Functions function;
    Types type;
} LineObjects;

#define LO_INIT {NOFUNCTION, NOTYPE}