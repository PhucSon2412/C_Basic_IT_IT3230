//• Viết chương trình mycat đọc và hiển thị nội dung một tập tin văn bản
//trên màn hình. Chương trình hỗ trợ hai cú pháp sử dụng như sau:
//• cat <filename> : Hiển thị một lần toàn bộ nội dung
//• cat <filename> -p : Hiển thị theo từng trang. Người dùng chạm một
//phím để xem trang tiếp theo.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define line 10
int main(int argc,char* argv[]){
    if(argc>3){
        printf("Invalid parameter!\nSyntax:<program_name> <source_file> <viewmode>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"rt");
    if(src==NULL){
        printf("Source file missing!");
        return 1;
    }
    char c[5000];
    if(argc==3){
        if(!strcmp(argv[2],"-p")){
            int i;
            while(1){
                for(i=0;i<line;i++){
                    fgets(c,5000,src);
                    printf("%s",c);
                    if(feof(src)) break;
                }
                if(feof(src)) return 0;
                fflush(stdin);
                printf("\n Press button to continue.\n");
                getchar();
            }
        }
    }
    if(argc==2){
        while(!feof(src)){
            fgets(c,5000,src);
            printf("%s",c);
        }
    }
    fclose(src);
}