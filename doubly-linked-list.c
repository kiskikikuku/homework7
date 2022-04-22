#include<stdio.h>
#include<stdlib.h>

<<<<<<< HEAD
=======
typedef struct Node{
    int key;
    struct Node* llink;
    struct Node* rlink;
}listNode;

>>>>>>> 222239c5a3fb0069481b021be53ed72b18832068
typedef struct Head{
    struct Node* first;
}headNode;

int initialize(headNode** h);

<<<<<<< HEAD
int freeList(headNode* h);
=======
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
    printf("----------------[2018068040]--------[Park Taehyun]--------------\n");

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

    return 1;
}

int initialize(headNode** h){
    if((*h) != NULL) // 공백 리스트가 아닌 경우(헤드가 존재)
        freeList(h); // 기존 리스트 할당 해제

        headNode* temp = (headNode*)malloc(sizeof(headNode)); // 헤드 포인터와 가리키는 헤드 생성
        h = &temp; // h가 생성한 헤드포인터를 가리킴
        temp->first = NULL; // 생성된 헤드의 first는 NULL
    

    /*
     singly에서 사용한 initialize 함수는 반환형이 headNode* 였다.
     때문에 반환값을 그대로 메인의 h에 넣어주면 됐다.
     doubly에서는 반환형이 int형이지만 h의 값의 변경이 필요하다
     따라서 h의 포인터인 headnode*의 포인터 headnode**형이 
     매개변수로 들어와야 h값을 변경시킬 수 있다.
    */
    return 1;
}

int freeList(headNode** h){
    
    return 0;
}


int insertNode(headNode* h, int key){

    return 0;
}

int insertLast(headNode* h, int key){

    return 0;
}

int insertFirst(headNode* h, int key){

    return 0;
}

int deleteNode(headNode* h, int key){

    return 1;
}

int deleteLast(headNode* h){

    return 0;
}

int deleteFirst(headNode* h){

    return 0;
}

int invertList(headNode* h){

    return 0;
}

void printList(headNode* h){
    int i = 0;
    listNode* p;

    printf("\n---PRINT\n");
    
    if(h == NULL){
        printf("Nothing to print...\n");
        return;
    }

    p = h->first;

    while(p!=NULL){
        printf("[ [%d]=%d ]", i, p->key);
        p = p->rlink;
        i++;
    }

    printf("  items = %d\n", i);
}
>>>>>>> 222239c5a3fb0069481b021be53ed72b18832068
