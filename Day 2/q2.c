#include <stdio.h>

int distributeCandies(int* candyType, int candyTypeSize) {
    int maxCandies = candyTypeSize / 2;
    int uniqueCandies = 0;

    int* candyMap = (int*)calloc(200001, sizeof(int));

    for (int i = 0; i < candyTypeSize; i++) {
        if (candyMap[candyType[i] + 100000] == 0) {
            uniqueCandies++;
            candyMap[candyType[i] + 100000] = 1;
        }
    }

    free(candyMap);

    return (maxCandies < uniqueCandies) ? maxCandies : uniqueCandies;
}

int main() {
    int candyType[] = {1, 1, 2, 2, 3, 3};
    int candyTypeSize = sizeof(candyType) / sizeof(candyType[0]);

    int numCandies = distributeCandies(candyType, candyTypeSize);
    printf("Number of candies to be distributed: %d\n", numCandies);

    return 0;
}
