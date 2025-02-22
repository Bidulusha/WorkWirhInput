#pragma once

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <io.h>

#define write _write
#else
#include <unistd.h>

#endif

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")

#define clearstd fflush(stdout)

char * gos(char str){ //getOneSymbol
    char * new_str = (char*)malloc(2 * sizeof(char));
    new_str[0] = str;
    new_str[1] = '\0';
    return new_str;
}

/*
Целочисленное в строку
Int to string
*/

char * intToString(int n){
    int temp = n, size = 1;
    while(temp){temp /= 10; size += 1;}

    char * new = (char*)malloc((size) * sizeof(char));
    new[0] = '\0';

    size -= 2;

    while(n){
        strcat(new, gos(48 + n / ((int)pow(10, size))));
        n %= ((int)pow(10,size));
        size -= 1;
    }

    return new;
}

unsigned int fileSize(char * filename){
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

void iprint(int text, const char * end){
    int i = 0, temp = text;
    while (temp){
        temp /= 10;
        i++;
    }
    write(1, intToString(text), i);
    write(1, end, strlen(end));  
}

#define println(text) print(text, "\n")
#define iprintln(text) iprint(text, "\n")