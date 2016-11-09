/*****************************************************************
 * CIS 361 Project 2
 *
 * @author Kristoher Trevino
 * November 8, 2016
 *
 * *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include <ctype.h>

int allowed(char *);
int isIdentifier(char *);
void outputData(node_t *, FILE *);

int main(int argc, char *argv[]){
    if(argc != 3){
        perror("Need more arguments");
        exit(1);
    }
    
    node_t * head = NULL;           //first node
    head = malloc(sizeof(node_t));
    node_t * tail = NULL;           //last node
    head = malloc(sizeof(node_t)); 
    tail = head;   
 
    char line[60];
    FILE *fin, *fout;
    fin = fopen(argv[1], "r");   
    fout = fopen(argv[2], "w");   
 
    int count = 0;  //determine page number
    char *token;
    int create = 0; //determine if linked list is created

    while(fgets(line, 60, fin) != NULL){//read input file
        count++; 
        token = strtok(line, " \n");

        if(token != NULL){ //checks token for comment lines or quotes for string costants
            if(token[0] == '/' && token[1] == '/')
                token = NULL;
            else if(token[0] == '"'){
                token = strtok(NULL, " \n");
                while(token[strlen(token)-2] != '"')
                    token = strtok(NULL, " \n");
                token = strtok(NULL, " \n");
            }
        } 

        if(create == 0 && token != NULL && isIdentifier(token)){ //create linked list
            createList(token, count, head);
            create = 1;
        }

        if(create == 1 && token != NULL && isIdentifier(token)){ //check if duplicate identifier
            findNode(token, count, head, tail);
        }

        while (token != NULL){ //check rest of tokens on same line
            token = strtok(NULL, " \n");
            if(token != NULL){ //check for comment lines or quotes for string constants
                if(token[0] == '/' && token[1] == '/'){
                    token = NULL;
                }else if(token[0] == '"'){
                    while(token[strlen(token)-2] != '"'){
                        token = strtok(NULL, " \n");
                    }     
                     token = strtok(NULL, " \n");
                 }
            }

            if(token != NULL){ 
               if(create == 0 && isIdentifier(token)){ //create linked list if haven't already  
                   createList(token, count, head);
                   create = 1;
               }
               else if(create == 1 && isIdentifier(token)) //check for duplicate identifier   
                   findNode(token, count, head, tail);
            }
        }
    }

    fclose(fin);
    outputData(head, fout); // output data to file

    return 0;
}

//checks if identifier is alphanum and allows to have underscores
int allowed(char * token){
    int i;
    for(i=0; i<strlen(token); i++){
        if(!isalnum(token[i]))
            if(token[i] != '_')
                return 0;
    }
    return 1;
}

//checks if valid identifer
//returns 1 if it is
int isIdentifier(char * token){
   if(allowed(token)){
        if(isdigit(token[0])) //denies identifier that start with a digit
            return 0;
       return 1; 
   }
    return 0;
}

//outputs data to given output file
void outputData(node_t * head, FILE *out){
    node_t * temp;
    temp = malloc(sizeof(node_t));
    temp = head;

    fprintf(out,"     Identifier     Line Number\n");
    fprintf(out,"     ----------     -----------\n");

    while(temp->next != NULL){ //loop through linked list display info
        fprintf(out,"%15s %5d", temp->identifier, temp->lineNum->lineNum[0]);
        int i=1;
        while(temp->lineNum->lineNum[i] != 0){
            fprintf(out," %d", temp->lineNum->lineNum[i]);
            i++;
        }
        fprintf(out,"\n");
        temp = temp->next;
    }

    //prints out last node
    fprintf(out,"%15s %5d", temp->identifier, temp->lineNum->lineNum[0]);
    int i=1;
    while(temp->lineNum->lineNum[i] != 0){
        fprintf(out," %d", temp->lineNum->lineNum[i]);
        i++;
     }
     fprintf(out,"\n");
     fclose(out);
}
