//Write a function that gets a string and two chars as arguments. The functions scans the string and replaces every occurrence of the first char with the second one.
//Write a program to test the above function. The program should read a string from the user (no spaces) and two characters, then call the function with the input, and print the result.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
int main(){
	char s[MAX_SIZE],c,r;
	scanf("%s %c %c",s,&c,&r);
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]==c) s[i]=r;
	}
	printf("%s",s);
}