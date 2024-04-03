//Viết hàm nhận đối số là một số thực (double) và trả về phần nguyên
//và phần thập phân của số đó.
//Viết chương trình minh họa hàm trên, với số thực được nhập từ
//người dùng.
#include<stdio.h>
void split(double a,int *itg,double *dcm){
    *itg=(int)a;
    *dcm=a-(float)*itg;
}
int main(){
    double a,dcm;
    int itg;
    scanf("%lf",&a);
    split(a,&itg,&dcm);
    printf("Interger: %i\nDecimal: %.3lf",itg,dcm);
}