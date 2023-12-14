#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

int find_substring_repetition( char * string , char * substring );
void delete_substring( char * string , char * substring );
void reverse( char * string , char * hold, int m, int n);  // I'm passing hold only because I don't want to allocate any more memory!

int print_mode = 1;

int main() {
    char * string = ( char *) calloc ( SIZE * SIZE , sizeof (char ));
    char * order = ( char *) calloc ( SIZE , sizeof (char ));
    char * hold = ( char *) calloc ( SIZE , sizeof (char ));

    gets( string);
    gets ( order );

    while ( strcmp( order, "exit") != 0){

        if ( strncmp ( order, "copy", 4 ) == 0 ){ // copy [n]
            if ( strcmp ( order, "copy") == 0) {
                strcpy( hold, string);
                strcat(string, hold);
            }
            else{
                int number;
                sscanf( order+5, "%d", &number );
                strcpy ( hold, string );

                for( int i=0; i< number; i++ ){
                    strcat( string, hold);
                }
            }
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order, "append", 6) == 0 ) {
            strcat(string, order + 7);
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order, "find", 4) == 0 ){
            int num = find_substring_repetition( string , order+5 ) ;
            if (num == 0)
                strcat ( string , order+ 5 );
            else {
                sprintf(hold, "%d", num);
                strcat(string, hold);
            }
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order, "count", 5) == 0 ) {
            if (strcmp(order, "count digits") == 0) {

                int digit_count = 0;
                for (int i = 0; i < strlen(string); i++) {
                    if ( string[i] >= 48 && string[i] <=57)
                        digit_count++;
                }
                sprintf(hold, "%d", digit_count);
                strcat(string, hold);
            }
            else if (strcmp(order, "count alphabets") == 0) {

                int alphabets_count = 0;
                for (int i = 0; i < strlen(string); i++) {
                    if ( ( string [i] >= 65 &&  string [i] <= 90 ) || ( string[i] >= 97 && string[i]<= 122 ) )
                        alphabets_count++;
                }
                sprintf(hold, "%d", alphabets_count);
                strcat(string, hold);

            }
            else{
                char char_to_search [2];
                char_to_search[0] = *( order +6);
                char_to_search[1] = '\0';

                int num = find_substring_repetition( string, char_to_search );
                sprintf(hold, "%d", num);
                strcat(string, hold);
            }
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order, "delete", 6) == 0 ){
            delete_substring( string, order+ 7);
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order, "reverse", 7) == 0 ){
            if ( strcmp( order , "reverse") == 0 )
                reverse ( string, hold, 0, strlen( string) );
            else{
                int m,n;
                sscanf ( order +8, "%d,%d", &m, &n);
                reverse ( string, hold , m, n);
            }
            if ( print_mode == 1)
                printf("%s\n", string);
        }

        else if ( strncmp ( order , "PRINT_MODE", 10 ) == 0 ) {
            if ( strcmp(order , "PRINT_MODE ON") == 0 )
                print_mode = 1;
            else if ( strcmp( order ,  "PRINT_MODE OFF") == 0)
                print_mode = 0;
        }
        else if ( strcmp( order, "print") == 0 )
            printf("%s\n", string );

//        if( strncmp ( order , "PRINT_MODE", 10 ) != 0 &&  strcmp( order, "print") != 0 && print_mode == 1 )

        gets(order);
    }

    free( string);
    free ( order);
    free ( hold) ;
    return 0;
}

int find_substring_repetition( char * string , char * substring ){
    int count = 0;
    char * hold = strstr( string, substring );
    while ( hold != NULL ){
        count ++;
        hold ++;
        hold = strstr( hold, substring);
    }
    return count;
}

void delete_substring( char * string , char * substring ) {



    int i = 0, k;
    while( i < strlen(string)) {

        if ( strncmp ( string+i, substring, strlen(substring)) == 0) {

            for ( k = 0;  string[ i + k + strlen ( substring )] != '\0' ; k++) {
                string[i + k] = string[i + strlen(substring) + k];
            }
            string[i + k] = '\0';
        }
        else{
            i++;
        }
    }
}

void reverse( char * string, char * hold, int m, int n ){
    strcpy( hold , string);
    for ( int i=m; i< n ; i++)
        string[i] = hold [ n +m -1  -i ];
}