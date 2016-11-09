/****************************************
 * structure.h
 * structure for a node
 *
 * @author Kristopher Trevino
 * November 8, 2016
 ***************************************/
#include <stdlib.h>
#include "queue.h"
#ifndef STRUCTURE_H
#define STRUCTURE_H
typedef struct node {
    char identifier[15];
    myqueue * lineNum;
    struct node * next;
} node_t;
#endif
