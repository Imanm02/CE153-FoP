#include <stdio.h>

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++) {
        int numberOfStations, maxTeleport;
        scanf("%d %d", &numberOfStations, &maxTeleport);

        int maxReachable = 0;
        for (int j = 0; j < numberOfStations; j++) {
            int entryTime, exitTime;
            scanf("%d %d", &entryTime, &exitTime);

            if (exitTime > maxReachable) {
                maxReachable = exitTime;
            }
        }

        printf("%s\n", (maxReachable >= maxTeleport - 1) ? "YES" : "NO");
    }
    return 0;
}