#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order
{
    char code[8];
    int adult;
    int room_num;
    char hotel[4];
    char date[11];
    int child;
    struct order *next; 
};
typedef struct order order;

order* head = NULL;

order* makeNode(char *code, int adult, int room_num, char *hotel, char *date ,int child)
{
    order* newNode = (order*) calloc (1, sizeof(order));
    strcpy(newNode->code, code);
    strcpy(newNode->hotel, hotel);
    strcpy(newNode->date, date);
    newNode->adult = adult;
    newNode->room_num = room_num;
    newNode->child = child;
    newNode->next = NULL;
    return newNode;
}

struct tree
{
    char code[8];
    order* node;
    struct tree *left;
    struct tree *right;
}
typedef struct tree tree;
tree* root = NULL;

tree* makeTree(order *node)
{
    tree* newNode = (tree*) calloc (1, sizeof(tree));
    strcpy(newNode->code, node->code);
    newNode->node = node;
    newNode->left = NULL;
    newNode->right = NULL
    return newNode;
}

int main()
{
    int order_num;
    FILE *f = fopen("booking_orders.txt","r+t");
    fscanf(f, "%i", &order_num);
    printf("Number of order : %i\n", order_num);
    while (order_num--)
    {
        char code[8];
        int adult;
        int room_num;
        char hotel[4];
        char date[11];
        int child;
        fscanf(f, "%s %i %i %s %s %i", code, &adult, &room_num, hotel, date, &child);
        order* newNode = makeNode(code, adult, room_num, hotel, date, child);
        if ( head == NULL ) head = newNode;
        else 
        {
            order* tmp = head;
            while ( tmp->next != NULL ) tmp = tmp->next;
            tmp->next = newNode;
        }
    }
    int illegal = 0;
    order* tmp = head;
    while ( tmp->next != NULL )
    {
        if ( tmp->child != 0 && tmp->adult == 0 ) illegal++;
        tmp = tmp->next;
    }
    printf("Number of illegal order : %i\n", illegal);
    tmp = head;
    while ( tmp->next != NULL )
    {
        tree* newNode = makeTree(tmp);
        if ( root == NULL ) root = newNode;
        else 
        {
            if ( strcmp)
        }
        tmp = tmp->next;
    }

    fclose(f);
}