/*总的来说没什么问题，可能就是不记得欧几里得算法是什么了*/
/*思路：用if语句使a始终为较大数，b为较小数，再在while语句中循环（辗转相除），余数为0就结束，此时输出的ab即为最大公约数*/
#include "stdio.h"

int main()
{
	int a,b,c,r;
	scanf("%d%d",&a,&b);//输入两个数
	
	if(a>=b)//比较a,b大小
	{
            while(a%b!=0)//只要a除以b有余数就继续进行
	   {
		  r=a%b;//欧几里得算法内容
		  a=b;
		  b=r;
	   }
	}
	else
	{
	   c=a;a=b;b=c;//让大的数为a，小的数为b
	   while(a%b!=0)
	   {
		  r=a%b;
		  a=b;
		  b=r;
	   } 
	}
	
	printf("%d",r);//输出最大公约数
	return 0;
	
} 
