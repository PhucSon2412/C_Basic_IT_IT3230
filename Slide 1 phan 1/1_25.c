//Viết chương trình để đọc một dãy số nhập từ bàn phím và ghi chúng ra
//tệp “out.txt” theo thứ tự ngược lại. Ngoài ra, tổng các số được ghi vào cuối file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
int main(){
    FILE* des=fopen("1_25_test.txt","w");
    int n,i,total=0;
    scanf("%i",&n);
    int *number=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        scanf("%i",&number[i]);
        total+=number[i];
    }
    for(i=n-1;i>=0;i--) fprintf(des,"%i ",number[i]);
    fprintf(des,"%i",total);
    fclose(des);
}