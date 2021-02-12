#include <stdio.h>
#include <stdlib.h>

char* input()

{
    char* input = (char*)malloc(100 * sizeof(char*));
    printf("Enter a string =>> ");
    fgets(input,100,stdin);
    printf("String: %s", input);
    return input;
                        
}


