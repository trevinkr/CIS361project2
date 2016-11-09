/*************************************************
 * queue.c
 *
 * @author Kristopher Trevino
 * November 8, 2016
 *
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//allocates memory to a newly instantiated queue
void allocate(myqueue * q){
        q = malloc(sizeof(myqueue));
}

//add lineNum of identifer to queue
void addLineNum(int l, myqueue * q){
    q->lineNum[q->sizeCount] = l;
    q->sizeCount++;
}
