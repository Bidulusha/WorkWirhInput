#include "../structures/Queue.h"
#include "../enums/Functions.h"
#include "../enums/Types.h"
/*
    Сделать файлы конфигурации для записи includes
*/
#include <string.h>

#define BUFFER_OF_LINE 256
#define MERROR puts("Memory allocation failed"); exit(1);

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

/*
Разделители
$ - comment
()
{}
\n
# - command
[]
*/

int findChar(char what, char *where) {
    char temp[2] = {what, '\0'};
    int ind = strstr(where, temp);
    if (ind != NULL) {
        return 0; // символ найден
    }
    return -1; // символ не найден
}

QueueString split(char* line){
    const char splits[] = {'(', ')', '{', '}', '[', ']', '$', '#'};
    QueueString listofstrings;

    char *temp = (char *)malloc(BUFFER_OF_LINE);

    if (temp == NULL){
        MERROR;
    }

    for (int i = 0; i < strlen(line); i++){
        if (findChar(line[i], splits) != -1){
            strncat(temp, line[i], 1);
        }
        else{
            addToQueueString(&listofstrings, temp);
            //addToQueueString(&listofstrings, line[i]);
            free(temp);
            char *temp = (char *)malloc(BUFFER_OF_LINE);
        }
    }

    free(temp);
    printQueueString(&listofstrings);
    return listofstrings;
}


// char **split(char *line) {
//     char *new_str = (char *)malloc(BUFFER_OF_LINE);
//     char *listofoperation = (char *)malloc(BUFFER_OF_LINE);

//     if (new_str == NULL || listofoperation == NULL) {
//         puts("Memory allocation failed");
//         exit(1);
//     }

//     new_str[0] = '\0'; // инициализируем как пустую строку
//     listofoperation[0] = '\0'; // инициализируем как пустую строку

//     for (int i = 0; i < strlen(line); i++) {
//         if (findChar(line[i], splits) != -1) {
//             strncat(new_str, &line[i], 1); // добавляем один символ
//         } else {
//             strncat(listofoperation, &line[i], 1); // добавляем один символ
//         }
//     }

//     char **output = malloc(2 * sizeof(char*));
//     if (output == NULL) {
//         puts("Memory allocation for output array failed");
//         exit(1);
//     }
    
//     output[0] = new_str;
//     output[1] = listofoperation;

//     return output;
// }

LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    QueueString splitobjects;
    for (int i = 0; i < strlen(line);i++){
        split(line);
    }
    return output;
}

