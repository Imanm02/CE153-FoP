#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MOD 94
#define MAX 1000000

struct block {
    char** transactions;
    int p;
    int n;
};

typedef struct block Block;
Block* new_block(int, int);
char value(char*,int);
char* calculate_hash(char*,Block*);

int main(){
    int m;
    Block* tmp;
    char* prev_hash = malloc(MAX);
    scanf("%d",&m);
    scanf(" %s",prev_hash);
    for(int i=1;i<m;i++){
        int n,p;
        scanf("%d %d",&n,&p);
        tmp = new_block(n,p);
        for(int j=0;j<n;j++){
            scanf(" %s",tmp->transactions[j]);
        }
        char* hash = calculate_hash(prev_hash,tmp);
        free(prev_hash);
        prev_hash = hash;
    }
    printf("%s\n",prev_hash);
    return 0;
}

Block* new_block(int n,int p){
    Block* tmp = malloc(sizeof(Block));
    tmp->n = n;
    tmp->p = p;
    tmp->transactions = malloc(n * sizeof(char*));
    for(int i=0;i<n;i++){
        tmp->transactions[i] = malloc(MAX);
    }
    return tmp;
}

char value(char* s,int p){
    int tmp = 0;
    int power = 1;
    for(int i=0;s[i]!='\0';i++){
        tmp += (s[i]*power);
        tmp %= MOD;
        power = (power*p)%MOD;
    }
    tmp+=33;
    return tmp;
}

char* calculate_hash(char* prev_hash,Block* b){
    char* tmp = calloc(1,b->n + 1);
    for(int i=0;i<b->n;i++){
        tmp[i] = value(b->transactions[i],b->p);
    }
    char alter = value(prev_hash,b->p);
    tmp[alter % b->n] = alter;
    return tmp;
}