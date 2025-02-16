#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "vlobj.h"

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

    VlFile vlfile = VLFILE_INIT;
    
    vlfile.filename = "core.vl";
    vlfile.updateVlFile(vlfile.filename);

    vlfile.filename = "newFile.vl";
    vlfile.updateVlFile(vlfile.filename);

    return 0;
}