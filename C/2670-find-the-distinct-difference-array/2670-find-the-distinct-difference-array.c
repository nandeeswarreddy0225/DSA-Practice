
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize) {
    int *ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int prefixCount = 0;
        int suffixCount = 0;

        for (int j = 0; j <= i; j++) {
            int found = 0;
            for (int k = 0; k < j; k++) {
                if (nums[k] == nums[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                prefixCount++;
            }
        }

        for (int j = i + 1; j < numsSize; j++) {
            int found = 0;
            for (int k = i + 1; k < j; k++) {
                if (nums[k] == nums[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                suffixCount++;
            }
        }

        ans[i] = prefixCount - suffixCount;
    }

    return ans;
}
