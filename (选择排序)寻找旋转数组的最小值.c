#include "stdio.h"
#include "stdlib.h"

int findMin(int* nums, int numsSize)
{
	int index,i,j;
    for(i=0;i<numsSize-1;i++)
    {
    	int temp;
    	index=i;
        for(j=i+1;j<numsSize-1;j++)
        if(nums[j]>nums[j+1])
		index=j+1;
		temp=nums[i];
		nums[i]=nums[index];
		nums[index]=temp;			
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
