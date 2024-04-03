//Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
//Dữ liệu
//· Dòng 1: xâu P1
//· Dòng 2: xâu P2
//· Dòng 3: văn bản T
//Kết quả:
//· Ghi văn bản T sau khi thay thế
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_SIZE 1000
int main(){
    int position[MAX_SIZE]={0},i,j,count=0;
    char t[MAX_SIZE]={0},p1[MAX_SIZE]={0},p2[MAX_SIZE]={0};
    fgets(p1,MAX_SIZE,stdin); fgets(p2,MAX_SIZE,stdin); fgets(t,MAX_SIZE,stdin);
    t[strlen(t)-1]='\0'; p1[strlen(p1)-1]='\0'; p2[strlen(p2)-1]='\0';
    for(i=0;i<strlen(t);i++){
        if(t[i]==p1[0]){
            for(j=1;j<strlen(p1);j++){
                if(t[i+j]==p1[j]){
                    position[i]=1;
                } else {
                    position[i]=0;
                    break;
                }
            }
            if(position[i]) printf("%s",p2);
            i=i+strlen(p1)-1;
        } else printf("%c",t[i]);
    }
}