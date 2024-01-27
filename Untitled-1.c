int cmpFunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int numSubseq(int* nums, int numsSize, int target){

    qsort(nums, numsSize, sizeof(int), cmpFunc);
    int result = 0;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right){
        if (nums[left] + nums[right] <= target){
            result++;
            left++;
        }
        else{
            right--;
        }
    }

    return result;
}