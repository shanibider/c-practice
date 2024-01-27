#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int numSubseq(int *nums, int numsSize, int target)
{

    qsort(nums, numsSize, sizeof(int), cmpFunc);
    int result = 0;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        printf("left: [%d]  right: [%d]\n", nums[left], nums[right]);

        if (nums[left] + nums[right] <= target)
        {
            result++;
            left++;
        }
        else
        {
            right--;
        }
        printf("result: %d\n", result);
    }

    return result;
}

int main()
{
    int nums[] = {3, 1, 2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 4;
    int result = numSubseq(nums, numsSize, target);
    return 0;
}