//• Viết chương trình nhận hai số thực làm đối số dòng lệnh, đại diện cho
//chiều dài và chiều rộng của một hình chữ nhật.
//• Chương trình dựa trên đó tính toán và in ra diện tích và chu vi của hình
//chữ nhật.
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    float lenght=atof(argv[1]),height=atof(argv[2]);
    if(argc!=3){
        printf("Invalid Parameter!");
        return 1;
    }
    float s=lenght*height,p=(lenght+height)*2;
    printf("Spread = %.2f\n",s);
    printf("Perimeter = %.2f\n",p);
    return 0;
}

