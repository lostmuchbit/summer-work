#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int fib(int n)
{
    int ret;
    if(n<=1) return n;
    else
    ret=(fib(n-1)+fib(n-2))%10000000007;
    return ret;
}

int main()
{
	int n;
	printf("输入n：");
	scanf("%d",&n);
	printf("斐波拉西数列第%d个数是%d",n,fib(n));
	return 0;
}
