#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct node
{
    int id;
    struct node* left;
    struct node* right;
} node;

node* root = NULL;

node* tree[50001] = {NULL};

node* makeNode(int id)
{
    node* newNode = (node*) malloc (sizeof(node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
}

void MakeRoot(int id)
{
    root = makeNode(id);
    tree[id] = root;
}

void AddLeft(int u, int v)
{
    tree[v]->left = makeNode(u);
    tree[u] = tree[v]->left;
}

void AddRight(int u, int v)
{
    tree[v]->right = makeNode(u);
    tree[u] = tree[v]->right;
}

int max(int a,int b)
{
    return (a > b) ? a : b;
}

int height(node* p)
{
    if(p==NULL) return 0;
    return max(height(p->left),height(p->right))+1;
}

int isAVL(node* r)
{
    if(r == NULL) return 1;
    int h1 = height(r->left);
    int h2 = height(r->right);
    if(abs(h1 - h2) <= 1 && isAVL(r->left) && isAVL(r->right)) return 1;
    else return 0; 
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
            MakeRoot(u);
        }
        if (strcmp(s, "AddLeft") == 0)
        {
            int u,v;
            scanf("%i %i", &u, &v);
            AddLeft(u, v);
        }
        if (strcmp(s, "AddRight") == 0)
        {
            int u,v;
            scanf("%i %i", &u, &v);
            AddRight(u, v);
        }
    }
    printf("%i %i",isAVL(root),height(root));
}