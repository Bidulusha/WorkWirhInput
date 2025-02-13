#include <stdio.h>
#include "vlobj.h"
#include "objects/structures/Queue.h"

int main(void){
    // VlFile vlfile = VLFILE_INIT;
    
    // vlfile.filename = "newFile.vl";
    // vlfile.updateVlFile(vlfile.filename);

    QueueInt q = QUEUEINT_INIT;

    int inp = -1;
    while (inp != 0)
    {
        scanf("%d", &inp);
        
        addToQueueInt(&q, inp);
        printQueueInt(&q);
    }
    

    return 0;
}