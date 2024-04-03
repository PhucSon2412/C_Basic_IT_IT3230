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
    struct node* 
} node;

node* root = NULL;

node* makeNode (char* name)
{
    node* newNode = (node*) calloc (1,sizeof(node));
    strcpy(newNode->id,name);
    newNode->leftChild = NULL;
    newNode->rightSibling = NULL;
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

int height (node* r)
{
    if ( r == NULL) return 0;
    int h = 1;
    node* tmp = r->leftChild;
    while (tmp != NULL)
    {
        int h1 = height(tmp) + 1;
        tmp = tmp->rightSibling;
        if (h1 > h) h = h1;
    }
    return h;
}

int treeDiameter (node* r)
{
    if (r == NULL) return 0;
    int hmax1 = 0, hmax2 = 0;
    node* tmp = r->leftChild;
    while (tmp != NULL)
    {
        int h = height(tmp);
        tmp = tmp->rightSibling;
        if (h > hmax1)
        {
            hmax2 = hmax1;
            hmax1 = h;
        } else if (h > hmax2) hmax2 = h;
    }
    int d = 0, maxChild = 0;
    tmp = r->leftChild;
    while (tmp != NULL)
    {
        int d = treeDiameter(tmp);
        tmp = tmp->rightSibling;
        if (d > maxChild) maxChild = d;
    }
    if (maxChild > (hmax1 + hmax2)) return maxChild;
    else return (hmax1 + hmax2);
}

int main()
{
    char buffer[MAX_SIZE]={0},id[MAX_SIZE]={0},id_parent[MAX_SIZE]={0};
    char* tmpBuf;
    int r_exist = 0,count;
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
    printf ("%i", treeDiameter(root));
}