#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main() {
    // Test case
    int nums[] = {1, 1, 2, 2, 3, 4, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Array before removing duplicates: \n ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    printf(" %d\n ");

    int k = removeDuplicates(nums, numsSize);

    // Output
    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
