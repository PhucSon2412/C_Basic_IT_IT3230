#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int id;
    struct node* leftChild;
    struct node* rightSib;
} node;
node* root;
node* makeNode(int u){
    node* newNode=(node*)calloc(1,sizeof(node));
    newNode->id=u;
    newNode->leftChild=NULL;
    newNode->rightSib=NULL;
    return newNode;
}
void makeRoot(int u){
    node* newNode=makeNode(u);
    root=newNode;
}
node* find(node* r,int u){
    if(r==NULL) return NULL;
    if(r->id==u) return r;
    node* p=r->leftChild;
    while(p!=NULL){
        node* q=find(p,u);
        if(q!=NULL) return q;
        p=p->rightSib;
    }
}
void Insert(int u,int v){
    node* p=find(root,v);
    if(p->leftChild==NULL){
        node* newNode=makeNode(u);
        p->leftChild=newNode;
    } else { 
        node* cur=p->leftChild;
        while(cur->rightSib!=NULL) cur=cur->rightSib;
        node* newNode=makeNode(u);
        cur->rightSib=newNode;
    }
}
void PreOrder(node* p)
{
    if(p==NULL)
    {
        return;
    }else
    {
        printf("%d ",p->id);
        node* tmp=p->leftChild;
        while(tmp!=NULL)
        {
            PreOrder(tmp);
            tmp=tmp->rightSib;
        }
    }
}

void InOrder(node* p)
{
    if(p==NULL)
    {
        return;
    }
    node* tmp = p->leftChild;
    InOrder(tmp);
    printf("%d ",p->id);
    if(tmp != NULL)
    {
        tmp = tmp -> rightSib;
    }
    while (tmp != NULL)
    {
        InOrder(tmp);
        tmp=tmp->rightSib;
    }
}

void PostOrder(node* p)
{
    if( p == NULL)
    {
        return;
    }
    node* tmp = p->leftChild;
    while(tmp!= NULL)
    {
        PostOrder(tmp);
        tmp=tmp->rightSib;
    }
    printf("%d ",p->id);
}

int main(){
    char s[100];
    while(1){
        fflush(stdin);
        scanf("%s",s);
        if(s[0]=='*') break;
        if(strcmp(s,"MakeRoot")==0){
            int u;
            scanf("%i",&u);
            makeRoot(u);
        }
        if(strcmp(s,"Insert")==0){
            int u,v;
            scanf("%i %i",&u,&v);
            Insert(u,v);
        }
        if(strcmp(s,"PreOrder")==0){
            PreOrder(root);
            printf("\n");
        }
        if(strcmp(s,"InOrder")==0){
            InOrder(root);
            printf("\n");
        }
        if(strcmp(s,"PostOrder")==0){
            PostOrder(root);
            printf("\n");
        }
    }
}
