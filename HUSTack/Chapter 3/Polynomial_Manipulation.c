#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int Poly[10000][1001]={0};
void Create(){
    int poly_id;
    scanf("%i",&poly_id);
    Poly[poly_id][1000]=1;
}
void AddTerm(){
    int poly_id,coef,exp;
    scanf("%i %i %i",&poly_id,&coef,&exp);
    Poly[poly_id][1000]=1;
    if(Poly[poly_id][exp]!=0) Poly[poly_id][exp]+=coef;
    else Poly[poly_id][exp]=coef;
}
void EvaluatePoly(){
    int poly_id,value;
    scanf("%i %i",&poly_id,&value);
    if(Poly[poly_id][1000]==0){
        printf("0\n");
        return;
    } else {
        int i,sum=0;
        for(i=999;i>=0;i--){
            if(Poly[poly_id][i]!=0) sum+=(Poly[poly_id][i]*pow(value,i));
        }
        printf("%i\n",sum);
    }
}
void AddPoly(){
    int poly_id1,poly_id2,result_poly_id,i;
    scanf("%i %i %i",&poly_id1,&poly_id2,&result_poly_id);
    Poly[result_poly_id][1000]=1;
    for(i=0;i<1000;i++) Poly[result_poly_id][i]=Poly[poly_id1][i]+Poly[poly_id2][i];
}
void PrintPoly(){
    int poly_id,i;
    scanf("%i",&poly_id);
    for(i=999;i>=0;i--){
        if(Poly[poly_id][i]!=0) printf("%i %i ",Poly[poly_id][i],i);
    }
    printf("\n");
}
void Destroy(){
    int poly_id,i;
    for(i=0;i<=1000;i++) Poly[poly_id][i]=0;
}
int main(){
    char s[20];
    while(1){
        fflush(stdin);
        scanf("%s",s);
        if(s[0]=='*') break;
        if(strcmp(s,"Create")==0) Create();
        if(strcmp(s,"AddTerm")==0) AddTerm();
        if(strcmp(s,"EvaluatePoly")==0) EvaluatePoly();
        if(strcmp(s,"AddPoly")==0) AddPoly();
        if(strcmp(s,"PrintPoly")==0) PrintPoly();
        if(strcmp(s,"Destroy")==0) Destroy();
    }
}