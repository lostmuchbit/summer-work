#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 10000

int balancedStringSplit(char * s)
{
    int balance=0,count=0;;
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])//在balance=0时截断字符串不会影响整体，达到局部完成题目目的（贪心思想） 
        {
            case 'L':balance++;break;
            case 'R':balance--;break;
            default:;
        }
        if(balance==0) count++; 
    }
    return count;
}

int main()
{
	char s[Max];
	printf("输入字符串：");
	scanf("%s",s);
	printf("有%d个平衡子字符串",balancedStringSplit(s));
	return 0;
}
