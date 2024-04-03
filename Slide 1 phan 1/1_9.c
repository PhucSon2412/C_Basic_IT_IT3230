//• Viết chương trình cho phép người dùng nhập một câu dưới dạng đối số
//dòng lệnh (mỗi từ trong câu là một đối số). Chương trình hiển thị nội
//dung câu đảo ngược của câu đã nhập.
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(int argc,char *argv[]){
    int i,n=argc-1;
    for(i=n;i>0;i--){
        printf("%s ",argv[i]);
    }
}