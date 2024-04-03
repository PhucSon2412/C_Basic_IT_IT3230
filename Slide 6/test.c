#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

int a[MAX_SIZE] = { 0 };
int c, n;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int check(int x)
{
    int i = 0, j = 0;
    int bo = c;
    while ( i < n && bo > 0 )
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
    qsort(a, n, sizeof(int), cmpfunc);
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