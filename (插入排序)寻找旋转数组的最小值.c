/*思路：用插入排序对数组进行升序，第一个元素就是最小的数字*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int findMin(int* nums, int numsSize)
{
	for(int i=1;i<numsSize;i++)
	{
		int temp=nums[i],j;
		for(j=i-1;j>=0&&nums[j]>temp;j--)
		nums[j+1]=nums[j];
		nums[j+1]=temp;	
	}
    
    return nums[0];
}

int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	nums=(int*)malloc(sizeof(int)*numsSize);
	
    for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("%d",findMin(nums,numsSize));
	
	free(nums);
	return 0;
}
