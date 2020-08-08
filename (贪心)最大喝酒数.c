/*思路：*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int numWaterBottles(int numBottles, int numExchange)
{
    int sum=numBottles;
    int numempty=numBottles;//空瓶子
    while(numempty/numExchange!=0)//空瓶子比交换多才循环
    {
        numBottles=numempty/numExchange;//交换后又得到了酒
        numempty=numempty/numExchange+numempty%numExchange;//交换完又可以得到空瓶子
        sum+=numBottles; //喝了几瓶酒   
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
