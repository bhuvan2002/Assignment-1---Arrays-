#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    char* numStr = malloc(digitsSize + 1);
    for (int i = 0; i < digitsSize; i++) {
        numStr[i] = digits[i] + '0';
    }
    numStr[digitsSize] = '\0';
    long long bigint = atoll(numStr);
    bigint++;
    int count = 0;
    long long temp = bigint;
    while (temp > 0) {
        temp /= 10;
        count++;
    }  
    int* result = malloc(count * sizeof(int));
    *returnSize = count;
    for (int i = count - 1; i >= 0; i--) {
        result[i] = bigint % 10;
        bigint /= 10;
    }

    free(numStr);
    return result;
}

int main() {
    int digits[] = {1, 2, 3};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);

    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("The new array after the increment is: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
