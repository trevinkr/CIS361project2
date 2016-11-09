#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list.c"

int main(int argc, char *argv[]){
    if(argc != 2){
        perror("Need more arguments");
        exit(1);
    }
    
    char line[60];
    FILE *fin;
    fin = fopen(argv[1], "r");
    
    int count = 0;
    char *token;
    while(fgets(line, 60, fin) != NULL){
        count++;
        token = strtok(line, " ");
        createList(token, count);
        while (token != NULL){
            printf("Token: %s\n", token);
            token = strtok(NULL, " ");
        }
     
    }
    fclose(fin);
    return 0;
}
