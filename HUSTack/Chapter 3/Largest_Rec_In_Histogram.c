#include<stdio.h>
int heights[1000]={0},stack[1000]={0};
int main(){
    int i,N,top=-1,height,width,area,maxArea=0;
    scanf("%i",&N);
    for(i=0;i<N;i++) scanf("%i",&heights[i]);
    i=0;
    while(i<N){
        if(top==-1||heights[i]>=heights[stack[top]]){
            stack[++top]=i++;
        } else {
            height=heights[stack[top]];
            top--;
            if(top==-1) width=i;
            else width=i-1-stack[top];
            area=height*width;
            if(area>maxArea) maxArea=area;
        }
    }
    while(top!=-1){
        height=heights[stack[top]];
        top--;
        if(top==-1) width=i;
        else width=i-1-stack[top];
        area=height*width;
        if(area>maxArea) maxArea=area;
    }
    printf("%i",maxArea);
    return 0;
}