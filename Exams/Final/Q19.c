#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toggle(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        } else if (isupper(s[i])) {
            s[i] = tolower(s[i]);
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
