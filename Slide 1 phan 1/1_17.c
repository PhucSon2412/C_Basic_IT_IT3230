//Viết chương trình double_line nhận một tập tin đầu vào và biến
//đổi nội dung của nó như sau: chương trình sẽ chèn thêm 1 dòng
//trống giữa các dòng trong văn bản. Kết quả được ghi vào một
//tập tin ở đầu ra. Chương trình chạy dưới dạng đối số dòng lệnh
//như sau: ./double_line <File 1> <File 2> 
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* src=fopen("C:\\Folder\\Code\\C_Basic\\1_17_test.txt","rt");
    FILE* des=fopen("C:\\Folder\\Code\\C_Basic\\1_17_test2.txt","wt");
    char c;
    while((c=fgetc(src)) != EOF){
        if(c=='\n'){
            fprintf(des,"\n\n");
            continue;
        }
        fputc(c,des);
    }
    fclose(src);
    fclose(des);
}