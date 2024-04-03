#include <stdio.h>
#define MAX_SIZE 1000001

int a[MAX_SIZE][2] = {0};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[MAX_SIZE][2], int low, int high)
{
    int pivot = a[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j][0] < pivot)
        {
            i++;
            swap(&a[i][0], &a[j][0]);
            swap(&a[i][1], &a[j][1]);
        }
    }
    swap(&a[i + 1][0], &a[high][0]);
    swap(&a[i + 1][1], &a[high][1]);
    return (i + 1);
}

void quickSort(int a[MAX_SIZE][2], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int check(int a[MAX_SIZE][2], int n)
{
    int intersect = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((a[j][0] > a[i][0] && a[j][0] < a[i][1]) || (a[j][1] > a[i][0] && a[j][1] < a[i][1]))
                intersect++;
            if (intersect == 2)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i, n;
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%i", &a[i][0]);
        scanf("%i", &a[i][1]);
    }

    quickSort(a, 0, n - 1);

    if (check(a, n))
        printf("TRUE");
    else
        printf("FALSE");

    return 0;
}
