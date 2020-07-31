/*思路：若数组为空则返回-1，-1.否则用选择排序将数组排序，对比原数组与排序后的数组，返回第一个不同的元素的下标和最后一个不同的元素的下标，若并无不同的元素则返回-1，-1.*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void sort(int* nums, int numsSize)
{
    for(int i=0;i<numsSize;i++)
    {
    	int j,temp=nums[i];
		for(j=i-1;j>=0&&nums[j]>temp;j--)
		nums[j+1]=nums[j];
		nums[j+1]=temp;			
	}
}

int* subSort(int* array, int arraySize)
{

    int *tmp = (int *)malloc(sizeof(int) * arraySize);
    memcpy(tmp, array, sizeof(int) * arraySize);

    sort(array,arraySize);
    int *retAns = (int *)malloc(2 * sizeof(int));
    retAns[0] = -1;
    retAns[1] = -1;

    for (int i = 0; i < arraySize; i++)
	if (array[i] != tmp[i] ) 
	{
        retAns[0] = i;
        break; 
    }
    for(int i=arraySize-1;i>=0;i--)
    if (array[i] != tmp[i])
	{
        retAns[1] = i;
        break; 	
	}
    return retAns;
} 

int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	nums=(int*)malloc(sizeof(int)*numsSize);
	
    for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	int* ret=subSort(nums,numsSize);
	
	for(int i=0;i<2;i++)
	printf("%d ",ret[i]);
	
	free(ret);
	free(nums);
	return 0;
}
