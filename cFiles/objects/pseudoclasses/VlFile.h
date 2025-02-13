#include "LineObject.h" 
#include "../Functions/additional.h" 
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * filename; // char * filename;
    LineObjects * lines; // structe LineObjects * lines;
    void (*updateVlFile)(char * filename);
}VlFile;

void updateVlFile(char * filename){

    LineObjects * lines = (LineObjects*)malloc(fileSize(filename) * sizeof(LineObjects));

    char buffer[256];

    //Read file
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        int i = 0;
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s\n", buffer);
            lines[i] = checkLines(buffer);
            i++;
        }
    } 
    else{
        puts("I can't find vl file, srr");
    }
    fclose(fp);

    free(fp);
    
    return lines;
}

/*
Инициализаторы псевдо классов
INIT for pseudo-classes
*/

#define VLFILE_INIT {"newFile.vl", malloc(sizeof(LineObjects)) , updateVlFile}