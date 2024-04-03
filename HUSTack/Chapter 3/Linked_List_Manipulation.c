#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int i;
    struct Node* previous;
    struct Node* next;
} node;
node* top=NULL;
node* makeNode(int i){
    node* newNode=(node*)calloc(1,sizeof(node));
    newNode->i=i;
    newNode->previous=NULL;
    newNode->next=NULL;
    return newNode;
}
void addNode(int i){
    if(top==NULL) top=makeNode(i);
    else {
        node* current=top;
        while(current->next!=NULL) current=current->next;    
        node* tmp=makeNode(i);
        current->next=tmp;
        tmp->previous=current;
    }
}
void printList(){
    node* current=top;
    while(current!=NULL){
        printf("%i ",current->i);
        current=current->next;
    }
}
void addLast(int k){
    node* tmp=top;
    node* ptmp=NULL;
    while(tmp!=NULL&&tmp->i!=k){
        ptmp=tmp;
        tmp=tmp->next;
    }
    if(tmp!=NULL) return;
    else {
        node* newNode=makeNode(k);
        ptmp->next=newNode;
    }
}
void addFirst(int k){
    node* tmp=top;
    while(tmp!=NULL&&tmp->i!=k){
        tmp=tmp->next;
    }
    if(tmp!=NULL) return;
    else {
        node* newNode=makeNode(k);
        newNode->next=top;
        top->previous=newNode;
        top=newNode;
    }
}
void addAfter(int u,int v){
    node* lock=top;
    while(lock!=NULL&&lock->i!=v) lock=lock->next;
    if(lock==NULL) return;
    else {
        node* tmp=top;
        while(tmp!=NULL&&tmp->i!=u){
            tmp=tmp->next;
        }
        if(tmp!=NULL) return;
        else {
            node* newNode=makeNode(u);
            lock->next->previous=newNode;
            newNode->next=lock->next;
            newNode->previous=lock;
            lock->next=newNode;
        }
    }
}
void addBefore(int u,int v){
    node* lock=top;
    while(lock!=NULL&&lock->i!=v) lock=lock->next;
    if(lock==NULL) return;
    else {
        node* tmp=top;
        while(tmp!=NULL&&tmp->i!=u){
            tmp=tmp->next;
        }
        if(tmp!=NULL) return;
        else {
            node* newNode=makeNode(u);
            lock->previous->next=newNode;
            newNode->previous=lock->previous;
            newNode->next=lock;
            lock->previous=newNode;
        }
    }
}
void Remove(int k){
    node* tmp=top;
    while(tmp!=NULL&&tmp->i!=k){
        tmp=tmp->next;
    }
    if(tmp==NULL) return;
    else {
        node* ntmp=tmp->next;
        node* ptmp=tmp->previous;
        if(ptmp!=NULL){
            ptmp->next=ntmp;
        }
        if(ntmp!=NULL){
            ntmp->previous=ptmp;
        }
        if(tmp==top){
            top=ntmp;
        }
    }
}
void Reverse() {
    node* current = top;
    node* ptmp = NULL;
    while (current != NULL) {
        node* nextNode = current->next;
        current->next = ptmp;
        current->previous = nextNode;
        ptmp = current;
        current = nextNode;
    }
    top = ptmp;
}
int main(){
    int n,i,t,u,v;
    scanf("%i",&n);
    for(i=0;i<n;i++){
        scanf("%i",&t);
        addNode(t);
    }
    char s[20];
    while (1)
    {
        fflush(stdin);
        scanf("%s",s);
        if(s[0]=='#') break;
        if(strcmp(s,"addlast")==0){
            scanf("%i",&u);
            addLast(u);
        } else if(strcmp(s,"addfirst")==0){
            scanf("%i",&u);
            addFirst(u);
        } else if(strcmp(s,"addafter")==0){
            scanf("%i %i",&u,&v);
            addAfter(u,v);
        } else if(strcmp(s,"addbefore")==0){
            scanf("%i %i",&u,&v);
            addBefore(u,v);
        } else if(strcmp(s,"remove")==0){
            scanf("%i",&u);
            Remove(u);
        } else if(strcmp(s,"reverse")==0) Reverse();
    }
    printList();
}