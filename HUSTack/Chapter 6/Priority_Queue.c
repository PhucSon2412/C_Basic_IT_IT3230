#include <stdio.h>
#include <stdlib.h>

int n, a[100000] = { 0 };

void shiftUp(int x)
{
    int father = (x - 1) / 2;
    while ( x > 0 && a[father] > a[x] )
    {
        int tmp = a[father];
        a[father] = a[x];
        a[x] = tmp;
        x = father;
        father = (x - 1) / 2;
    }
}

void shiftDown(int x)
{
    int L = x * 2 + 1;
    int R = x * 2 + 2;
    int min = x;
    if ( L < n && a[L] < a[min] ) min = L;
    if ( R < n && a[R] < a[min] ) min = R;
    if ( min != x )
    {
        int tmp = a[min];
        a[min] = a[x];
        a[x] = tmp;
        shiftDown(min);
    }
}

void enqueue(int v)
{
    a[n] = v;
    n++;
    shiftUp(n-1);
}

int dequeue()
{
    int v = a[0];
    a[0] = a[n-1];
    n--;
    shiftDown(0);
    return v;
}

int main()
{
    int i, tmp, capacity, total = 0;
    scanf("%i", &capacity);
    for ( i = 0 ; i < capacity ; i++ )
    {
        scanf("%i", &tmp);
        enqueue(tmp);
    }
    while ( n > 1 )
    {
        int a = dequeue();
        int b = dequeue();
        int c = a + b;
        total += c;
        enqueue(c);
    }
    printf("%i", total);
}