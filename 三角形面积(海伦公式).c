/*没有问题*/
/*用double定义边长，半周长，面积，再依据海伦公式*/ 
#include "stdio.h"
#include "math.h"

int main()
{
	double a,b,c,p,t;
	
	printf("输入三角形三条边：\n");
	while(scanf("%lf%lf%lf",&a,&b,&c)！=EOF)
	{
      p=(a+b+c)/2;
	    t=p*(p-a)*(p-b)*(p-c);
	    printf("面积：%lf",sqrt(t));
  }
	return 0; 
} 
