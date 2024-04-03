#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001

void merge(int a[], int L, int M, int R)
{
    int i = L, j = M + 1, k, tmp_a[MAX_SIZE];
    for(k = L;k <= R;k++)
    {
        if(i > M)
        {
            tmp_a[k] = a[j];
            j++;
        } 
        else if (j > R)
        {
            tmp_a[k] = a[i];
            i++;
        }
        else if (a[i] < a[j])
        {
            tmp_a[k] = a[i];
            i++;
        } else
        {
            tmp_a[k] = a[j];
            j++;
        }
    }
    memcpy(a + L, tmp_a + L, sizeof(int) * (R - L + 1));
}

void mergeSort(int a[], int L, int R)
{  
    if(L < R)
    {
        int M = (L + R) / 2;
        mergeSort(a, L, M);
        mergeSort(a, M+1, R);
        merge(a, L, M, R);
    }
}

int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for (i = 0;i < n;i++) scanf("%i", &a[i]);
    mergeSort(a,0,n-1);
    for (i = 0;i < n;i++) printf("%i ", a[i]);
}