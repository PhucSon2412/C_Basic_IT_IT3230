//Compute the sum of two integers a and b.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *a){
	int i,tmp;
	for(i=0;i<strlen(a)/2;i++){
		tmp=a[i];
		a[i]=a[strlen(a)-i-1];
		a[strlen(a)-i-1]=tmp;
	}
}
void sum(char *a,char *b){
	int c[31]={0};
	int i,j;
	for(i=0;i<30;i++){ 
		if(a[i]==0&&b[i]==0) break;
		if(a[i]==0&&b[i]!=0){
			c[i]=c[i]+b[i]-48;
			continue;
		}
		if(a[i]!=0&&b[i]==0){
			c[i]=c[i]+a[i]-48;
			continue;
		}
		if((a[i]-48)+(b[i]-48)<=9){
			c[i]=c[i]+(a[i]-48)+(b[i]-48);
		} else if((a[i]-48)+(b[i]-48)>9){
			c[i+1]++;
			c[i]=c[i]+(a[i]-48)+(b[i]-48)-10;
		}
	}
	int maxlen;
	if(strlen(a)>strlen(b)) maxlen=strlen(a);
	else maxlen=strlen(b);
	if(c[maxlen]!=0){
			while(c[maxlen]!=0){
			maxlen++;
		}
	}
	for(i=maxlen-1;i>=0;i--) printf("%i",c[i]);
}
int main(){
	int i=0;
	char a[30]={0},b[30]={0};
	scanf("%s %s",a,b);
	reverse(a); reverse(b);
	sum(a,b);
}