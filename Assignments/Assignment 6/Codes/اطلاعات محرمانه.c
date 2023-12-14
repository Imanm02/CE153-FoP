#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int set_max_char ( int * str);
int set_max_sum ( int * arr);

int l;

int main()
{
    int m,n;
    scanf("%d%d%d",&n, &m, &l);

    // setting the 3d input array
    int *** voroodi = (int ***) malloc( n * sizeof( int** ));// satrha

    for ( int i=0; i< n; i++){
        *( voroodi + i ) = (int **) malloc ( m * sizeof( int *));// sotoon ha

        for ( int j=0; j< m; j++){

            *(*( voroodi +i ) +j ) = (int *) malloc ( ( l+1 ) * sizeof( int )); //too ha!

            char f_or_t;
            scanf("\n%c", &f_or_t);

            if( f_or_t == 'F'){
                for ( int k = 1; k <= l; k++){
                    scanf("%*c%c", *( *( voroodi +i )+j )+k );
                }
            }

            else{  // f_or_t == 'T'
                for ( int k = 1; k <= l; k++ ){
                    scanf ("%d", *(*( voroodi + i) +j )+k );
                }
            }
            // setting the F or T chars, they are not set as char, but the ascii code. F : 70 , T : 84
            *( *( *( voroodi +i) +j)) = (int) f_or_t;
        }
    }

    //declaring the 2d output array
    int ** output = ( int **) malloc( n * sizeof( int *));
    for ( int i=0; i< n; i++ ){
        *( output + i) = malloc ( m * sizeof( int ));
    }

    for ( int i=0; i<n; i++ ){
        for( int j=0; j< m; j++ ){
            int ans;

            if ( *(*(*( voroodi + i) +j)) == 70 ) //means F
                ans = set_max_char( *(*( voroodi + i )+ j) );
            else{ //T
                ans = set_max_sum ( *(*( voroodi + i) +j) );

            }

            *(*( output + i) +j) = ans;
        }
    }

    for ( int i=0; i< n; i++){
        for ( int j=0; j<m; j++){
            if(  *(*(*( voroodi + i) +j)) == 70 ) // F
                printf("%c ", *(*( output + i) +j ));
            else
                printf("%d ", *(*( output + i) +j ));
        }
        printf("\n");
    }

    return 0;
}

int set_max_char( int * str){

    int max=0;
    for ( int i=1; i<=l; i++){
        if ( (int) *( str + i ) > max )
            max =(int) *( str+i);
    }
    if ( 65 <= max && max <= 90 ){
        max += 32;
    }
    return max;
}

int set_max_sum ( int * arr){

    int max_sum = 0;
    int current_sum;

    for ( int i=1; i<=l; i++ ){
        current_sum = 0;

        for ( int j=i; j<=l; j++){
            current_sum += *( arr +j);
            if ( current_sum > max_sum )
                max_sum = current_sum;
        }
    }
    return max_sum;
}


