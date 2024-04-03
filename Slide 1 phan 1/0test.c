#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct sinhvien{
    int stt;
    int mssv;
    char name[27];
    long tel;
    float grade;
} SV;

int main(){
    FILE* src=fopen("1_27_test.txt","r+");
    FILE* des=fopen("1_27_test2.txt","w+");
    int n=0,i;
    SV sv[100];
    while(!feof(src)){
        fscanf(src,"%i %i %s %ld",&sv[n].stt,&sv[n].mssv,sv[n].name,&sv[n].tel);
        n++;
    }
    for(i=0;i<n;i++){
        printf("Enter %s's grade: ",sv[i].name);
        scanf("%f",&sv[i].grade);
    }
    fprintf(des,"%-3s%-10s%-30s%-10s%-10s\n","No","StudentID","Name","Telephone","Grade");
    for(i=0;i<n;i++){
        fprintf(des,"%-3i%-10i%-30s%-10ld%-10.2f\n",sv[i].stt,sv[i].mssv,sv[i].name,sv[i].tel,sv[i].grade);
    }
    fclose(src);
    fclose(des);
}