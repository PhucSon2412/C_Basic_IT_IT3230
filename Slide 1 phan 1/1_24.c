//Viết chương trình đọc từng dòng văn bản từ một tập tin, sau đó tính
//độ dài xâu ký tự trên mỗi dòng và ghi ra một tập tin mới theo định
//dạng sau: <độ dài dòng> <Nội dung dòng>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Invalid parameter!\nSyntax:<program_name> <source_file>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"r");
    FILE* des=fopen(argv[2],"w");
    if(src==NULL){
        printf("Source file missing!");
        return 1;
    }
    char line[1000];
    while (fgets(line,1000,src)!=NULL)
    {
        fprintf(des,"%i\t%s",strlen(line)-1,line);
    }
    fclose(src);
    fclose(des);
}