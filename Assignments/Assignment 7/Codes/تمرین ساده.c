#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_spaces( char * string);
int compare_chars( char a, char b);
int compare_strings( char * str1 , char * str2);

int main() {
    int n;
    scanf("%d\n", &n);
    char ** a = (char **) malloc ( n * sizeof( char*));
    char ** b = (char **) malloc ( n * sizeof( char*));

    for ( int i=0; i<n; i++){
        a[i] = (char *) malloc( 100 * sizeof(char ));
        b[i] = (char *) malloc( 100 * sizeof(char ));

        gets( a[i]);
        strcpy( b[i], a[i]);
        delete_spaces( a[i]);
    }

    char b_hold[100];
    char a_hold[100];
    for ( int i=0; i<n; i++){
        for ( int j= i+1; j< n; j++) {
            if ( compare_strings(a[i], a[j]) == -1 ) {

                strcpy( b_hold, b[i]);
                strcpy( a_hold, a[i]);

                strcpy ( b[i] , b[j]);
                strcpy ( a[i] , a[j]);

                strcpy( b[j], b_hold);
                strcpy( a[j], a_hold);
            }
        }
    }

    for ( int i=0 ; i<n; i++ ){
        printf("%s\n", b[i]);
    }

    for ( int i=0; i< n; i++) {
        free(a[i]);
        free(b[i]);
    }
    free (a);
    free (b);
    return 0;
}
void delete_spaces( char * string){
    int n = strlen( string) +1;
    for ( int i=0; i< n; i++){
        if( string[i] == ' '){
            n--;
            for ( int j=i; j<n; j++){
                string[j] = string[j+1];
            }
        }
    }
}

int compare_chars( char a, char b) {
    if (a == b)
        return 0;
    int symbols_ascii[] = {95, 45, 21, 64, 41, 40, 37};

    for (int i = 0; i < 7; i++) {
        if (a == symbols_ascii[i])
            return 1;
        else if (b == symbols_ascii[i])
            return -1;
    }

    if (a > b)
        return -1;
    else
        return 1;
}

int compare_strings( char * str1, char * str2 ){
    int i=0;
    while (1 ){
        if ( i == strlen (str2) && i == strlen ( str1) )
            return 0;
        if ( i == strlen ( str1) )
            return 1;
        if ( i == strlen( str2) )
            return -1;
        if ( compare_chars( str1[i], str2[i]) == 1)
            return 1;
        if ( compare_chars( str1[i], str2[i]) == -1)
            return -1;
        else
            i++;
    }
}