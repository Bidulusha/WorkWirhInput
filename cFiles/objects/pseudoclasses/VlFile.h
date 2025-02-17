#pragma once

#include "LineObjects.h" 
#include "../Functions/additional.h" 

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * filename; // char * filename;
    LineObjects * lines; // structe LineObjects * lines;
    void (*updateVlFile)(char * filename);
}VlFile;

/*
Инициализаторы псевдо-классов
INIT for pseudo-classes
*/

#define VLFILE_INIT {"newFile.vl", malloc(sizeof(LineObjects)) , updateVlFile}

/*
Функции для псевдо-класса
functions for pseudo-class
*/

void updateVlFile(char * filename){
    #ifdef _WIN32
    SetConsoleCP(65001);    // Ввод
    SetConsoleOutputCP(65001);  // Вывод
    #endif

    LineObjects * lines = (LineObjects*)malloc(fileSize(filename) * sizeof(LineObjects));

    char buffer[BUFFER_OF_LINE];

    //Read file
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        int i = 0;
        while((fgets(buffer, BUFFER_OF_LINE, fp))!=NULL)
        {
            checkLines(buffer);
            i++;
        }
    } 
    else{
        puts("I can't find vl file, srr");
    }
    fclose(fp);

    free(lines);
}

