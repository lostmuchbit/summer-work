/*问题：不知道叉乘的模与顺序的关系*/ 
/*while语句输入三点，输入数字全为0则结束，循环内计算叉乘的模，大于0则逆时针，小于0则顺时针*/ 
#include "stdio.h"

int main()
{
	int x1,y1,x2,y2,x3,y3;
	printf("输入三点："); 
	
	while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		if((x1==0)&&(y1==0)&&(x2==0)&&(y2==0)&&(x3==0)&&(y3==0))//结束 
		break;
		if(((x1==x2)&&(y1==y2))||((x1==x3)&&(y1==y3))||((x2==x3)&&(y2==y3)))//防止输入重复的点 
		{
		   printf("至少有两点是同一点，重输："); 
		   continue;
		}
		
		int A=x2-x1;
		int B=y2-y1;
		int C=x3-x1;
		int D=y3-y1;
		if(A*D-B*C>0)//计算叉乘的模 
		printf("三点逆时针\n");
		else
		printf("三点顺时针\n"); 
		
		printf("输入三点："); 
	}
	return 0;
}
