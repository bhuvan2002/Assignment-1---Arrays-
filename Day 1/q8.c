#include <stdio.h>
#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int len = numsSize;
    int* result = (int*)malloc(2 * sizeof(int));

    int sum = (len * (len + 1)) / 2;
    int s = 0, a = 0;

    int* obj = (int*)calloc(len + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (obj[nums[i]] == 1) {
            a = nums[i];
        } else {
            obj[nums[i]] = 1;
            s += nums[i];
        }
    }

    result[0] = a;
    result[1] = sum - s;

    *returnSize = 2;
    free(obj);
    return result;
}

int main() {
    int nums[] = {1, 2, 2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* result = findErrorNums(nums, numsSize, &returnSize);

    printf("The error numbers are: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
