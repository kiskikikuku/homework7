#include<stdio.h>
#include<stdlib.h>

typedef struct Head{
    struct Node* first;
}headNode;

int initialize(headNode** h);

int freeList(headNode* h);
