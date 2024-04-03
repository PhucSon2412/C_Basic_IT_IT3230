//Viết chương trình đọc một xâu ký tự biểu diễn một câu từ người
//dùng. Sau đó chương trình hiển thị mỗi từ trong câu trên một
//dòng. Một từ là một dãy các ký tự liên tiếp không chứa ký tự
//trắng. 
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10000
int main(){
    char s[MAX_SIZE];
    int i;
    fgets(s,MAX_SIZE,stdin);
    s[strlen(s)-1]='\0';
    for(i=0;i<strlen(s);i++){
        if(s[i]!=32) printf("%c",s[i]);
        else printf("\n");
    }
}