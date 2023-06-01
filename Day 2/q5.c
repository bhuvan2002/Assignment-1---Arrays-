#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int numA = *(int*)a;
    int numB = *(int*)b;

    return numB - numA;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int positiveProduct = nums[0] * nums[1] * nums[2];
    return positiveProduct;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int maxProduct = maximumProduct(nums, numsSize);
    printf("The maximum product of three numbers is %d\n", maxProduct);

    return 0;
}
