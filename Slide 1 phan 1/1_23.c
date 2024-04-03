//Viết chương trình nhận đối số dòng lệnh là đường dẫn đến một file
//văn bản (nội dung dưới 80 dòng). Chương trình thêm một dòng mới
//vào cuối file nói trên với nội dung chứa các ký tự đầu tiên của các
//dòng trong file ban đầu.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Invalid parameter!\nSyntax:<program_name> <source_file>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"a+");
    if(src==NULL){
        printf("Source file missing!");
        return 1;
    }
    char first[81]={0},c[256];
    int i=0;
    while(fgets(c,256,src)){   
        if(i<80){
            first[i]=c[0];
            i++;
        }
    }   
    fseek(src,0,SEEK_END);
    fprintf(src,"\n%s",first);
    fclose(src);
}