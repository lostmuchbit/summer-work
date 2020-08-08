#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int climb(int n,int *a)//每次计算的斐波拉西数列的数记录在数组中以节约时间
{
    if(a[n]!=0) return a[n];//出口
    a[n]=climb(n-1,a)+climb(n-2,a);
    return a[n];
}

int climbStairs(int n)
{ 
    if(n<0) return 0;
    if(n<=2) return n;
    int* a=(int*)calloc(n+1,sizeof(int));//申请空间
    a[1]=1;
    a[2]=2;
    return climb(n,a);
}

int main()
{
	int n;
	printf("输入n：");
	scanf("%d",&n);
	printf("%d节楼梯有%d中走法",n,climbStairs(n));
	return 0;
}
