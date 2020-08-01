#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    /*判断数组nums是否为空，若为空则返回空*/
    if(nums==NULL) return NULL;
    
    int* ret=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    
    /*将数组ret中所有元素赋值为0，防止出现边界问题*/
    memset(ret,0,sizeof(int)*numsSize);

    int j=0;
    for(int i=0;i<numsSize;i++)
    {   
        /*将nums的前n个元素装入ret的复数下标位置，后n个元素装入ret的奇数下标位置*/
        if(i<n)  
        ret[2*i]=nums[i];
        else
        {
            ret[2*j+1]=nums[i];
            j++;
        }
    }
    return ret;
}

int main()
{
	int n;
	printf("输入n:");
	scanf("%d",&n);
	
	int* nums=(int*)malloc(sizeof(int)*(2*n));
	printf("输入数组:");
	for(int i=0;i<2*n;i++)
	scanf("%d",&nums[i]);
	
	int returnSize=0;
	int* ret=shuffle(nums,2*n,n,&returnSize);
	printf("输出数组：");
	for(int i=0;i<returnSize;i++)
	printf("%d ",ret[i]); 
	
	free(nums);
	free(ret);
	return 0;
}
