#include "stdio.h"
#include "stdlib.h"
#include "string.h"

bool lemonadeChange(int* bills, int billsSize)
{
    int five=0,ten=0;
    for(int i=0;i<billsSize;i++)
    {
        if(bills[i]==5)
        five++;
        if(bills[i]==10)
        {
            if(five>0)
            {
                ten++;
                five--;
            }
            else return false;
        } 
        if(bills[i]==20)
        {
            if(ten>0&&five>0)//若扫到20美元的，优先找出（假如有）一张10美元的零钱(贪心思想)，之后剩下的找零用5美元补足，最后判断是否有足够的5美元钞票可以找零！若没有返回false
            {
                ten--;
                five--;
            }
            else if(five>=3)
            five-=3;
            else return false;
        }
    }
    return true;
}

int main()
{
	int billsSize;
	printf("输入时收入次数billsSize:");
	scanf("%d",&billsSize);
	int* bills=(int*)malloc(sizeof(int)*billsSize);
	printf("输入每次收钱：");
	for(int i=0;i<billsSize;i++)
	scanf("%d",&bills[i]);
	lemonadeChange( bills, billsSize) ? printf("可以找开") : printf("找不开");
	free(bills);
	return 0;	
}
