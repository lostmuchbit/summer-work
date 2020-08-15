/*转移方程：
dp[i-2]+nums[i]>dp[i-1]时dp[i]=dp[i-2]+nums[i],反之则dp[i]=dp[i-1];*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int rob(int* nums, int numsSize)
{
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    int* dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=nums[0];
    dp[1]=fmax(nums[0],nums[1]);
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=fmax(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[numsSize-1];
}

int main()
{
	int ASize;
	printf("输入住户个数：");
	scanf("%d",&ASize);
	
	int* A=(int*)malloc(sizeof(int)*ASize);
	printf("输入住户钱数:");
	for(int i=0;i<ASize;i++)
	scanf("%d",&A[i]);
	
	printf("小偷打家劫舍最大金额为%d",rob( A,ASize));
	
	free(A);
	return 0;
}
