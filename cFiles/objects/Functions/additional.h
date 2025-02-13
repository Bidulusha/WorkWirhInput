unsigned int fileSize(char * filename){
    #include <stdio.h>

    char buffer[256];
    int count = 0;

    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            count++;
        }
    } 
    else{
        puts("I can't find vl file, srr");
    }
    fclose(fp);

    return count;
}