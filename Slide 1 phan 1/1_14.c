//• Viết chương trình có tên mycp hoạt động tương tự lệnh cp trong các hệ
//điều hành UNIX/LINUX. Nó có thể sao chép một tập tin văn bản sang
//một tập tin mới theo cú pháp:
//• mycp <tập_tin_1> <tập_tin_2>
//• Đường dẫn, tên các tập tin được cung cấp dưới dạng đối số dòng lệnh.
//• Chú ý: Chương trình phải kiểm tra cú pháp sử dụng (vd số đối số –
//thông báo lỗi và hiển thị hướng dẫn khi cần..)
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Invalid parameters!\nSyntax: <program_name> <source_file> <destination_file>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"rt");
    FILE* des=fopen(argv[2],"wt");
    if(src==NULL){
        printf("Source file not found!");
    }
    char c[256];
    while(!feof(src)){
        fgets(c,256,src);
        fprintf(des,"%s",c);  
    }
    fclose(src);
    fclose(des);
}