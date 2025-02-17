#include <stdio.h>
#include <locale.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <io.h>

#define write _write
#else
#include <unistd.h>

#endif

#include "objects/Functions/additional.h"
#include "vlobj.h"

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")


int main(void){
    #ifdef _WIN32
    SetConsoleCP(65001);    // Ввод
    SetConsoleOutputCP(65001);  // Вывод
    #endif

    // Устанавливаем локаль для поддержки русских символов
    setlocale(LC_ALL, "ru_RU.UTF-8");

    /*
    Чтение .vl файлов
    */
    VlFile vlfile = VLFILE_INIT;
    
    vlfile.filename = "core.vl";
    vlfile.updateVlFile(vlfile.filename);

    vlfile.filename = "newFile.vl";
    vlfile.updateVlFile(vlfile.filename);
    
    /*
    
    */
    //hashmap* memoryFunctrion = hashmap_create();
    QueuePairts functions_memory = QUEUEPTS_INIT;

    printQueuePairts(&functions_memory);
    
    Pairts temp = {TYPE_INT, "12"};
    
    addToQueuePairts(&functions_memory, temp);
    printQueuePairts(&functions_memory);


    temp = getPairts(&functions_memory);
    printQueuePairts(&functions_memory);

    printf("(%s, %s)\n", get_name(temp.first), temp.second);
    clearstd;

    return 0;
}