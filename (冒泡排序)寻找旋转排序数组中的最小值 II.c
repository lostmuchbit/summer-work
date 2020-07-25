/*思路：将数组冒泡升序，输出第一个元素*/
#include "stdio.h"
#include "stdlib.h"

int findMin(int* nums, int numsSize)
{
    for(int i=0;i<numsSize;i++)
    for(int j=0;j<numsSize-i-1;j++)
    if(nums[j]>nums[j+1])
    {
        int temp;
        temp=nums[j];
        nums[j]=nums[j+1];
        nums[j+1]=temp;
    }
    return nums[0];
}

int main()
{
	int *nums,target;
	int numsSize;
	scanf("%d",&numsSize);
	nums=(int*)malloc(sizeof(int)*numsSize);
	
    for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("%d",findMin(nums,numsSize));
	
	free(nums);
	return 0;
}
