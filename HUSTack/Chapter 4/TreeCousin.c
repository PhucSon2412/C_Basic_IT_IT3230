#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct node 
{
    char id[MAX_SIZE];
    struct node* leftChild;
    struct node* rightSibling;
    struct node* nextInQueue;
} node;

node* root = NULL;
node* queueStart = NULL;
node* queueEnd = NULL;
int queueSize = 0;

node* makeNode (char* name)
{
    node* newNode = (node*) calloc (1,sizeof(node));
    strcpy(newNode->id,name);
    newNode->leftChild = NULL;
    newNode->rightSibling = NULL;
    newNode->nextInQueue = NULL;
    return newNode;
}

node* findNode (node* r, char* id)
{
    if(r == NULL) return NULL;
    else if(strcmp(r->id,id)==0) return r;
    node* tmp = findNode(r->leftChild,id);
    if(tmp != NULL) return tmp;
    tmp = r->rightSibling;
    if(tmp != NULL)
    {
        node* tmp1 = findNode(tmp,id);
        if(tmp1 != NULL) return tmp1;
    }
    return NULL;
}

void insertNode (char* id_father, char* id_child)
{
    node* father = findNode(root, id_father);
    if(father == NULL) return;
    node* newNode = makeNode(id_child);
    if(father->leftChild == NULL) father->leftChild = newNode;
    else
    {
        node* tmp = father->leftChild;
        while (tmp->rightSibling != NULL) tmp = tmp->rightSibling;
        tmp->rightSibling = newNode;
    }
}

void enqueueNode(node* newNode)
{
    if(queueStart == NULL)
    {
        queueStart = newNode;
        queueEnd = newNode;
    } 
    else
    {
        queueEnd->nextInQueue = newNode;
        queueEnd = newNode;
    }
    queueSize++;
}

void dequeueNode()
{
    if(queueStart != NULL)
    {
        queueSize--;
        if(queueStart == queueEnd)
        {
            queueStart = NULL;
            queueEnd = NULL;
        } 
        else
        {
            queueStart = queueStart->nextInQueue;
        }
    }
}

void treeCousin(char *id)
{
    enqueueNode(root);
    int found = 0;
    while (queueSize > 0 && found == 0)
    {
        int size = queueSize;
        while (size > 0)
        {
            node* top = queueStart;
            node* tmp = top->leftChild;
            int isChild = 0;
            while (tmp != NULL)
            {
                if (strcmp(tmp->id, id) == 0)
                {
                    isChild = 1;
                    found = 1;
                    break;
                }
                tmp = tmp->rightSibling;
            }
            if (isChild == 0)
            {
                tmp = top->leftChild;
                while (tmp != NULL)
                {
                    enqueueNode(tmp);
                    tmp = tmp->rightSibling;
                }
            }
            dequeueNode();
            size--;
        }
    }
    if (queueSize > 0)
    {
        while (queueSize > 0)
        {
            printf("%s ", queueStart->id);
            dequeueNode();
        }
    }
    else printf("NOTFOUND");
}

int main()
{
    char buffer[MAX_SIZE]={0}, id[MAX_SIZE]={0}, id_parent[MAX_SIZE]={0}, inpId[MAX_SIZE]={0};
    char* tmpBuf;
    int r_exist = 0,count;
    scanf("%s", inpId);
    getchar();
    while (1)
    {
        count = 0;
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, MAX_SIZE - 1, stdin);
        if(buffer[0] == '$' && buffer[1] == '$') break;
        tmpBuf = (char*)buffer;
        while (1)
        {
            memset(id, 0, sizeof(id));
            sscanf(tmpBuf,"%s",id);
            if(id[0] == '$') break;
            tmpBuf = strstr(tmpBuf, id) + strlen(id);
            if(count == 0)
            {
                memset(id_parent, 0, sizeof(id_parent));
                strcpy(id_parent, id);
                if(r_exist == 0)
                {
                    root = makeNode(id_parent);
                    r_exist = 1;
                }
            } else
            {
                insertNode(id_parent,id);
            }
            count++;
        }
    }
    treeCousin(inpId);
}