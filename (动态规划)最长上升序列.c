#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

/*定义 dp[i]dp[i] 为考虑前 i个元素，以第 i个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取。

我们从小到大计算 dp[]dp[] 数组的值，在计算 dp[i]之前，我们已经计算出 dp[0...i-1] 的值，则状态转移方程为：

dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]

即考虑往 dp[0 ...i-1]中最长的上升子序列后面再加一个 nums[i]。由于 dp[j]代表nums[0…j] 中以 nums[j] 结尾的最长上升子序列，所以如果能从 dp[j]这个状态转移过来，
那么 nums[i] 必然要大于nums[j]，才能将nums[i] 放在nums[j] 后面以形成更长的上升子序列。

最后，整个数组的最长上升子序列即所有dp[i] 中的最大值。

*/ 
int lengthOfLIS(int* nums, int numsSize)
{
    if(numsSize==0) return 0;
    int* dp=(int*)malloc(sizeof(int)*numsSize);
    memset(dp,1,sizeof(int)*numsSize);

    int maxans=1;
    for(int i=0;i<numsSize;i++)
    {
        int maxval=0;
        for(int j=0;j<i;j++)
        if(nums[i]>nums[j])
        maxval=fmax(maxval,dp[j]);
        dp[i]=maxval+1;
        maxans=fmax(maxans,dp[i]);
    }
    free(dp);
    return maxans;
}

int main()
{
	int ASize;
	printf("输入数组元素个数：");
	scanf("%d",&ASize);
	
	int* A=(int*)malloc(sizeof(int)*ASize);
	printf("输入数组:");
	for(int i=0;i<ASize;i++)
	scanf("%d",&A[i]);
	
	printf("最长上升序列长度为%d",lengthOfLIS( A,ASize));
	
	free(A);
	return 0;
}
