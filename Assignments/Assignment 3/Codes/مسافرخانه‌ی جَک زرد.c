#include <stdio.h>
#include <stdlib.h>

int findMaximum(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) return num1;
    else if (num2 >= num1 && num2 >= num3) return num2;
    else return num3;
}

int findMinimum(int num1, int num2, int num3) {
    if (num1 <= num2 && num1 <= num3) return num1;
    else if (num2 <= num1 && num2 <= num3) return num2;
    else return num3;
}

int findMedium(int num1, int num2, int num3) {
    if ((num1 <= num2 && num1 >= num3) || (num1 <= num3 && num1 >= num2)) return num1;
    else if ((num2 <= num1 && num2 >= num3) || (num2 <= num3 && num2 >= num1)) return num2;
    else return num3;
}

int main() {
    float ratio1, ratio2, ratio3;
    int score1, score2, score3, minRadius, maxRadius, medRadius, numThrows, totalScore = 0;
    scanf("%f %f %f", &ratio1, &ratio2, &ratio3);

    if (ratio1 == ratio2 || ratio1 == ratio3 || ratio2 == ratio3) {
        printf("error");
    } else {
        scanf("%d %d %d", &score1, &score2, &score3);
        scanf("%d", &minRadius);

        maxRadius = minRadius * findMaximum(ratio1, ratio2, ratio3) / findMinimum(ratio1, ratio2, ratio3);
        medRadius = minRadius * findMedium(ratio1, ratio2, ratio3) / findMinimum(ratio1, ratio2, ratio3);

        scanf("%d", &numThrows);
        for (int i = 0; i < numThrows; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            int distanceSquared = x * x + y * y;

            if (distanceSquared <= minRadius * minRadius) {
                totalScore += findMaximum(score1, score2, score3);
            } else if (distanceSquared <= medRadius * medRadius) {
                totalScore += findMedium(score1, score2, score3);
            } else if (distanceSquared <= maxRadius * maxRadius) {
                totalScore += findMinimum(score1, score2, score3);
            }
        }
        printf("%d", totalScore);
    }
    return 0;
}