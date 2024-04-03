//Viết chương trình có đối số dòng lệnh như sau
//merge <file1> <file2> <file3>
//Chương trình ghi vào file 3 bằng cách đọc và trộn lần lượt từng dòng
//từ file 1 và file 2. Chương trình đọc một dòng từ file 1, ghi vào file 3 sau
//đó đọc một dòng từ file 2 – ghi vào file 3. Chú ý: File 1 và File 2 có thể
//có số dòng khác nhau, khi đọc hết nội dung một file, chương trình sao
//chép các dòng tiếp theo của file còn lại vào file 3
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc!=4){
        printf("Invalid parameters!\nSyntax: <program_name> <source_file_1> <source_file_2> <destionation_file>.");
        return 1;
    }
    FILE* f1=fopen(argv[1],"rt");
    FILE* f2=fopen(argv[2],"rt");
    FILE* des=fopen(argv[3],"wt");
    if(f1==NULL||f2==NULL){
        printf("Source file not found!");
        return 1;
    }
    char c1[2000],c2[2000];
    while ((fgets(c1, 2000, f1) != NULL)&& (fgets(c2, 2000, f2) != NULL)) {
        fputs(c1,des);
        fputs(c2,des);
    }
    while (fgets(c1, 2000, f1) != NULL) {
        fprintf(des,"\n");
        fputs(c1,des);
    }
    while (fgets(c2, 2000, f2) != NULL) {
        fprintf(des,"\n");
        fputs(c2,des);
    }

    fclose(f1);
    fclose(f2);
    fclose(des);
}