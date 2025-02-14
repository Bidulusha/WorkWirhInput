#include "../structures/Queue.h"
#include "../enums/Functions.h"
#include "../enums/Types.h"
/*
    Сделать файлы конфигурации для записи includes
*/
#include <string.h>

#define BUFFER_OF_LINE 256

#define MERROR puts("Memory allocation failed"); exit(1);
#define MWARNING puts("It's not exist");

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

char * gos(char str){ //getOneSymbol
    char * new_str = (char*)malloc(1 *sizeof(char));
    new_str[0] = str;
    new_str[1] = '\0';
    return new_str;
}

int findChar(char what, const char where[]) {
    int i = 0;
    while (i < strlen(where)) {
        if (where[i] == what) {
            //printf("where: %c\nwhat: %c\n ", where[i], what);
            return 1;} // Найден
        i++;
    }
    return 0; // Не найден
}


// int findChar(char what, const char *where) {
//     char temp[2] = {what, '\0'};
//     int ind = strstr(where, temp);
//     if (ind != NULL) {
//         return 0; // символ найден
//     }
//     return -1; // символ не найден
// }

QueueString split(char* line){
    const char splits[] = {' ','(', ')', '{', '}', '[', ']', '#', '\'', '\"', '\n', '$', '\0'};
    QueueString listofstrings = QUEUEINT_STRING;

    bool openone = false;

    char *temp = (char *)malloc(BUFFER_OF_LINE);
    if (temp == NULL){ MERROR; }
    temp[0] = '\0';


    for (int i = 0; i < strlen(line); i++){
        if (!findChar(line[i], splits)){
            strncat(temp, &line[i], 1);
        }
        else{
            if (line[i] == '\'' || line[i] == '\"' || line[i] == '$'){
                if (!openone) openone = true;
                else openone = false;
                addToQueueString(&listofstrings, gos(line[i]));
            }

            if(!openone){
                if (temp != NULL && temp[0] != '\0'){
                    addToQueueString(&listofstrings, temp);
                }

                temp[0] = '\0';
                if (line[i] != '\n') addToQueueString(&listofstrings, gos(line[i]));
            }
            else{
                strncat(temp, &line[i], 1);
            }
        }
    }

    if (temp[0] != '\0') addToQueueString(&listofstrings, temp);

    free(temp);
    return listofstrings;
}


LineObjects checkLines (char * line){
    LineObjects output = LO_INIT;
    QueueString splitobjects = QUEUEINT_STRING;
    splitobjects = split(line);
    printQueueString(&splitobjects);
    return output;
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