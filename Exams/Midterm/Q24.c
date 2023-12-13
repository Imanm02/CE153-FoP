#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toggle(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            if (!(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u'))
                s[i] = '*';
        } else if (isupper(s[i])) {
            if (!(s[i] == 'A' || s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'))
                s[i] = '*';
        }
    }
}
int main()
{
    char str[201];
    scanf("%[^\n]s", str);
    toggle(str);
    printf("%s", str);
    return 0;
}
