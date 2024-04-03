//Sửa chương trình sao chép tập tin ở slide trước để chương trình chỉ
//hiện nội dung tập tin ra màn hình, sau đó hiển thị số các dòng văn
//bản.
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Invalid parameters!\nSyntax: <program_name> <source_file> <offset> <destionation_file>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"rt");
    if(src==NULL){
        printf("Source file not found!");
        return 1;
    }
    int line=0;
    printf("Reading file %s... done!",argv[1]);
    char c[1000];
    while(!feof(src)){
        fgets(c,1000,src);
        printf("%s",c);
        line++;
    }
    printf("This file has %i line(s).",line);
}