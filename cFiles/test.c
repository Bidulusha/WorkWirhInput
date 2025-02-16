#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "c-hashmap-main/map.c"

unsigned long long step(int a, int b){
    long long sum = 1;
    for (int i = 0; i < b; i++){
        sum *= a;
    }
    return sum;
}

int main(void){
    printf("%d", (step(62, 12) * sizeof("z")) / 1024);
    return 0;
}