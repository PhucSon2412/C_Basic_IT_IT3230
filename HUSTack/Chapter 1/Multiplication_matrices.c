//Given two matrices Each element of the two matrices are integers from 1 to 50. Compute the product matrix C = A x B.
//Input
//Line 1 contains two positive integers n and k (1 <= n, k <= 100)
//Line i+1 (i = 1,2, ..., n): contains the i
//row of A (elements are separated by a SPACE character)
//Line n+2: contains two positive integers k and m (1 <= k,m <= 100)
//Line i+n+2 (i= 1, 2, ..., k): contains the i
//row of B (elements are separated by a SPACE character)
//Output
//Line i (i = 1,...,n) contains the i
//row of the resulting matrix (elements are separated by a SPACE character)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main(){
    int l1,c1,l2,c2,i,j,k,a[100][100],b[100][100],c[100][100]={0};
    scanf("%i %i",&l1,&c1);
    for(i=0;i<l1;i++){
        for(j=0;j<c1;j++) scanf("%i",&a[i][j]);
    }
    scanf("%i %i",&l2,&c2);
    for(i=0;i<l2;i++){
        for(j=0;j<c2;j++) scanf("%i",&b[i][j]);
    }
    for(i=0;i<l1;i++){
        for(j=0;j<c2;j++){
            c[i][j]=0;
            for(k=0;k<c2;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<l1;i++){
        for(j=0;j<c2;j++){
            printf("%i ",c[i][j]);
        }
        printf("\n");
    }
}