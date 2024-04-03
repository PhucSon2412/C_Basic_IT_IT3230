// /Viết một hàm nhận đối số là hai mảng số nguyên, có cùng số
//phần tử. Hàm trả về 1 nếu hai mảng có nội dung trùng nhau và 0
//cho các trường hợp còn lại. Hàm trả vể -1 nếu 2 mảng có nội dung đối
//xứng
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 10000
int similar(int s1[],int s2[]){
    int i,s1len=0,s2len=0,sml=0,symmetry=0;
    for (i=0;i<MAX_SIZE||s1[i]==0;i++) if(s1[i]!=0) s1len+=1;
    for (i=0;i<MAX_SIZE||s2[i]==0;i++) if(s2[i]!=0) s2len+=1;
    if(s1len!=s2len) return 0;
    else{
        for (i=0;i<s1len;i++){
            if(s1[i]==s2[s2len-i-1]) symmetry=1;
            else {
                symmetry=0;
                break;
            }
        }
        if(symmetry) return -1;
        for (i=0;i<s1len;i++){
            if(s1[i]==s2[i]) sml=1;
            else sml=0;
            if(sml==0) return 0;
        }
    }
    return 1;
}
int main(){
    char c;
    int i=0,s1[MAX_SIZE]={0},s2[MAX_SIZE]={0};
    printf("Enter first array: ");
    while((c=getchar())!='\n'){
        s1[i]=c-48;
        i++;
    }
    printf("Enter second array: ");
    i=0;
    while((c=getchar())!='\n'){
        s2[i]=c-48;
        i++;
    }
    printf("%i",similar(s1,s2));
}