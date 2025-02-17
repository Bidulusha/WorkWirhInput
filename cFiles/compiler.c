#include <stdio.h>
#include <locale.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif

#include "vlobj.h"
#include "c-hashmap-main/map.c"

#define typeof(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char*: "char*", \
    default: "unknown")


int main(void){
    SetConsoleCP(65001);    // Ввод
    SetConsoleOutputCP(65001);  // Вывод

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
    
    return 0;
}