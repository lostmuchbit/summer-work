#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

double myPow(double x, int n)
{
    double res = 1.0;
    switch(n)
    {
        case 0:
            return res;
        case 1:
            return x;//出口
        case -1:
            return res/x;
        default:
            res = myPow(x, n/2)*myPow(x,n/2);
            return res * myPow(x, n % 2);
    }
}

int main()
{
	int n;
	double x; 
	printf("输入x和n:");
	scanf("%lf%d",&x,&n);
	printf("x的n次幂：%lf",myPow(x,n));
	return 0;
}
