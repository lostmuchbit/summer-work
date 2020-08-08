#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int digit_root(int n)
{
    int root = 0;
    while (n)
    {
        root += n % 10;
        n /= 10;
    }
    if (root>9) return digit_root(root);
    else return root;//数字为个位数时出口
}

int main()
{
    int m;
    printf("输入m：");
    scanf("%d",&m);
    printf("%d的数字根是%d",m,digit_root(m));
    return 0;
}
