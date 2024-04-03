//• Tạo một file văn bản với tên lab1.txt với nội dung bất kỳ, lưu trong
//thư mục cùng với chương trình.
//• Viết chương trình đọc từ file trên mỗi lần một ký tự, sau đó ghi
//chúng vào một file mới với tên lab1w.txt
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* src=fopen("C:\\Folder\\Code\\C_Basic\\lab1.txt","rt");
    FILE* des=fopen("C:\\Folder\\Code\\C_Basic\\lab1w.txt","wt");
    char c;
    while((c=fgetc(src)) != EOF){
        fputc(c,des);
    }
    fclose(src);
    fclose(des);
}