#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n;
char A[21];
char save[1048576][21];
int writen = 0;

void printSolution()
{
    int i;
    strcpy(save[writen], A);
    strcat(save[writen], "\n");
    writen++;
}

void Try(int k)
{
    int v;
    for ( v = 0 ; v <= 1 ; v++ )
    {
        if ( v == 0 ) A[k] = '0';
        else if ( v == 1 ) A[k] = '1';
        if ( k == n - 1 ) printSolution();
        else Try(k + 1);
    }
}

int main()
{
    char s[6] = { 0 };
    scanf("%i %s", &n, s);
    Try(0);
    int i, count = 0;
    for ( i = 0 ; i < writen ; i++ )
    {
        char *check = strstr(save[i], s);
        if (check != NULL) continue;
        else count++;
    }
    printf("%i", count);
}