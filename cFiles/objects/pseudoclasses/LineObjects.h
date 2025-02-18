#pragma once

#include "../structures/Queue.h"
#include "../enums/Functions.h"
#include "../enums/Types.h"
#include "../Functions/additional.h"

/*
    Сделать файлы конфигурации для записи includes
*/
#include <string.h>

#define BUFFER_OF_LINE 256
#define BUFFER_SIZE(type) BUFFER_OF_LINE * sizeof(type)

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

int find(const char* str, const char* splits) {
    for(int i = 0; i < strlen(str); i++){
        for (int j = 0; j < strlen(splits); j++){
            if (str[i] == splits[j]) {
                return i;
            }
        }
    }
    return -1;
}

int deleteFirstTabulation(char * str){
    int temp;
    for(int i = 0; i < strlen(str) && str[i] == ' '; i++){temp++;}
    if (temp != 0){
        str[0] = '\0';
        strcat(str, &str[temp]);
    }
    return temp / 4;   
}

QueueString split(char* line){
    const char splits[] = {',', ' ','(', ')', '{', '}', '[', ']', '#', '\'', '\"', '\n', '$', '\0'};
    QueueString listofstrings = QUEUESTRING_INIT;

    int ind;
    int tabcount = deleteFirstTabulation(line);
    puts("12");

    char * temp = (char*)malloc(BUFFER_SIZE(char*));
    temp[0] = '\0';

    for (int i = 0; i < strlen(line); i++){
        if ((ind = find(gos(line[i]), splits)) != -1){
            if (temp[0] != '\0'){
                addToQueueString(&listofstrings, temp);
                temp[0] = '\0';
            }

            if (line[i] == '$') {
                if (i + 1 < strlen(line) && line[i + 1] != '*') {
                    break;  // Не начало "$*", значит просто выходим
                } else {
                    i += 2;  // Пропускаем "$*"
                    while (i < strlen(line) && !(line[i] == '$' && i - 1 >= 0 && line[i - 1] == '*')) {
                        i++;
                    }
                    i++;
                }
            }

            if (line[i] == '\'' || line[i] == '\"'){
                addToQueueString(&listofstrings, gos(line[i]));
                char openchar = line[i];
                i++;
                while(line[i] != openchar){
                    strcat(temp, gos(line[i]));
                    i++;
                }

                addToQueueString(&listofstrings, temp);
                temp[0] = '\0';
            }

            if(line[i] != '\n' && line[i] != ' '){
                addToQueueString(&listofstrings, gos(line[i]));
            }
        }
        else{
            strcat(temp, gos(line[i]));
        }
    }

    if (temp[0] != '\0'){
        addToQueueString(&listofstrings, temp);
    }

    free(temp);

    return listofstrings;
}


LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    QueueString splitobjects = QUEUESTRING_INIT;
    splitobjects = split(line);

    printQueueString(&splitobjects);

    return output;
}