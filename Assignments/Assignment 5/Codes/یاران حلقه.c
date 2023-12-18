#include <stdio.h>

int main() {
    unsigned int numPlayers, currentPlayer = 1, remainingMoves = 1;
    scanf("%u", &numPlayers);
    unsigned int players[numPlayers];

    for (unsigned int i = 0; i < numPlayers; i++) {
        players[i] = i + 1;
    }

    while (remainingMoves < numPlayers) {
        for (unsigned int i = 0; i < numPlayers; i++) {
            if (players[i] != 0) {
                currentPlayer = !currentPlayer;
                if (currentPlayer) {
                    players[i] = 0;
                    remainingMoves++;
                }
            }
        }
    }

    for (unsigned int i = 0; i < numPlayers; i++) {
        if (players[i] != 0) {
            printf("%u", players[i]);
            break;
        }
    }

    return 0;
}