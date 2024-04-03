//Viết chương trình đọc một tập tin văn bản và hiển thị ra màn hình số
//hiệu từng dòng, theo sau là nội dung của dòng đó. Tên tập tin được
//cung cấp dưới dạng đối số dòng lệnh.
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
    printf("Reading file %s... done!\n",argv[1]);
    char c[1000];
    while(!feof(src)){
        fgets(c,1000,src);
        printf("%i %s",line+1,c);
        line++;
    }
    printf("\nThis file has %i line(s).",line);
}