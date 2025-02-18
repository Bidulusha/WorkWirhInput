#pragma once
#include <string.h>

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")

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

void _print(const char *text, const char * end) {
    write(1, text, strlen(text));
    write(1, end, strlen(end));  
}

void _println(const char *text) {
    print(text, "\n");  
}

//#define print(text) _print(text, "\n")