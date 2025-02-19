#include <stdio.h>
#include <stdlib.h>
//Legacy or List
typedef struct StringL
{
    char element;
    struct StringL * next;
    struct StringL * prev;
} StringL;
#define nullString {NULL,NULL,NULL}

StringL *strLchar(char c){
    StringL* st = (StringL*)malloc(sizeof(StringL));
    st->element = c;
    st->next = NULL;
    st->prev = NULL;
    return st;
}

void printstrl(StringL *str){
    if (str->element == NULL){
        printf("");
    }
    else while(str->next != NULL){
        printf("%c",str->element);
        str = str->next;
    }
    if (str->element == NULL){
        printf("%c",str->element);
    }
    printf("\n");
}

void addStringLegacy(StringL *str,char c){
    if (str->element == NULL){
        str->element = c;
    }
    else{
        StringL *new_c = strchar(c);
        new_c ->prev = str;
        str->next = new_c;
    }
}

StringL *AddCharInStringL(StringL *str, char * c){
    StringL* st = (StringL*)malloc(sizeof(str) + sizeof(c));
    st = str;
    while (!st->next){
        st = st->next;
    }
    for(int i = 0; i < sizeof(c); i += 1){
        st->next = strLchar(c[i]);
        st->next->prev = st;
        st = st->next;
    }
    return st;
}


