#include <stdio.h>
#include <stdlib.h>

int countA = 1, countB = 0;

void countACharacters();
void countBCharacters();

int main() {
    countACharacters();
    if (countB >= countA) printf("%d. YES", 2 * countA);
    else printf("%d. NO", countA + countB);
}

void countACharacters() {
    char character;
    scanf("%c", &character);
    if (character == 'a') {
        countA++;
        countACharacters();
    } else if (character == 'b') {
        countB++;
        countBCharacters();
    }
}

void countBCharacters() {
    char character;
    scanf("%c", &character);
    if (character == 'b') {
        countB++;
        countBCharacters();
    }
}