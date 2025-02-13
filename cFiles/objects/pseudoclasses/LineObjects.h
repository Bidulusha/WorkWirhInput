#include "../structures/Structures.h"
#include <string.h>


typedef struct{ // struct LineObjects
    Functions function;
    Types type;
} LineObjects;

/*
Инициализаторы псевдо классов
INIT for pseudo-classes
*/

#define LO_INIT {NOFUNCTION, NOTYPE}

/*
Функции для псевдо-класса
functions for pseudo-class
*/

LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    for (int i = 0; i < strlen(line);i++){

    }
    return output;
}

