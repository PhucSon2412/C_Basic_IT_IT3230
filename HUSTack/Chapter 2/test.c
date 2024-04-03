#include<stdio.h>
#define MOD 1000000007
#define MAX 1000
long long C[MAX][MAX];
void precompute(){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<=i;j++){
            if(j==0||j==i){
                C[i][j]=1;
            }else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
            }
        }
    }
}
int main(){
    int k,n;
    precompute();
    scanf("%d %d",&k,&n);
    printf("%lld",C[n][k]);
    return 0;
}