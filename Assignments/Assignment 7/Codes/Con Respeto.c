#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block {
    int P;
    int num_of_transactions;
    char hash [1000];
    char primary_string [1000];
    char transactions [1000][1000];
};

typedef struct block Block;
Block* new_block(int, int);

void calculate_hash( int t );

int reminder_to_94 ( int p, int k);

char value( char * s, int p);


Block * blocks_arr [1000];
int num_of_blocks = 0;

int main() {
    int m;
    scanf("%d", &m);
    char first_hash [1000];
    scanf("%s", first_hash);


    blocks_arr[0] =  new_block( 2,1); //  n, p don't matter!
    strcpy( blocks_arr[0]->hash , first_hash);

    //scanning the blocks
    for ( int i=1; i< m; i++){
        int n,P;
        scanf( "%d %d",&n,&P);
        blocks_arr[i] = new_block( P, n);
    }

    calculate_hash( m-1);
    printf("%s", blocks_arr[m-1]->hash);

    return 0;
}

Block * new_block ( int P, int n ){

    Block * block = ( Block *) calloc( 1, sizeof( Block));
    block->P = P;
    block->num_of_transactions = n;

    if( num_of_blocks != 0) {
        for (int j = 0; j < n; j++) {
            scanf("%s", block->transactions [j]);
        }
        for (int i = 0; i < n; i++) {
            block->primary_string[i] = value(block->transactions[i], block->P);
        }
    }
    num_of_blocks ++;
    return block;
}
void calculate_hash( int t){

    if ( t== 0){
        return;
    }
    char alter;
    calculate_hash( t-1 );

    alter = value( blocks_arr[t-1]->hash , blocks_arr[t]->P);
    int index_to_put_alter = alter % ( blocks_arr[t]->num_of_transactions );

    char * hash = blocks_arr[t]->primary_string  ;

    hash[ index_to_put_alter] = alter;

    strcpy( blocks_arr[t]->hash,  hash);

}

char value ( char * s, int p ){
    int len = (int) strlen( s);
    int sum=0;
    int sum_argument;
    for ( int k = 0; k< len; k++){
        sum_argument = s[k] * reminder_to_94( p,k);
        sum += sum_argument % 94;
    }

    char c = sum% 94 +33;
    return c;
}
int reminder_to_94( int p, int k){
    int answer = 1;
    while( k != 0){
        answer = answer *p;
        answer = answer % 94;
        k--;
    }
    return answer;
//    if ( k == 0)
//        return 1;
//    int ans = reminder_to_94( p, k-1);
//    ans = (ans * p ) % 94;
//    return ans;
}