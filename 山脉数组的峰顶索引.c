/*思路：定义下限为0，上限为最后一个下标，当上限大于下限时进行循环：mid等于上下限和的一半，如果A[mid*]<A[mid+1],则向mid右侧探索，反之则向mid左侧探索/
#include "stdio.h"
#include "stdlib.h"

int peakIndexInMountainArray(int* A, int ASize)
{
    int low = 0, high= ASize - 1;
        while (low< high) {
            int mid = low + (high - low) / 2;
            if (A[mid] < A[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
}

int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	
	nums=(int*)malloc(sizeof(int)*numsSize);
	
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("%d",peakIndexInMountainArray(nums,numsSize));
	
	free(nums);
	return 0;
}
