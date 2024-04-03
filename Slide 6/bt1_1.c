#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,Q,count = 0;
    scanf("%i %i", &n, &Q);
    int *a = (int *)malloc(n*sizeof(int));
    for ( i = 0; i < n; i++)
        scanf("%i", &a[i]);
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if ( (a[i] + a[j]) == Q)
            {
                count++;
            }
        }
    }
    printf("%i", count);
}