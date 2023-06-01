#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int key;
    int value;
};

int compare(const void* a, const void* b) {
    struct Pair* pairA = (struct Pair*)a;
    struct Pair* pairB = (struct Pair*)b;

    return pairA->key - pairB->key;
}

int findLHS(int* nums, int numsSize) {
    struct Pair* map = (struct Pair*)malloc(numsSize * sizeof(struct Pair));
    int mapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int foundIndex = -1;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].key == nums[i]) {
                foundIndex = j;
                break;
            }
        }

        if (foundIndex != -1) {
            map[foundIndex].value++;
        } else {
            map[mapSize].key = nums[i];
            map[mapSize].value = 1;
            mapSize++;
        }
    }

    qsort(map, mapSize, sizeof(struct Pair), compare);

    int max = 0;

    for (int i = 1; i < mapSize; i++) {
        if (map[i].key == map[i - 1].key + 1 && map[i].value + map[i - 1].value > max) {
            max = map[i].value + map[i - 1].value;
        }
    }

    free(map);

    return max;
}

int main() {
    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int longestSubsequence = findLHS(nums, numsSize);
    printf("The longest harmonious subsequence length is %d\n", longestSubsequence);

    return 0;
}
