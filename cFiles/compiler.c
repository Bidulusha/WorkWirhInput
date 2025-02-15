#include <stdio.h>
#include "vlobj.h"

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")

int main(void){
    // VlFile vlfile = VLFILE_INIT;
    
    // vlfile.filename = "newFile.vl";
    // vlfile.updateVlFile(vlfile.filename);

    int a = 12;
    char a1[] = "huij";

    printf("%s", typeof(a1));

    return 0;
}