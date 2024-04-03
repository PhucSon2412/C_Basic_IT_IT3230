//Viết hàm :
//• Có tham số là một xâu ký tự và hai ký tự
//• Hàm sẽ duyệt xâu và thay thế tất cả các ký tự thứ nhất trong xâu
//bằng ký tự thứ hai.
//• Viết chương trình để kiểm tra hàm nói trên:
//• Đọc một xâu không chứa ký tự trắng và hai ký tự, sau đó gọi hàm
//với các đối số trên và in ra kết quả
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100000
void replace(char s[],char c,char r){
    int i=0;
    for(i=0;i<strlen(s);i++) if(s[i]==c) s[i]=r;
}
int main(){
    char s[MAX_SIZE],c,r;
    scanf("%s",s);
    fflush(stdin);
    scanf("%c %c",&c,&r);
    replace(s,c,r);
    printf("%s",s);
}