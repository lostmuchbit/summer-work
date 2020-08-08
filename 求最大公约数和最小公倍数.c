#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int gcd(int m,int n)
{
                //出口
    return m%n==0 ? n : gcd(n,m%n);
}

int main()
{
    int m,n,k;
    printf("输入m和n:");
    scanf("%d%d",&m,&n);
    k=gcd(m,n);
    printf("%d与%d最大公约数：%d\n",m,n,k);
    printf("%d与%d最小公倍数：%d\n",m,n,m*n/k);
    return 0;
}
