#pragma once

#define clearstd fflush(stdout)

unsigned int fileSize(char * filename){
    #include <stdio.h>

    char buffer[256];
    int count = 0;

    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            count++;
        }
    } 
    else{
        puts("I can't find vl file, srr");
    }
    fclose(fp);

    return count;
}


void print(const char *text, const char * end) {
    write(1, text, strlen(text));
    write(1, end, strlen(end));  
}

void println(const char *text) {
    print(text, "\n");  
}