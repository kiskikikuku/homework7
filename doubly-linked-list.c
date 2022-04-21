#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node* llink;
    struct Node* rlink;
}listNode;

typedef struct Head{
    struct Node* first;
}headNode;

int initialize(headNode** h);

int freeList(headNode** h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main(){

    char command;
    int key;    
    headNode* headnode = NULL;

    do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command)
        {
        case 'z': case 'Z':
            initialize(&headnode); 
            break;
        case 'p': case 'P':
            printList(headnode);
            break;
        case 'i': case'I':
            printf("Your Key = ");
            scanf("%d", &key);
            insertNode(headnode, key);
            break;
        case 'd': case 'D':
            printf("Your Key = ");
            scanf("%d", &key);
            deleteNode(headnode, key);
            break;
        case 'n': case'N':
            printf("Your Key = ");
            scanf("%d", &key);
            insertLast(headnode, key);
            break;
        case'e': case'E':
            deleteLast(headnode);
            break;
        case'f': case'F':
            printf("Your Key = ");
            scanf("%d", &key);
            insertFirst(headnode, key);
            break;
        case't': case'T':
            deleteFirst(headnode);
            break;
        case'r': case'R':
            invertList(headnode);
            break;

        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }
    }while(command !='q' || command !='Q');

    return 0;
}
