#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "input.c"

/* Return true (non-zero) if the char is a whaitespace ('\t' or ' ') */
int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if the char is not a whitespace */
int non_space_char(char c){
  if(c == ' ' || c == '\t'){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next space-separated word in zero-terminated st*/
char* word_start(char* str){
  if (count_words(str) > 0){
    int i = 0;
    
    while (space_char(str[i])) {
        i++;
    }
    return (str + i);
  }
  return str;
}

/* Returns a pointer to the first space character in zero-terminated str. */
char* word_end(char* str){
    int i = 0;
    while(non_space_char(str[i])) {
      //while((str[i]) != ' '){
        i++;
    }
    return (str + i);
}

/* Counts the number of words in the string argument. */
int count_words(char* str){
    int i = 0;
    int count = 0;

    while(str[i] != '\0'){
        if(str[i] == ' ' && str[i+1] != ' '){
            count++;
        }
        i++;
    }
    count += 1;
    return count;
}


/* Copy_str helper method to know the length of the string <len> */
int string_length(char* str){
  int index = 0;
  long count = 0;
  while(str[index++]){
    count++;
  }
  return count;
}

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

/* main Method */
int main(){
  //int loop = 1;
  //while (loop == 1) {
    char* test = input();
    
    //test word_start
    printf("\nTest word_start\n");
    char* word1 = test;
    printf("String:%s \n", word_start(word1));
        
    //test word_end
    printf("\nTest word_end\n");
    char* word2 = test;
    printf("String:%s \n", word_end(word2));
        
    //test count_words
    printf("\nTest count_words\n");
    char* word3 = test;
    printf("Word count: %d\n", count_words(word3));
    
    //test copy_str
    printf("\nTesting copy_str\n");
    char* word4 = test;
    int len = string_length(word4);
    printf("Copy: %s\n ", copy_str(word4, len));
  //}
}
