/*****************************************
 * list.c
 * Stores nodes on a linked list
 *
 * @author Kristopher Trevino
 * November 8, 2016
 *
 * **************************************/
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

//initialized first node in linked list
void createList(char* target, int line, node_t* head){
    if(head->next == NULL){
        strcpy(head->identifier, target);
        head->lineNum = malloc(sizeof(myqueue));
        head->lineNum->sizeCount = 0;
        addLineNum(line, head->lineNum);
    }
}

//iterate over list to find duplicate nodes
//if duplicate node, add line number to that node
//if node is not found, add new node
void findNode(char* target, int line, node_t* head, node_t* tail){
    node_t * current = NULL;
    current = malloc(sizeof(node_t));
    current = head;

    //iterate through loop
    while(current->next != NULL){
        //if found break out of loop to add line number to queue
        if(isSame(current->identifier, target)){
            break;
        }  
        current = current->next;
    }

    if(isSame(current->identifier, target)){ //add line number to queue if duplicate  
        addLineNum(line, current->lineNum);
    }else{ //add new node
        node_t * newNode = NULL;
        newNode =  malloc(sizeof(node_t));
        newNode->lineNum = malloc(sizeof(myqueue));
        current->next = newNode;
        strcpy(newNode->identifier, target); //copy identifier to node data
        addLineNum(line, newNode->lineNum);  //add line number to queue
        tail = newNode;
    }    
}


//Determines if identifer is the same as the one in node
int isSame(char* target, char* current){
    if(strcmp(target, current) == 0)
        return 1;
    return 0;
}

