#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
}node_t;

int main(){
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
/*   
   if(head == NULL)
       printf("Head is NULL\n");
*/ 
   if (head == NULL){
	//issue with mallocing
        return 1;
    }

    head->val = 2; 
    printf("Val: %d\n", head->val);
   if(head->next == NULL)
        printf("Next node is NULL");


return 0;
}
