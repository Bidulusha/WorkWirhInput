#include "../structures/Queue.h"
#include "../enums/Functions.h"
#include "../enums/Types.h"
/*
    Сделать файлы конфигурации для записи includes
*/
#include <string.h>

#define BUFFER_OF_LINE 256




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

char * gos(char str){ //getOneSymbol
    char * new_str = (char*)malloc(2 * sizeof(char));
    new_str[0] = str;
    new_str[1] = '\0';
    return new_str;
}

int findFirstOccurrence(const char* str, const char* splits) {
    const char* p = str;
    while (*p) { // Проходим по строке до конца
        const char* s = splits;
        while (*s) { // Проходим по массиву символов разделителей
            if (*p == *s) {
                return p - str; // Возвращаем индекс первого вхождения
            }
            s++;
        }
        p++;
    }
    return -1; // Возвращаем -1, если не найдено
}

int deleteFirstTabulation(char * str){
    int count = 0;
    char * s = str;
    while((strstr(s,"\t"))){
        count++;
    }
    
}

QueueString split(char* line){
    const char splits[] = {' ','(', ')', '{', '}', '[', ']', '#', '\'', '\"', '\n', '$', '\0'};
    QueueString listofstrings = QUEUESTRING_INIT;
    printf("%s\n", line);
    deleteFirstTabulation(line);
    printf("%s\n", line);

    return listofstrings;
}


LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    QueueString splitobjects = QUEUESTRING_INIT;
    splitobjects = split(line);
    printQueueString(&splitobjects);
    return output;
}