#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    int child;
    struct node* child1;
    struct node* child2;
    struct node* child3;
};
typedef struct node node;
node* root = NULL;

node* makeNode (int value) 
{
    node* newNode = (node* ) calloc (1,sizeof(node));
    newNode->value = value;
    newNode->child = 0;
    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->child3 = NULL;
    return newNode;
}

void makeRoot(int u)
{
    node* newNode = makeNode(u);
    root = newNode;
}

node* findNode (int value, node* r) {
    if (r == NULL) return NULL;
    if (r->value == value) return r;
    node* tmp = NULL;
    tmp = findNode(value,r->child1);
    if(tmp !=NULL) return tmp;
    tmp = findNode(value,r->child2);
    if(tmp !=NULL) return tmp;
    tmp = findNode(value,r->child3);
    if(tmp !=NULL) return tmp;
    return NULL;
}

void insert (int v_child, int v_parent) {
    node* tmp = findNode(v_parent, root);
    if (tmp == NULL) return;
    node* newNode = makeNode(v_child);
    if (tmp->child1 == NULL) tmp->child1 = newNode;
    else if (tmp->child2 == NULL) tmp->child2 = newNode;
    else if (tmp->child3 == NULL) tmp->child3 = newNode;
    tmp->child++;
}

void PreOrder(node* r)
{
    if(r == NULL) return;
    printf("%i ",r->value);
    PreOrder(r->child1);
    PreOrder(r->child2);
    PreOrder(r->child3);
}

void InOrder(node* r)
{
    if(r == NULL) return;
    InOrder(r->child1);
    printf("%i ",r->value);
    InOrder(r->child2);
    InOrder(r->child3);
}

void PostOrder(node* r)
{
    if(r == NULL) return;
    PostOrder(r->child1);
    PostOrder(r->child2);
    PostOrder(r->child3);
    printf("%i ",r->value);
}

int main()
{
    char s[100];
    while (1) {
        fflush(stdin);
        scanf("%s", s);
        if (s[0] == '*') break;
        if (strcmp(s, "MakeRoot") == 0)
        {
            int u;
            scanf("%i", &u);
            makeRoot(u);
        }
        if (strcmp(s, "Insert") == 0)
        {
            int u,v;
            scanf("%i %i", &u, &v);
            insert(u, v);
        }
        if (strcmp(s, "PreOrder") == 0)
        {
            PreOrder(root);
            printf("\n");
        }
        if (strcmp(s, "InOrder") == 0)
        {
            InOrder(root);
            printf("\n");
        }
        if (strcmp(s, "PostOrder") == 0) 
        {
            PostOrder(root);
            printf("\n");
        }
    }
}