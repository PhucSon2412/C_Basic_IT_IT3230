//• Tạo một file văn bản nội dung là danh sách lớp gồm ít nhất 6 sinh viên.
//Mỗi dòng gồm 4 trường sau:
//• STT(số thứ tự) Mã số sinh viên Họ và tên (không chứa ký tự trắng) Số
//điện thoại. Ví dụ
//• 1 20181110 Bui_Van 0903112234
//• 2 20182111 Joshua_Kim 0912123232
//• Viết chương trình đọc tập tin trên vào một mảng các cấu trúc phù hợp.
//Chương trình yêu cầu nhập bổ sung thêm trường điểm cho mỗi sinh
//viên sau đó ghi lại kết quả vào tập tin bangdiem.txt (transcript.txt) gồm
//tất cả các trường nói trên (cùng trường điểm).
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct sinhvien{
    int stt;
    int mssv;
    char name[27];
    int tel;
    float grade;
} SV;
int main(){
    FILE* src=fopen("1_27_test.txt","r+");
    FILE* des=fopen("1_27_test2.txt","w+");
    int n=0,i;
    SV sv[100];
    while(!feof(src)){
        fscanf(src,"%i %i %s %i",&sv[n].stt,&sv[n].mssv,sv[n].name,&sv[n].tel);
        n++;
    }
    for(i=0;i<n;i++){
        printf("Enter %s's grade: ",sv[n].name);
        scanf("%f",&sv[i].grade);
    }
    fprintf(des,"%3s%10s%30s%10s%10s\n","No","StudentID","Name","Telephone","Grade");
    for(i=0;i<n;i++){
        fprintf(des,"%3i%10i%30s%10i%10f\n",sv[n].stt,sv[n].mssv,sv[n].name,sv[n].tel,sv[n].grade);
    }
    fclose(src);
    fclose(des);
}