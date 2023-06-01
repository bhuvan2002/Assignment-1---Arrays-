#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int index;
    while ((index = findIndex(nums, numsSize, val)) != -1) {
        for (int i = index; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        numsSize--;
    }
    return numsSize;
}

int findIndex(int* nums, int numsSize, int val) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = removeElement(nums, numsSize, val);
    printf("The value of K = %d\n", result);
    return 0;
}
