//Viết tiếp chương trình ví dụ trên để hiển thị phần tử mảng có giá
//trị gần nhất với giá trị trung bình của tất cả các phần tử mảng
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(){
    int i;
    float average,closest1=0,closest2=10000,n,total=0;
    printf("How many numbers: ");
    scanf("%f",&n);
    float *number=(float *)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        printf("Enter number %i: ",i+1);
        scanf("%f",&number[i]);
        printf("\n");
        total+=number[i];
    }
    average=total/n;
    for(i=0;i<average;i++){
        if((average-number[i])<(average-closest1)) closest1=number[i];
    }
    for(i=number[5];i>average;i--){
        if((number[i]-average)<(closest2-average)) closest2=number[i];
    }
    if(average-closest1<closest2-average) printf("Average: %f",closest1);
    else printf("Average: %f",closest2);
    free(number);
}