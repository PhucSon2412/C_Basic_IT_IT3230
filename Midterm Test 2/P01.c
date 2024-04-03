#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, even = 0, odd = 0;
    scanf("%i", &n);
    int *a = (int *) calloc (n, sizeof(int));
    for ( i = 0 ; i < n ; i++ )
        scanf("%i", &a[i]);
    for ( i = 0 ; i < n ; i++ )
    {
        if ( a[i] % 2 == 0 ) odd++;
        else even++;
    }
    printf("%i %i", even, odd);
    free(a);
}