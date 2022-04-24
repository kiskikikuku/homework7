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
int freeList(headNode* h); 
listNode* createNode(int key); // 삽입할 노드 생성하는 함수
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);
void printList(headNode* h); //선언

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
        case'q': case'Q':
            freeList(headnode);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }
    }while(command !='q' && command !='Q');

    return 1;
}

int initialize(headNode** h){
    if((*h) != NULL){ // 공백 리스트가 아닌 경우(헤드가 존재)
        freeList(*h);
    } // 기존 리스트 할당 해제

        *h = (headNode*)malloc(sizeof(headNode)); // 헤드 포인터와 가리키는 헤드 생성
        (*h)->first = NULL; // 생성된 헤드의 first는 NULL
    

    /*
     singly에서 사용한 initialize 함수는 반환형이 headNode* 였다.
     때문에 반환값을 그대로 메인의 h에 넣어주면 됐다.
     doubly에서는 반환형이 int형이지만 h의 값의 변경이 필요하다
     따라서 h의 포인터인 headnode*의 포인터 headnode**형이 
     매개변수로 들어와야 h값을 변경시킬 수 있다.
    */
    return 1;
}

int freeList(headNode* h){
    listNode* node = h->first; //첫 노드부터 끝노드까지 가는 노드포인터
    listNode* prev = NULL; //node뒤를 따라가며 할당해제시키는 노드포인터

    while(node != NULL){
        prev = node;
        node = node->rlink;
        free(prev);
    }
    free(h); // 헤드노드까지 할당해제
    
    return 0;
}


listNode* createNode(int key){
    listNode* n = (listNode*)malloc(sizeof(listNode)); // 노드 할당
    n->key = key; 
    n->llink = n->rlink = NULL; // 노드 값 초기화

    return n;
} //삽입할 노드 만들어주는 함수(insert함수들에서 중복이 많아 선언했습니다.)


int insertNode(headNode* h, int key){
    listNode* p = h->first; //삽입 위치 찾을 노드 포인터
    listNode* node = createNode(key); // 노드 생성

    if(h->first == NULL) // 공백 리스트에 삽입되는 경우
    {
        h->first = node;
        return 1;
    }

    while(p!=NULL){
        if(p->key>=key){ // 삽입 위치 찾음(key값 오름차순)
            if(p == h->first) // 맨 앞에 삽입되는 경우
                insertFirst(h, key); 
            else{ // 중간에 삽입되는 경우
                node->rlink = p; 
                node->llink = p->llink; 
                p->llink->rlink = node;
                p->llink = node;
            }
            return 0;
        }
            
        p = p->rlink; // 다음 노드 탐색
    }

    insertLast(h, key); // 맨뒤에 삽입
    return 0;
} //key값 오름차순 정렬로 노드를 삽입

int insertLast(headNode* h, int key){
    listNode* node = createNode(key);
    listNode* p = h->first; //마지막 위치를 포인팅 해줄 노드포인터

    if(h->first == NULL) {//공백 리스트의 경우
        h->first = node;
        return 1;
    }
    
    while(p->rlink!=NULL){ //마지막 노드로 이동
        p = p->rlink;
    }
    
    node->llink = p; // 그 뒤에 삽입
    p->rlink = node;
    return 0;
} //마지막 위치에 노드 삽입

int insertFirst(headNode* h, int key){
    listNode* node = createNode(key);

    if(h->first == NULL){//공백 리스트의 경우
       h->first = node;
       return 1;
    }

    node->rlink = h->first; 
    h->first->llink = node;
    h->first = node; //첫 위치에 노드 삽입, 기존 first의 포인터 바꿔줌
    
    return 0;
} // 시작 위치에 노드 삽입

int deleteNode(headNode* h, int key){
    listNode* p = h->first;

    if(h->first == NULL){ //공백 리스트의 경우
        printf("Empty List.");
        return 1;
    }

    while(p != NULL){
        if (p->key == key) // 지우려는 key값을 가진 노드 발견
        {   
            if(p == h->first){ // 첫 노드인 경우
                h->first = p->rlink;
                if(p->rlink != NULL) // 2개 이상의 노드가 있는 경우
                    p->rlink->llink = NULL; // 지우는 노드의 뒤 노드는 first가 됨-> llink가 NULL
                free(p);
                return 1;
            }

            else{
                p->llink->rlink = p->rlink;
                if(p->rlink != NULL) // 마지막 노드가 아닌 경우
                    p->rlink->llink = p->llink; // 지우는 노드의 다음 노드의 llink가 지워지는 노드의 이전 노드를 가리키게 한다.
                free(p);
                return 1;
            }
        }
        p = p->rlink; // 다음 노드로 이동
    }

    printf("Non-existing value %d", key); // 지우고자하는 key값을 가진 노드가 없는 경우
    return 1;
}

int deleteLast(headNode* h){
    if(h->first == NULL){ //공백 리스트의 경우
        printf("Empty List.");
        return 0;
    }

    listNode* p = h->first;

    while(p->rlink!=NULL){
        p = p->rlink;           
    } //마지막 노드까지 이동

    if (p == h->first) //노드 1개인 리스트의 경우
    {   
        h->first = NULL;
        free(p);
    }
    else{ // 노드 1개 이상인 리스트
        p->llink->rlink = NULL;
        free(p);
    }

    return 0;
}

int deleteFirst(headNode* h){
    if(h->first == NULL){
        printf("Empty List.");
        return 0;
    } // 공백 리스트의 경우

    listNode* p = h->first;

    if (p->rlink == NULL) //노드 1개인 리스트
    {
        h->first = NULL;
        free(p);    
    } 
    else{ // 노드 1개 이상인 리스트
        h->first = p->rlink;
        p->rlink->llink = NULL;
        free(p);
    }
    return 0;
}

int invertList(headNode* h){
    listNode* current = h->first; // 링크를 바꿔줄 노드의 위치하는 노드포인터
    listNode* post = h->first->rlink; // current한칸 앞 위치 노드를 가리키는 노드포인터
    listNode* trail = NULL;  // current 한칸 이전 노드를 가리키는 노드포인터

    while(current->rlink != NULL){ //마지막 위치까지 이동하며
        current->rlink = trail;
        current->llink = post; // current노드의 l,r 링크를 바꿔줌(trail, post 이용)
        trail = current; 
        current = post; 
        post = post->rlink; // 바꾸고 난 뒤 trail, current, post는 각각의 다음 노드로 이동
    }
    current->rlink = trail; // 마지막 노드의 rlink 변경
    h->first = current; // 기존의 last 노드가 새로운 first 노드가 됨

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
