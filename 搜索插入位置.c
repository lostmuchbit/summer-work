/*问题：不知道如何输入未知元素数量的数组并统计元素数量*/
/*思路（函数）：如果目标小于下标为0的数则返回0，若目标大于下标为numsSize-1的数，
则返回numsSize,再进行遍历，若下标为i的数大于或等于目标，则终止循环，并返回i*/
#include "stdio.h" 
#include "string.h"
#include "stdlib.h"

int searchInsert(int* nums, int numsSize, int target)
{
    int i;
    if(target<nums[0]) return 0;
    if(target>nums[numsSize-1]) return numsSize;
    
    for(i=0;i<numsSize;i++)
        if((target<nums[i])||(target==nums[i]))
            break;
    return i;
}

int main()
{
	int *nums,numsSize=0,target;
	
	nums=(int*)malloc(sizeof(int));
	
	scanf("%d",nums+numsSize);
    while(getchar()!='\n')
    {
    	numsSize++;
    	scanf("%d",nums+numsSize);
	}
	
	scanf("%d",&target);
	
	printf("%d",searchInsert(nums,numsSize+1,target));
	
	return 0;
}
