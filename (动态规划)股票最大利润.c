#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize==0) return 0;
   int minprice=prices[0];
   int maxprofit=0;
   
   /*例：      7 1 6 3 4
     最小本金：7 1 1 1 1
	 利润：    0 0 5 5 5
	*/ 
   for(int i=0;i<pricesSize;i++)
   {
       minprice=fmin(minprice,prices[i]);//记录买股票本金最小需要多少钱 
       maxprofit=fmax(maxprofit,prices[i]-minprice);//记录最大利润 
   }
   return maxprofit;
}

int main()
{
	int ASize;
	printf("输入股票个数：");
	scanf("%d",&ASize);
	
	int* A=(int*)malloc(sizeof(int)*ASize);
	printf("输入股票金额数:");
	for(int i=0;i<ASize;i++)
	scanf("%d",&A[i]);
	
	printf("股票最大利润为%d",maxProfit( A,ASize));
	
	free(A);
	return 0;
}
