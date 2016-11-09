//#include "/home/trevinkr/cis361/Project2/list.h"
/*****************************************
 * Stores nodes on a linked list
 * **************************************/
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char identifier[15];
    int lineNum; //queue lineNum;
    struct node * next;
}node_t;

node_t * head;
node_t * tail;
//char[15] target;

//create linked list
void createList(char  *target, int line){
    printf("At createList");
    //strcpy(target, t);
    head = NULL;
    head =(node_t *) malloc(sizeof(node_t));
    if(head == NULL){
        strcpy(head->identifier, target);
        head->lineNum = line;
        head->next = NULL;
        tail = head;
    }
}

//iterate over list to find node
void findNode(char* target, int line){
    node_t * current;
    current = head;
    while(!isSame(current->identifier, target) && current != NULL){
        //add new node
        if(!isSame(current->identifier, target)){
            printf("adding new node: %s\n", target);
            node_t *nextNode = tail->next;
            nextNode =  malloc(sizeof(node_t));
            strcpy(nextNode->identifier,target);
            nextNode->lineNum = line;
            nextNode->next = NULL;
            tail = nextNode;
        }
        else
            printf("Node: %s already exitst\n", target);
    
        current = current->next;
    }
   
}

//if it is return true, else false,
int isSame(char* target, char* current){
    if(strcmp(target, current))
        return 1;

    return 0;
}
//int main(){
//    return 0;
//}

