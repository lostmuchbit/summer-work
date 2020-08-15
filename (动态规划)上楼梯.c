#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int waysToStep(int n)
{
    switch(n)
    {
        case 1: return 1;break;
        case 2: return 2;break;
        case 3: return 4;break;
        default:;
    }
    int* dp=(int*)malloc(sizeof(int)*n);
    dp[0]=1;
    dp[1]=2;
    dp[2]=4;
    for(int i=3;i<n;i++)
    dp[i]=((dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007+dp[i-3]%1000000007)%1000000007;//取模来防止溢出很关键 
    //dp[i]=dp[i-1]+dp[i-2]+dp[i-3]；这是一个类似斐波拉西数列的式子； 
    return dp[n-1];
}

int main()
{
	int n;
	printf("输入阶梯数:");
	scanf("%d",&n);
	printf("%d节楼梯有%d种上楼的方法",n,waysToStep(n));
	return 0;
}
