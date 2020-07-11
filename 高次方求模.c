/*问题：指数项为奇数时操作*/
/*利用递归实现n^p%M=(((n%m)^2)%M)·····*/ 

#include "stdio.h" 
 
int PowMod(int n, int p,int M)
{
	if (p == 1)//确立边界 
	{
		return n % M;
	}
	int temp = PowMod(n, p/2,M);//由于p为奇数时，p/2有误差，p为int，故例：p=5,p/2=2 
	int result = (temp*temp) % M;
	if (p % 2 == 1)//p为奇数时 
	{
		result = (result*n) % M;//result需乘n 
	}
	return result;
}

int main()
{
	int n,p,M;
	scanf("%d%d%d",&n,&p,&M);
	
	printf("%d",PowMod(n,p,M));
	return 0;
}
