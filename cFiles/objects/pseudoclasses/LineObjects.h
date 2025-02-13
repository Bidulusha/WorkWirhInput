#include "../structures/Structures.h"
#include <string.h>


typedef struct{ // struct LineObjects
    Functions function;
    Types type;
} LineObjects;

#define LO_INIT {NOFUNCTION, NOTYPE}

LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    for (int i = 0; i < strlen(line);i++){
        
    }
    return output;
}

