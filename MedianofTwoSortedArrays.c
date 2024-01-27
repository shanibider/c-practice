#include <stdio.h>
#include <stdlib.h>

int cmpr(void const *a, void const *b)
{
    return (*(int *)a - *(int *)b);
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

    int *mergedArr = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0;

    for (i = 0; i < nums1Size; i++)
    {
        mergedArr[i] = nums1[i];
    }

    for (int j = 0; j < nums2Size; j++)
    {
        printf("Hit\n");
        mergedArr[i] = nums2[j];
        i++;
    }

    int mSize = i;
    printf("Size: %d\nmergedArr: ", mSize);

    for (i = 0; i < mSize; i++)
    {
        printf("%d ", mergedArr[i]);
    }

    qsort(mergedArr, mSize, sizeof(int), cmpr);

    printf("\nAfter: ");
    for (i = 0; i < mSize; i++)
    {
        printf("%d ", mergedArr[i]);
    }

    double result;

    if (mSize % 2 != 0)
    {
        result = mergedArr[mSize / 2];
        return result;
    }
    else
    {
        result = (mergedArr[mSize / 2] + mergedArr[(mSize / 2) - 1]);
        result /= 2;
        return result;
    }
}

int main()
{

    int arr1[2] = {1, 3};
    int arr2[1] = {2};

    printf("Result: %f", findMedianSortedArrays(arr1, 2, arr2, 1));
}