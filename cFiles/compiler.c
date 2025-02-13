#include <stdio.h>
#include "vlobj.h"

//Понадобится для создания сs файла
// if(fp){
    //     //записываем строку
    //     fputs(message, fp);
    //     fclose(fp);
    //     printf("File has been written\n");
// }

int main(void){
    editVlFile("newFile.vl");
    
    return 0;
}