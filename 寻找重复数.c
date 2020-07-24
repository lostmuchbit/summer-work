#include "stdio.h"
#include "stdlib.h"

/*思路：letf从0开始，right从numsSize-1开始，mid从numsSize/2开始，当left=right时结束循环，循环内：遍历数组，若元素比mid小或等于，则计数器count加一，遍历结束后若count大于mid则right=mid
，反之则left=mid+1，mid=（left+right）/2，循环结束后返回left*/
int findDuplicate(int* nums, int numsSize){
     int i, mid, left = 1, right = numsSize -1;
     int count = 0; 
     mid = numsSize / 2;
     while(left != right)
     {
         count = 0;
         for(i = 0; i < numsSize; i++)
             if(nums[i] <= mid) count++;

         if(count > mid)  right = mid;
         else left = mid + 1;
         
         mid = (left + right) / 2;
     }
     return left;
} 

int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	
	nums=(int*)malloc(sizeof(int)*numsSize);
	
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("%d",findDuplicate(nums,numsSize));
	
	free(nums);
	return 0;
}
