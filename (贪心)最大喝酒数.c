#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int numWaterBottles(int numBottles, int numExchange)
{
    int sum=numBottles;
    int numempty=numBottles;
    while(numempty/numExchange!=0)
    {
        numBottles=numempty/numExchange;
        numempty=numempty/numExchange+numempty%numExchange;
        sum+=numBottles;    
    }
    return sum;
}

int main()
{
    int m,n;
    printf("输入m和n:");
    scanf("%d%d",&m,&n);
    printf("最多可以喝%d瓶酒",numWaterBottles(m,n));
   
    return 0;
}
