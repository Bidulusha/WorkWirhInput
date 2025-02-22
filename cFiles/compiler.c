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

#include "objects/Functions/additional.h"
#include "objects/structures/Queue.h"
#include "vlobj.h"


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

    QueuePairss tempp = QUEUEPSS_INIT;
    printQueuePairss(&tempp);

    return 0;
}