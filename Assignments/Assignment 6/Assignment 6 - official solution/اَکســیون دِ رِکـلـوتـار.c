#include<stdio.h>
#include<stdlib.h>

int cmp(int* a,int* b,int i,int j){
	return (*(b+i)) < (*(b+j));
}

void merge(int* a,int* b,int n){
	int* tmpa = calloc(n,sizeof(int));
	int* tmpb = calloc(n,sizeof(int));
	int n1 = n/2;
	int n2 = n;
	int i1=0;
	int i2=n1;
	int i=0;
	while(i1<n1 && i2<n2){
		if(cmp(a,b,i1,i2)){
			*(tmpa + i) = *(a+i1);
			*(tmpb + i) = *(b+i1);
			i1++;
		}
		else{
			*(tmpa + i) = *(a+i2);
			*(tmpb + i) = *(b+i2);
			i2++;
		}
		i++;
	}
	while(i1<n1){
		*(tmpa + i) = *(a+i1);
		*(tmpb + i) = *(b+i1);
		i1++;
		i++;
	}
	while(i2<n2){
		*(tmpa + i) = *(a+i2);
		*(tmpb + i) = *(b+i2);
		i2++;
		i++;
	}
	for(int j=0;j<i;j++){
		*(a+j) = *(tmpa+j);
		*(b+j) = *(tmpb+j);
	}
	free(tmpa);
	free(tmpb);
}

void msort(int* a,int *b,int n){
	if(n<=1)
		return;
	int mid = n/2;
	msort(a,b,mid);
	msort(a+mid,b+mid,n-mid);
	merge(a,b,n);
}

int main(){
	int* id = calloc(1,sizeof(int));
	int* num = calloc(1,sizeof(int));
	int n=0;
	while(1){
		int a,b;
		scanf("%d",&a);
		if(a==-1)
			break;
		scanf("%d",&b);
		id = realloc(id,(n+1)*sizeof(int));
		num = realloc(num,(n+1)*sizeof(int));
		*(id + n) = a;
		*(num + n) = b;
		n++;
	}
	msort(id,num,n);
	int winner = -1;
	for(int i=0;i<n;i++){
		if(i-1>=0 && *(num+i-1)==*(num+i))
			continue;
		if(i+1<n && *(num+i+1)==*(num+i))
			continue;
		winner = i;
		break;
	}
	if(winner==-1){
		printf("no one won.");
		return 0;
	}
	int cheat = 0;
	for(int i=0;i<n;i++){
		if(i==winner)
			continue;
		if(*(id+i)==*(id+winner)){
			cheat = 1;
			break;
		}
	}
	if(cheat){
		printf("%d cheated.",*(id+winner));
	}
	else{
		printf("%d won.",*(id+winner));
	}
	return 0;
}