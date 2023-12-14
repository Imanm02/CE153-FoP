#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size = 100;
    int ** a = (int **) malloc(size * sizeof(int *));
    for(int i=0; i< size; i++){
        *(a+i) = malloc( 2* sizeof(int));
    }

    int code = 0;
    int num_of_people = 0;

    scanf( "%d", &code);
    while( code != -1 ){
        if (num_of_people >= size){
            a = realloc( a, (size+100) * sizeof( int *));

            for(int i= size ; i< size +100; i++){
                *( a+i ) = malloc( 2* sizeof( int ));
            }
            size += 100;
        }

        *(*(a+ num_of_people)) = code;

        scanf("%d", *(a+ num_of_people) + 1);
        scanf("%d", &code);

        if ( code != -1)
            num_of_people ++;
        }

    int winner_index ;
    int min_num;
    int has_winner = 0;
    int isrepeated;

    for (int i=0; i<= num_of_people; i++){
        isrepeated = 0;
        for (int j =0; j<= num_of_people; j++){
            if (i!= j && *(*(a+i)+1) == *(*(a+j) + 1) ) {
               isrepeated = 1;
            }
        }

        if (isrepeated == 0){
            if (has_winner == 0 || *(*(a+i)+1)< min_num ){
                min_num = *(*(a+i)+1);
                winner_index = i;
                has_winner = 1;
            }
        }
    }

    if( has_winner ){
        int count = 0;
        for (int i=0; i <= num_of_people; i++ ){
            if (*(*( a+i)) == *(*(a + winner_index)) )
                count++;
        }
        if(count ==1)
            printf("%d won.", *(*(a + winner_index)));
        else
            printf("%d cheated.", *(*(a + winner_index)));
    }
    else{
        printf("no one won.");
    }

    for(int i=0; i< size; i++){
        free (*(a+i));
    }

    free(a);
    return 0;
}