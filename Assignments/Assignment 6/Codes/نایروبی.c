#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int size = 100;

    char * type = (char* ) malloc( size * sizeof( char));
    void * value = ( void * ) malloc( size * sizeof( double ));

    char  * order = ( char *) malloc ( 10 * sizeof ( char ));
    int index =0;

    while ( 1 ){
        scanf ( "%s", order );

        if ( strcmp ( order ,"out") == 0 )
            break;

        else if ( strcmp( order, "access")== 0 ){

            int wanted_index;
            scanf("%d", &wanted_index);

            if ( wanted_index >= index || wanted_index <0)
                printf("Out of Boundaries\n");

            else if ( *( type + wanted_index ) == 'i')
                printf("Integer %d is in index %d\n", *(int *)((double *) value + wanted_index ),  wanted_index );

            else if ( *( type + wanted_index ) == 'c')
                printf("Character %c is in index %d\n",  *(char *)((double *) value + wanted_index ) , wanted_index );

            else if ( *( type + wanted_index ) == 'f')
                printf("Float %.6lf is in index %d\n",  *( (double *) value + wanted_index ) , wanted_index );

            else if ( *( type + wanted_index ) == 'b'){
                if (  *(bool *)( (double *) value + wanted_index ) == false )
                    printf("Boolean False is in index %d\n", wanted_index );
                else
                    printf("Boolean True is in index %d\n", wanted_index );
            }
        }

        else if ( strcmp ( order , "print-all") == 0 ){
                if( index == 0)
                    printf("Nothing Exists...\n");

                for( int i=0 ; i< index ; i++ ){
                    printf("%d: ", i);

                    if (  *( type + i ) == 'i' )
                        printf("Integer - %d\n", *(int *)( (double *) value + i) );

                    if (  *( type + i ) == 'c' )
                        printf("Character - %c\n", *(char *) ( (double *) value + i) );

                    if (  *( type + i ) == 'f' )
                        printf("Float - %.6lf\n", *( (double *) value +i ));

                    if (  *( type + i ) == 'b' ){
                        if (* (bool *) ((double *) value +i)  == true )
                            printf("Boolean - True\n");
                        else
                            printf("Boolean - False\n");
                    }
                }
            }

        else if ( strcmp ( order , "erase-all") == 0 ){
            index = 0;
            printf( "All Data Has Been Cleared...\n");
        }

        else{

            if ( index >= size ){
                size += 100;
                type = (char * ) realloc ( type , size * sizeof ( char ));
                value = (void * ) realloc ( value , size * sizeof ( double ));
            }

            if( strcmp ( order, "int") == 0){
                    *( type + index ) = 'i';
                    scanf( "%d", (int *)((double *) value + index ) );
                    printf("Integer %d added to index %d\n", *(int *)( (double *) value + index ), index);
                    index ++;
            }

            else if( strcmp ( order, "char") == 0){

                    *( type + index ) = 'c';
                    scanf("\n%c" , (char *)( (double *) value + index ));

                    printf("Character %c added to index %d\n", *(char *)( (double *) value + index ) , index);
                    index ++;
            }

            else if( strcmp ( order, "float") == 0){

                    *( type + index )= 'f';
                    scanf("%lf" , (double *) value + index );

                    printf("Float %.6lf added to index %d\n", *( (double *) value + index ), index);
                    index ++;
            }

            else if( strcmp ( order, "bool") == 0){

                    *( type + index ) = 'b';
                    scanf("%d" , (int *)(( double *) value + index) );

                    if ( *( bool *) ( (double *)value + index ) == false)
                        printf("Boolean False added to index %d\n", index);
                    else
                        printf("Boolean True added to index %d\n", index);
                    index ++;
            }
        }
    }

    free ( order );
    free ( type );
    free ( value);

    return 0;
}
