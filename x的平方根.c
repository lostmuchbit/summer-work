/*问题：二分查找法的操作*/
/*思路：如果x小于0，则返回-1，表示实数范围内求不了，如果0<=x<=1则返回x,再二分查找，直至循环结束，返回low*/
#include "stdio.h"
#include "stdlib.h"

 int mySqrt(int x)
{
    int low=0;//定义下限
    int high=x;//定义上线
    int mid=0;//中值

    if(x<0) return -1;
    else if(x<=1) return x;
    else
        while(low+1<high)
        {
            mid=(low+high)/2;
            if(x/mid<mid)
            high=mid;
            else
            low=mid;
        }
    return low;
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d",mySqrt(x));
        
    return 0;
}
