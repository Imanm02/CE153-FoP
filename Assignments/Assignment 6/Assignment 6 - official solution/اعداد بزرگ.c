#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M (10000+10)

void reverse(char* c){
	int n = strlen(c);
	for(int i=0;i<n-i-1;i++){
		char tmp = *(c+i);
		*(c+i) = *(c+n-i-1);
		*(c+n-i-1) = tmp;
	}
}

char* sum(char* a,char* b,int r){
	int n = strlen(a);
	int m = strlen(b);
	reverse(a);
	reverse(b);
	char* res = calloc(M,1);
	int remain = 0;
	int i;
	for(i=0;i<n||i<m;i++){
		int x = remain;
		if(i<n)
			x += *(a+i)-'0';
		if(i<m)
			x += *(b+i)-'0';
		*(res+i) = (x%r)+'0';
		remain = x/r;
	}
	while(remain>0){
		*(res + i) = (remain%r)+'0';
		remain = remain/r;
	}
	reverse(res);
	return res;
}

int main(){
	int r;
	scanf("%d",&r);
	char* a = calloc(M,1);
	char* b = calloc(M,1);
	scanf("%s %s",a,b);
	char* res = sum(a,b,r);
	printf("%s",res);
	return 0;
}