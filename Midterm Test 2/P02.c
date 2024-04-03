#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, C, T, S, R, slot_found = 999, slot_id;
    scanf("%i %i %i %i", &C, &T, &S, &R);
    int* slot = (int *) calloc (S+1 , sizeof(int));
    for ( i = 0 ; i < C ; i++ )
    {
        int a, b, c, d;
        scanf("%i %i %i %i", &a, &b, &c, &d);
        slot[c]++;
    }
    for ( i = 1 ; i <= S ; i++ )
    {
        if ( slot[i] < slot_found )
        {
            slot_found = slot[i];
            slot_id = i;
        }
    }
    printf("%i %i", slot_id, T-slot_found);
    free(slot);
}