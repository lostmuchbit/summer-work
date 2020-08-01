/*先将数组qsort排序,在相邻两个数求差，若等差则返回true，否则返回false*/
#include "stdio.h" 
#include "stdlib.h"
#include "string.h"

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize)
{   
    int x;
    int flag=1;
    qsort(arr,arrSize,sizeof(int),cmp);
    x=arr[1]-arr[0];
    for(int i=0;i<arrSize-1;i++)
    if(x!=arr[i+1]-arr[i])
    {
        flag=0;
        break;
    }
    if(flag!=0)
    return true;
    else return false;
 
}
int main()
{
	int numsSize;
	printf("输入numsSize:");
	scanf("%d",&numsSize);
	
	int* nums=(int*)malloc(sizeof(int)*numsSize);
	printf("输入数组:");
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	if(canMakeArithmeticProgression(nums, numsSize))
	printf("nums数组内元素是等差数列");
	else
	printf("nums数组内元素不是等差数列"); 
	
	free(nums);
	return 0;
}
