#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "input.c"

/* Returns a fresly allocated new string containing <len> chars from <inStr> */
char* copy_str(char* inStr, short len){
    char* copy = (char*)malloc(len+1 * sizeof(char));
    int i = 0;
    for(i; i<len-1; i++) {
        //printf("[%d]: %c", i, inStr[i], "\n");
        copy[i] = inStr[i];
        //printf("[%d]: %c", i, copy[i], "\n");
    }
    return copy;
}

int main()
{
    int loop = 1;
    
    while (loop == 1) {
        char* test = input();
        int len = string_length(test);
        printf("Copy: %s\n ", copy_str(test, len));
    }
}
