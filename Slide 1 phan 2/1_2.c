//Xây dựng và chạy minh họa (demo) hàm sau
//char* subStr(char* s1, int offset, int number)
//Hàm tách xâu con từ xâu s1 bắt đầu từ ký tự tại chỉ số offset (tính từ 0) 
//và có độ dài number ký tự.
//Chú ý kiểm tra tính hợp lệ của các đối số. Trong trường hợp giá trị
//number lớn hơn độ dài phần còn lại của xâu s1 tính từ vị trí offset, trả
//về xâu con là phần còn lại của s1 tính từ vị trí offset.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX_SIZE 1000
char* subStr(char* s1, int offset, int number){
    if((offset+number)>strlen(s1)){
        char* ss=(char *)calloc(sizeof(char),strlen(s1)-offset);
        strcpy(ss,s1+offset-1);
        return ss;
    } else if((offset+number)<=strlen(s1)){
        char *ss=(char *)calloc(sizeof(char),number);
        strcpy(ss,s1+offset-1);
        ss[number]='\0';
        return ss;
    }
}
int main(){
    char s1[MAX_SIZE];
    char *ss;
    int offset,number;
    printf("Enter s1: ");
    fgets(s1,MAX_SIZE,stdin);
    s1[strlen(s1)-1]='\0';
    printf("Enter offset and number: ");
    scanf("%i %i",&offset,&number);
    ss=subStr(s1,offset,number);
    printf("%s",ss);
    free(ss);
}