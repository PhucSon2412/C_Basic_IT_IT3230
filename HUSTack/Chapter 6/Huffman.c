#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGHT 100

typedef struct NODE
{
    int character;
    int freq;
    struct NODE *left;
    struct NODE *right;
} node ;

node* nodes[100] = { 0 };
int freq[256] = { 0 };
int totalBit = 0;
int bits[100] = { 0 };
int n = 0;

void shiftUp(int x)
{
    int father = (x - 1) / 2;
    while ( x > 0 && nodes[father]->freq > nodes[x]->freq )
    {
        node* tmp = nodes[father];
        nodes[father] = nodes[x];
        nodes[x] = tmp;
        x = father;
        father = (x - 1) / 2;
    }
}

void shiftDown(int x)
{
    int L = x * 2 + 1;
    int R = x * 2 + 2;
    int min = x;
    if ( L < n && nodes[L]->freq < nodes[min]->freq ) min = L;
    if ( R < n && nodes[R]->freq < nodes[min]->freq ) min = R;
    if ( min != x )
    {
        node* tmp = nodes[min];
        nodes[min] = nodes[x];
        nodes[x] = tmp;
        shiftDown(min);
    }
}

void enqueue(node* x)
{
    nodes[n] = x;
    n++;
    shiftUp(n-1);
}

node* dequeue()
{
    node* v = nodes[0];
    nodes[0] = nodes[n-1];
    n--;
    shiftDown(0);
    return v;
}

void printfBit(node* r, int count)
{
    if ( r->left == NULL && r->right == NULL )
    {
        // printf("%c : ", r->character);
        // int i;
        // for ( i = 0 ; i < count ; i++ )
        // {
        //     printf("%i", bits[i]);
        // }
        // printf("\n");
        totalBit += ( count * freq[r->character] );
    }
    else
    {
        if ( r->left != NULL)
        {
            bits[count] = 0;
            printfBit( r->left, count + 1 );
        }
        if ( r->right != NULL )
        {
            bits[count] = 1;
            printfBit( r->right, count + 1 );
        }
    }
}


int main()
{
    char s[100] = { 0 };
    fgets(s, sizeof(s) - sizeof(char), stdin);
    s[strlen(s) - 1] = '\0';
    int i;
    for ( i = 0 ; i < strlen(s) ; i++ )
    {
        freq[s[i]]++;
    }
    for ( i = 0 ; i < 256 ; i++ )
    {
        if ( freq[i] > 0 )
        {
            node* newNode = (node *) calloc (1, sizeof(node));
            newNode->freq = freq[i];
            newNode->character = i;
            newNode->left = NULL;
            newNode->right = NULL;
            enqueue(newNode);
        }
    }
    while ( n > 1 )
    {
        node* c1 = dequeue();
        node* c2 = dequeue();
        node* newNode = (node *) calloc (1, sizeof(node));
        newNode->character = 0;
        newNode->freq = c1->freq + c2->freq;
        if ( c1->freq <= c2->freq )
        {
            newNode->left = c1;
            newNode->right = c2;
        }
        else 
        {
            newNode->left = c2;
            newNode->right = c1;
        }
        enqueue(newNode);
    }
    printfBit(dequeue(), 0);
    printf("%i\n", totalBit);
    
}