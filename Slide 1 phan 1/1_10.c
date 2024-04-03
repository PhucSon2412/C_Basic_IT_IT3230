//Viết chương trình tính lũy thừa x của cơ số tự nhiên e^x
//. Người dùng có thể khởi chạy chương trình với hai cú pháp:
//<Tên_chương_trình> <giá trị lũy thừa> ví dụ: e 50
//Hoặc
//<Tên_chương_trình> <giá trị lũy thừa> <sai_số_cho_phép>. Ví dụ: e 50 0.0003
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(int argc,char *argv[]){
    if(argc>3){
        printf("Invalid Parameter!");
        return 1;
    }
    int exponential=atoi(argv[1]);
    float last=exp(exponential);
    if(argc==2) printf("%f",last);
    else if(argc==3){
        char a[100]={0};
        float decimal=atof(argv[2]);
        int i,n=strlen(argv[2])-2;
        sprintf(a,"%f",last);
        int dot=0;
        for(i=0;i<strlen(a);i++){
            if(a[i]=='.'){
                dot=i;
                break;
            }
        }
        printf("%c\n",a[dot+n+1]);
        if(a[dot+n+1]>='5'){
            a[dot+n]++;
            a[dot+n+1]='\0';
        }
        else{
            a[dot+n]--;
            a[dot+n+1]='\0';
        }
        puts(a);
        
    }
}