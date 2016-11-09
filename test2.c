#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include <ctype.h>
//myProgram
int allowed(char *);
int isIdentifier(char *);
int main(int argc, char *argv[]){
    if(argc != 2){
        perror("Need more arguments");
        exit(1);
    }
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    node_t * tail = NULL;
    head = malloc(sizeof(node_t));
    tail = head;
    char line[60];
    FILE *fin;
    fin = fopen(argv[1], "r");
    int count = 0;
    char *token;
    int create = 0; //creates list only once
    while(fgets(line, 60, fin) != NULL){
        count++;
        token = strtok(line, " \n");
        if(token != NULL){ //cheks for comments or quotes
            if(token[0] == '/' && token[1] == '/')
                token = NULL;
            else if(token[0] == '"'){
                token = strtok(NULL, " \n");
                while(token[strlen(token)-1] != '"')
                    token = strtok(NULL, " \n");
                 token = strtok(NULL, " \n");
            }
        }
        if(create == 0 && isIdentifier(token)){
            createList(token, count, head);
           // printf("create: %d", create);
            create = 1;
        }
        printf("Check identifier: %d, %s\n", isIdentifier(token), token);
        //printf("After createList   head: %s tail: %s\n", head->identifier, tail->identifier);
        if(create == 1 && isIdentifier(token)){
            findNode(token, count, head, tail);
            //printf("create: %d\n", create);
        }
//        create = 1;
        while (token != NULL){
            token = strtok(NULL, " \n");
            printf("Token1: %s\n", token);
            if(token != NULL){
                if(token[0] == '/' && token[1] == '/'){
                    token = NULL;
                }else if(token[0] == '"'){
                    printf("HERE I AM token: %s\n", token);
                    token = strtok(NULL, " \n");
                    printf("Before While loop: %s, %d\n", token,(int) strlen(token));
                    while(token[strlen(token)-2] != '"'){
                        token = strtok(NULL, " \n");
                        printf("Inside while loop: %s, %d\n", token, (int) strlen(token));
                    }
                     token = strtok(NULL, " \n");
                 }
            }
            if(token != NULL){
               printf("Check identifier: %d, %s\n", isIdentifier(token), token);
               if(create == 0 && isIdentifier(token)){
                   createList(token, count, head);
                   printf("List is created at: %s\n", token);
                   create = 1;
               }
               else if(create == 1 && isIdentifier(token))
                   findNode(token, count, head, tail);
               //printf("Token: %s\n", token);
            }
        }
    }
    fclose(fin);
    //loop through
node_t * temp;
    temp = malloc(sizeof(node_t));
    //prints all
    temp = head;
    printf("     Identifier     Line Number\n");
    printf("     ----------     -----------\n");
    while(temp->next != NULL){
        printf("%15s %5d", temp->identifier, temp->lineNum->lineNum[0]);
        int i=1;
        while(temp->lineNum->lineNum[i] != 0){
            printf(" %d", temp->lineNum->lineNum[i]);
            i++;
        }
        printf("\n");
        temp = temp->next;
    }
    //prints out last node
    printf("%15s %5d", temp->identifier, temp->lineNum->lineNum[0]);
    int i=1;
    while(temp->lineNum->lineNum[i] != 0){
        printf(" %d", temp->lineNum->lineNum[i]);
        i++;
    }
    printf("\n");
    return 0;
}
//checks if contains underscore and rest is alphanum
int allowed(char * token){
    int i;
    //int found = 0;
    for(i=0; i<strlen(token); i++){
        if(!isalnum(token[i]))
            if(token[i] != '_')
                return 0;
    }
    return 1;
}

int isIdentifier(char * token){
   if(allowed(token)){
    //if starts with a digit return 0
        if(isdigit(token[0]))
            return 0;
       return 1;
   }
    //if starts with '//' then return zero and everything else on that line is zero
    return 0;
}

