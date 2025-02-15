#include <stdio.h>
#include "vlobj.h"

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")

int main(void){
    VlFile vlfile = VLFILE_INIT;
    
    vlfile.filename = "newFile.vl";
    vlfile.updateVlFile(vlfile.filename);


    return 0;
}