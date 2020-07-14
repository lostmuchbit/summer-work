/*没什么问题*/
/*用双循环，由第一个元素开始，与后面的元素比较，若后面的元素较大，则后一个元素赋值为该元素，并结束子循环，
如果母循环确立的元素等于最大的元素，则提前结束母循环，如果数组为空，则返回0*/
#include "stdio.h"
#define Max 10000

 int removeDuplicates(int* nums, int numsSize)
{
    int i,j,k=1,max;
    max=nums[numsSize-1];
    
    if(numsSize==0) return 0;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
            if(nums[i]<nums[j])
            {
                nums[i+1]=nums[j];
                k++;
                break;
            } 
        if(nums[i]==max)
            break;
    
    }
        
    return k;
}

int main()
{
	int nums[Max],numsSize;
	
	printf("输入长度:");
	scanf("%d",&numsSize);
	
	printf("输入字符串:");
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("输出:");
	for(int j=0;j<removeDuplicates(nums,numsSize);j++)
	printf("%d",nums[j]);
	
	return 0;
	
}
