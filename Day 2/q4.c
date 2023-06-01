#include <stdio.h>

int canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1) continue;

        if ((i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            n--;
        }
    }

    return n <= 0;
}

int main() {
    int flowerbed[] = {1, 0, 0, 0, 1};
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int n = 1;

    int canPlace = canPlaceFlowers(flowerbed, flowerbedSize, n);
    if (canPlace) {
        printf("You can place the flowers in the flowerbed.\n");
    } else {
        printf("You cannot place the flowers in the flowerbed.\n");
    }

    return 0;
}
