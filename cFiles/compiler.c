#include <stdio.h>
#include "vlobj.h"
#include "objects/structures/Queue.h"

int main(void){
    VlFile vlfile = VLFILE_INIT;
    
    vlfile.filename = "newFile.vl";
    vlfile.updateVlFile(vlfile.filename);

    return 0;
}