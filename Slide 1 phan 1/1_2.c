//Viết chương trình nhập vào một xâu ký tự và hiển thị số lần xuất
//hiện của mỗi ký tự có trong xâu.
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100000
int main(){
    int i,count[26]={0};
    char s[MAX_SIZE],c;
    printf("Enter sentence: ");
    while((c=getchar())!='\n'){
        if(65<=c&&c<=90){
            count[c-65]+=1;
        }
        if(97<=c&&c<=122){
            count[c-97]+=1;
        }
    }
    for(i=0;i<25;i++){
        if(count[i]!=0){
            printf("The letter '%c' appears %i time(s).\n",i+65,count[i]);
        }
    }

}