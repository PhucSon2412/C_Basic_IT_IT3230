#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100000] = { 0 };

int main()
{
    while (1)
    {
        char c[10];
        scanf("%s", c);
        if ( c[0] == '*' ) break;
        else a[atoi(c)] = 1;
    }
    fflush(stdin);
    char buffer[128] = { 0 };
    while (1)
    {
        scanf("%s", buffer);
        if ( buffer[0] == '*' && buffer[1] == '*' && buffer[2] == '*') break;
        else 
        {
            if ( strcmp(buffer, "find") == 0 )
            {
                int i;
                scanf("%i", &i);
                if ( a[i] == 0 ) printf("0\n");
                else printf("1\n");
            }
            else if ( strcmp(buffer, "insert") == 0 )
            {
                int i;
                scanf("%i", &i);
                if ( a[i] == 1 ) printf("0\n");
                else
                {
                    a[i] = 1;
                    printf("1\n");
                }
            }
        }
    }
    
}