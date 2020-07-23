/*问题：循环的限制条件*/
/*思路：详见注释*/
#include "stdio.h"
#include "stdlib.h"

int search(int* nums, int numsSize, int target)
{
    int m=-1;
    int low=0,high=numsSize-1,mid;

    while(low<=high)//在下限小于或等于上限时进行循环
    {
        mid=(low+high)/2;//取中间值
        if(target<nums[mid]) high=mid-1;//上限变为mid-1
        else if(target>nums[mid]) low=mid+1;//下限变为mid+1
        else 
        {
            m=mid;//当发现目标值时取得位置并结束循环
            break;
        }
    }
    return m;
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
	
	printf("%d",search(nums,numsSize+1,target));
	
	free(nums);
	return 0;
} 
