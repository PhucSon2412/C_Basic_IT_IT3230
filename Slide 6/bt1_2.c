#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100000

int a[MAX_SIZE] = {0};

void merge(int L, int M, int R)
{
    int ta[MAX_SIZE] = {0};
    int i = L, j = M + 1, k;
    for ( k = L; k <= R; k++)
    {
        if (i > M)
        {
            ta[k] = a[j];
            j++;
        }
        else if (j > R)
        {
            ta[k] = a[i];
            i++;
        }
        else if (a[i] <= a[j])
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
    memcpy( a + L, ta + L, (R - L + 1) * sizeof(int));
}

void msort(int L, int R)
{
    if (L >= R) return;
    int M = (L + R) / 2;
    msort(L, M);
    msort(M + 1, R);
    merge(L, M, R);
}

int binarySearch(int L, int R, int Y)
{
    if (L > R) return 0;
    if (L == R) if(a[L] == Y) return 1;
                else return 0;
    int M = (L + R) / 2;
    if (a[M] == Y) return 1;
    else if (a[M] > Y) return binarySearch(L, M - 1, Y);
    else return binarySearch(M + 1, R, Y);
}

int main()
{
    int i, n, Q, count = 0;
    scanf("%i %i", &n, &Q);
    for ( i = 0; i < n; i++)
        scanf("%i", &a[i]);
    msort(0,n-1);
    for ( i = 0; i < n; i++)
    {
        int ok = binarySearch( i + 1, n - 1, Q - a[i]);
        count += ok;
    }
    printf("%i", count);
}