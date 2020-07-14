/*没什么问题*/
/*如果数组为空，则返回值count为0，否则就从0开始遍历，如果第一次有元素与给定数不相等，
则第一个元素赋值为该元素，并且计数器count加1，最后返回count，输出的元素为前count个*/
#include "stdio.h"
#define Max 10000

int removeElement(int* nums, int numsSize, int val)
{
    int count=0;
    if(numsSize==0) return 0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=val)
        {
            nums[count]=nums[i];
            count++;
        }
    }
    return count;
}

int main()
{
	int nums[Max],numsSize,val;
	
	printf("输入长度:");
	scanf("%d",&numsSize);
	
	printf("输入字符串:");
	for(int j=0;j<numsSize;j++)
	scanf("%d",&nums[j]);
	
	printf("输入去除数字:");
	scanf("%d",&val);
	
	printf("输出：");
	for(int i=0;i<removeElement(nums,numsSize,val);i++)
	printf("%d ",nums[i]);
	
	return 0;
}
