#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "objects/structures/Queue.h"

int main(void){
    QueueInt first = QUEUEINT_INIT;
    
    first.print(&first);
    first.add(&first, 12);
    first.print(&first);

    for (int i = 0; i < 10; i++){
        first.add(&first, i);
        first.print(&first);
    }

}