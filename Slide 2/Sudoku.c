#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int x[9][9]={0};
void printSolution(){
    int r,c;
    for(r=0;r<=8;r++){
        for(c=0;c<=8;c++) printf("%i ",x[r][c]);
        printf("\n");
    }
    printf("\n");
    getchar();
}
int check(int v,int r,int c){
    int i,j,R=r/3,C=c/3;
    for(i=0;i<=8;i++) if(x[r][i]==v) return 0;
    for(i=0;i<=8;i++) if(x[i][c]==v) return 0;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(x[3*R+i][3*C+j]==v) return 0;
        }
    }
    return 1;
}
void Try(int r,int c){
    int v;
    for(v=1;v<=9;v++){
        if(check(v,r,c)){
            x[r][c]=v;
            if(r==8&&c==8) printSolution();
            else {
                if(c<8) Try(r,c+1);
                if(c==8) Try(r+1,0);
            }
            x[r][c]=0;
        }
    }
}
int main(){
    Try(0,0);
}