//Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các hình chữ nhật trong danh sách trên
//Dữ liệu
//· Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
//· Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
//Kết quả
//· Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,tmp;
	scanf("%i",&n);
	int *x1=(int *)calloc(n,sizeof(int));
	int *y1=(int *)calloc(n,sizeof(int));
	int *x2=(int *)calloc(n,sizeof(int));
	int *y2=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%i %i %i %i",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++){
		if(x1[i]>x2[i]){
			tmp=x1[i];
			x1[i]=x2[i];
			x2[i]=tmp;
		}
		if(y1[i]>y2[i]){
			tmp=y1[i];	
			y1[i]=y2[i];
			y2[i]=tmp;
		}
	}
	int mx1=999999,my1=999999,mx2=-1,my2=-1;
	for(i=0;i<n;i++){
		if(x1[i]<mx1) mx1=x1[i];
		if(y1[i]<my1) my1=y1[i];
		if(x2[i]>mx2) mx2=x2[i];
		if(y2[i]>my2) my2=y2[i];
	}
	printf("%i",((mx2-mx1)*(my2-my1)));
	free(x1); free(x2); free(y1); free(y2);
}