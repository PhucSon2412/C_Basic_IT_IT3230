//• Cài đặt hàm my_strcat :
//• Đầu vào là hai xâu ký tự s1 và s2
//• Đầu ra: một con trỏ - trỏ tới vùng nhớ động chứa nội dung là xâu
//kết quả của phép nối hai xâu s1 và s2
//• Ví dụ: Phép nối “hello_” và “world!” trả về “hello_world!”
//• Sử dụng kỹ thuật cấp phát bộ nhớ động
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX_SIZE 1000
char *my_strcat(char *s1,char *s2){
    char *s3=(char *)calloc(strlen(s1)+strlen(s2)+1,sizeof(char));
    strcpy(s3,s1);
    strcpy(s3+strlen(s1),s2);
    return s3;
}
int main(){
    char s1[MAX_SIZE],s2[MAX_SIZE];
    char *s3;
    printf("Enter s1: ");
    fgets(s1,MAX_SIZE,stdin);
    s1[strlen(s1)-1]='\0';
    printf("Enter s2: ");
    fgets(s2,MAX_SIZE,stdin);
    s2[strlen(s2)-1]='\0';
    s3=my_strcat(s1,s2);
    printf("%s",s3);
    free(s3);
}