#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    int id;
    struct NODE* left;
    struct NODE* right;
} node;

node* root = NULL;

node* makeNode(int id)
{
    node* newNode = (node*) calloc (1, sizeof(node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int insertNode(node* newNode, node* r)
{
    if ( r == NULL ) r = newNode;
    else if ( newNode->id == r->id ) return 0;
    else 
    {
        if ( r->id > newNode->id ) 
        {
            if ( r->left == NULL ) r->left = newNode;
            else insertNode(newNode, r->left);
        }
        else 
        {
            if ( r->right == NULL ) r->right = newNode;
            else insertNode(newNode, r->right);
        }
    }
}

void PreOrder(node* r)
{
    if ( r == NULL ) return;
    else 
    {
        printf("%i ", r->id);
        PreOrder(r->left);
        PreOrder(r->right);
    }
}

void PostOrder(node* r)
{
    if ( r == NULL ) return;
    else 
    {
        PostOrder(r->left);
        PostOrder(r->right);
        printf("%i ", r->id);
    }
}

int main()
{
    char buffer[10] = { 0 };
    while (1)
    {
        scanf("%s", buffer);
        if ( buffer[0] == '#' ) break;
        else if ( strcmp(buffer, "insert") == 0 )
        {
            int i;
            scanf("%i", &i);
            if ( root == NULL ) root = makeNode(i);
            else if ( i == root->id ) continue;
            else insertNode(makeNode(i), root);
        }
        else if ( strcmp(buffer, "preorder") == 0 ) 
        {
            PreOrder(root);
            printf("\n");
        }
        else if ( strcmp(buffer, "postorder") == 0 )
        {
            PostOrder(root);
            printf("\n");
        }
    }
}