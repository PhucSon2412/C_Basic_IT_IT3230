//Viết một chương trình có thể sử dụng cùng một lúc hai chức
//năng mã hóa và giải mã một tập tin văn bản sử dụng mật mã
//Caesar (mã hóa cộng) như sau. Chương trình nhận ba đối số:
//<tập tin nguồn> <độ dịch chuyển> < tập tin đích>
//Khi cần mã hóa, chạy chương trình với độ dịch chuyển (offset) n
//là một số nguyên dương. Chương trình sẽ thay thế mỗi ký tự
//trong tập tin bởi một ký tự đứng sau nó n vị trí trong bảng mã
//ASCII. Ví dụ với offset =3 thì A->D, B->E
//Khi giải mã, chạy chương trình với đầu vào là tập tin mã hóa và
//giá trị độ dịch chuyển là số âm tương ứng (VD offset = -3)
//Chức năng nâng cao (tùy chọn): Với các ký tự là chữ cái thực
//hiện dịch chuyển vòng tròn: A-> D, ..., Z -> C
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc!=4){
        printf("Invalid parameters!\nSyntax: <program_name> <source_file> <offset> <destionation_file>.");
        return 1;
    }
    FILE* src=fopen(argv[1],"rt");
    FILE* des=fopen(argv[3],"wt");
    if(src==NULL){
        printf("Source file not found!");
    }
    int offset=atoi(argv[2]);
    char c;
    while((c=fgetc(src))!=EOF){
        if(c>='a'&&c<='z'){
            if((c+offset)>'z'){
                c=c+offset-26;
                fputc(c,des);
                continue;
            }
            if((c+offset)<'a'){
                c=c+offset+26;
                fputc(c,des);
                continue;
            }
        }
        if(c>='A'&&c<='Z'){
            if((c+offset)>'Z'){
                c=c+offset-26;
                fputc(c,des);
                continue;
            }
            if((c+offset)<'A'){
                c=c+offset+26;
                fputc(c,des);
                continue;
            }
        }
        c+=offset;
        fputc(c,des);
    }
    fclose(src);
    fclose(des);
}