#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

int a[MAX_SIZE] = { 0 };
int c, n;

void merge(int L, int M, int R)
{
    int ta[MAX_SIZE] = { 0 };
    int i = L, j = M + 1, k;
    for ( k = L ; k <= R ; k++ )
    {
        if ( i > M )
        {
            ta[k] = a[j];
            j++;
        }
        else if ( j > R )
        {
            ta[k] = a[i];
            i++;
        }
        else if ( a[i] <= a[j] )
        {
            ta[k] = a[i];
            i++;
        }
        else
        {
            ta[k] = a[j];
            j++;
        }
    }
    memcpy( a + L , ta + L , sizeof(int) * (R - L + 1) );
}

void mergesort(int L, int R)
{
    if (L >= R) return;
    int M = (L + R) / 2;
    mergesort(L, M);
    mergesort(M + 1, R);
    merge(L, M, R);
}

int check(int x)
{
    int i = 0, j = 0;
    int bo = c - 1;
    while ( j < n && bo > 0 )
    {
        j++;
        if ( a[j] - a[i] >= x )
        {
            i = j;
            bo--;
        }
        else
        {
            continue;
        }
    }
    return (bo == 0);
}

int main()
{
    int i;
    scanf("%i %i", &n, &c);
    for ( i = 0 ; i < n ; i++ )
        scanf("%i", &a[i]);
    mergesort(0, n - 1);
    int maxDis = a[n-1];
    int minDis = a[0];
    int MID = maxDis;
    while ( minDis < MID )
    {
        MID = ( maxDis + minDis ) / 2;
        if ( check(MID) )
        {
            minDis = MID;
        }
        else 
        {
            maxDis = MID;
        }
    }
    printf("%i", MID);
}