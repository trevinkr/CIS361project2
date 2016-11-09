/****************************************
 * queue.h
 *
 * @author Kristopher Trevino
 * November 8, 2016
 *
 **************************************/
#ifndef QUEUE_H
#define QUEUE_H
typedef struct queue{
    int lineNum[30];
    int sizeCount;
} myqueue;
void allocate(myqueue *);
void addLineNum(int, myqueue *);
#endif
