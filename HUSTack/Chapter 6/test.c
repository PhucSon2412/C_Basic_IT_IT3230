#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node_
{
    int chr;
    int freq;
    struct node_* left;
    struct node_* right;
} NODE;

NODE* nodes[1000001] = { 0 };
int n = 0;
int bits[1000001] = { 0 };
int totalBit = 0;
int freq[256] = { 0 };

void shiftDown(int i)
{
    int L = i * 2 + 1;
    int R = i * 2 + 2;
    int min = i;
    if (L < n && nodes[L]->freq < nodes[min]->freq)
        min = L;
    if (R < n && nodes[R]->freq < nodes[min]->freq)
        min = R;
    if (min != i)
    {
        NODE* tmp = nodes[i];
        nodes[i] = nodes[min];
        nodes[min] = tmp;
        shiftDown(min);
    }
}

void shiftUp(int i)
{
    int parent = (i - 1) / 2;
    while (i > 0 && nodes[parent]->freq > nodes[i]->freq)
    {
        NODE* tmp = nodes[parent];
        nodes[parent] = nodes[i];
        nodes[i] = tmp;
        i = parent;
        parent = (i - 1) / 2;
    }
}

NODE* dequeue()
{
    NODE* r = nodes[0];
    nodes[0] = nodes[n - 1];
    n -= 1;
    shiftDown(0);
    return r;
}

void enqueue(NODE* x)
{
    nodes[n] = x;
    n += 1;
    shiftUp(n - 1);
}

void printCodes(NODE* root, int bits[], int count)
{
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->chr);
        for (int i = 0;i < count;i++)
        {
           printf("%d", bits[i]);
        }
        printf("\n");
        totalBit += count * freq[root->chr];
    }else
    {
        if (root->left != NULL)
        {
            bits[count] = 0;
            printCodes(root->left, bits, count + 1);
        }
        if (root->right != NULL)
        {
            bits[count] = 1;
            printCodes(root->right, bits, count + 1);
        }
    }
}

int main()
{
    //char* s = "Xin chao cac ban. Day la vi du huffman coding.";
    char s[1024] = { 0 };
    fgets(s, sizeof(s), stdin);
    for (int i = 0;i < strlen(s);i++)
    {
        freq[s[i]] += 1;
    }
    for (int i = 0;i < 256;i++)
    {
        if (freq[i] > 0)
        {
            NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
            newNode->freq = freq[i];
            newNode->chr = i;
            newNode->left = NULL;
            newNode->right = NULL;
            enqueue(newNode);
        }
    }
    while (n > 1)
    {
        NODE* tmp1 = dequeue();
        NODE* tmp2 = dequeue();
        NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
        newNode->chr = 0;
        if (tmp1->freq < tmp2->freq)
        {
            newNode->left = tmp1;
            newNode->right = tmp2;
        }else
        {
            newNode->left = tmp2;
            newNode->right = tmp1;
        }
        newNode->freq = tmp1->freq + tmp2->freq;
        enqueue(newNode);
    }

    printCodes(dequeue(), bits, 0);
    printf("%d\n", totalBit);
}