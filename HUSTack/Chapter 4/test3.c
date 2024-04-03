#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int count=0;

struct node
{
    int value;
    struct node* leftChild;
    struct node* rightSibling;
};
typedef struct node node;
node* root=NULL;

node* makeNode(int value){
    node* newNode=(node*)calloc(1,sizeof(node));
    newNode->value=value;
    newNode->leftChild=NULL;
    newNode->rightSibling=NULL;
    return newNode;
}

node* findNode(int value,node* r){
    if(r==NULL) return NULL;
    if(r->value==value) return r;
    node* tmp=findNode(value,r->leftChild);
    if(tmp!=NULL) return tmp;
    else
    {
        tmp=r->rightSibling;
        if(tmp!=NULL)
        {
            node* tmp1=findNode(value,tmp);
            if(tmp1!=NULL) return tmp1;
        }
    }
    return NULL;
}

void insert(int v_child,int v_parent){
    node* tmp=findNode(v_parent,root);
    if(tmp==NULL) return;
    node* newNode=makeNode(v_child);
    if(tmp->leftChild==NULL) tmp->leftChild=newNode;
    else
    {
        tmp=tmp->leftChild;
        while (tmp->rightSibling!=NULL) tmp=tmp->rightSibling;
        tmp->rightSibling=newNode;
    }
}

int demSoChuSo(int n)
{
    int dem=0;
    do{
        dem++;
        n=n/10;
    }while(n!=0);
    return dem;
}

void printTree(node *root, int depth) {
    if (root == NULL) {
        return;
    }
    printTree(root->leftChild, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("|   ");
    }
    printf("+---%d\n", root->value);
    printTree(root->rightSibling, depth + 1);
}

int main(){
    char buffer[1024]={0},number[1024]={0};
    int a[100]={0};
    int r_exist=0;
    while(1)
    {
        fflush(stdin);
        fgets(buffer,sizeof(buffer)-1,stdin);
        buffer[strlen(buffer)-1]='\0';
        if(buffer[0]=='$'&&buffer[1]=='$') break;
        int n=0,i;
        char* tmpBuf=(char *)buffer;
        while(1)
        {
            sscanf(tmpBuf,"%s",number);
            if(number[0]=='$') break;
            a[n]=atoi(number);
            n++;
            tmpBuf+=(demSoChuSo(a[n])+1);
        }
        if(r_exist==0)
        {
            root=makeNode(a[0]);
            r_exist=1;
        }
        node* tmp=findNode(a[0],root);
        if(tmp==NULL) continue;
        for(i=1;i<n;i++)
        {
            insert(a[i],a[0]);
        }
    }
    printTree(root, 0);
}