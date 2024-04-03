//Tạo một tập tin văn bản có tên product.txt, mỗi dòng trong đó chứa
//thông tin về một sản phẩm: ID (kiểu int), Product Name (xâu ký tự
//không chứa ký tự trắng), Price (kiểu double). Các trường dữ liệu trên
//phân tách với nhau bởi một ký tự space hoặc tab. Ví dụ
//1 Samsung_Television_4K 20000000
//2 Apple_MacBook_2020 18560000
//Viết chương trình đọc tập tin trên vào một mảng các phần tử cấu trúc
//và sau đó hiện nội dung mảng trên ra màn hình dưới dạng:
//No Product Name Price
//1 Samsung_Television_4K 20000000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct product{
    int STT;
    char name[23];
    long price;
} product;
int main(){
    FILE* src=fopen("1_26_test.txt","r");
    int n=0,i;
    product pd[100];
    while(!feof(src)){
        fscanf(src,"%i %s %ld",&pd[n].STT,pd[n].name,&pd[n].price);
        n++;
    }
    printf("No\tProduct\t\t\t\tPrice\n");
    for(i=0;i<n;i++){
        printf("%-5i\t%-25s\t%i\n",pd[i].STT,pd[i].name,pd[i].price);
    }
}