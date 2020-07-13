/*问题：极端情况很难写清*/
/*思路：当数组为空时返回0，否则就从第一个元素开始历遍，顺序就计数器加一，直到出现逆序，计数器归0，
把计数器最大值装到max中，如果全顺序就直接把计数器值装到max中，返回nax*/
#include "stdio.h" 
#define Max 10000

int findLengthOfLCIS(int* nums, int numsSize){
    int max=0,count=1,i;//对于序列的长度，至少会达到1
    if(numsSize==0)//考虑到极端情况
    return 0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]<nums[i+1])//经过试验，相同的元素不算入递增
                count++;
        else//逆序的情况
        {
            if(count>max)
            {
                max=count;
            }
            count=1;
        }
    }
    if(count>max)//防止全部顺序，不出现逆序的情况
        max=count;
    return max;
}

int main()
{
	int nums[Max],numsSize;
	scanf("%d",&numsSize);
	
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	printf("%d",findLengthOfLCIS( nums, numsSize));
	
	return 0;
}
