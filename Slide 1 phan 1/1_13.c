//• Viết chương trình đọc nội dung từ một tập tin văn bản, mỗi lần đọc một
//ký tự.
//• Chương trình sẽ chuyển ký tự chữ cái hoa thành ký tự chữ cái thường
//và ngược lại, sau đó ghi vào một tập tin khác.
//• Chú ý với các ký tự khác – chương trình vẫn thực hiện sao chép một
//cách thông thường sang tập tin mới. 
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* src=fopen("C:\\Folder\\Code\\C_Basic\\lab1.txt","rt");
    FILE* des=fopen("C:\\Folder\\Code\\C_Basic\\lab1w.txt","wt");
    char c;
    while((c=fgetc(src)) != EOF){
        if(c>='a'&&c<='z'){
            c=c-('a'-'A');
            fputc(c,des);
            continue;
        }
        if(c>='A'&&c<='Z') c=c+('a'-'A');
        fputc(c,des);
    }
    fclose(src);
    fclose(des);
}