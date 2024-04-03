//Viết chương trình nhận tên hai tập tin ở đối số dòng lệnh, sau đó tiến
//hành ghép nội dung của tập tin thứ hai vào cuối tập tin thứ nhất. Giả sử
//cả hai tập tin đều tồn tại.Cú pháp sử dụng: apd <file1> <file2>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Invalid parameters!\nSyntax: <program_name> <append_file> <source_file>.");
        return 1;
    }
    FILE* des=fopen(argv[1],"at");
    FILE* src=fopen(argv[2],"rt");
    if(src==NULL){
        printf("Source file not found!");
    }
    char c;
    while((c=fgetc(src)) != EOF){
        fputc(c,des);
    }
    fclose(src);
    fclose(des);
}