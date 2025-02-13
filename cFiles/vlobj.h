#include "objects/Functions/VlFile.h" 
#include "objects/Functions/additional.h" 
#include <stdlib.h>
/*
Псевдо классы
Pseudo classes
*/

typedef struct{
    char * filename;
    LineObjects * lines;
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

#define VlFIle_INIT {"newFile.vl", new LineObjects * lines, updateVlFile}

