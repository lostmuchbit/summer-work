/*思路：一次遍历字符串，每相邻的两个字符相同则计数器count加1，，不相同则count归为1，再比较max与count大小，若max较小，则把count值赋给max，遍历完后返回max*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 500

int maxPower(char * s)
{
    int count=1,max;
    int i=1;
    max=count;
    while(s[i]!='\0')
    {
         if(s[i-1]==s[i])
        count++;
        else
        count=1;
        if(max<count) max=count;
        i++;
    }
    return max;
} 

int main()
{
	char s[Max],val,i=0;
	printf("输入字符串："); 
	while(scanf("%c",&val))
	{
		if(val!='\n')
		{
		    s[i]=val;
		    i++;	
		}
		else
		break;
	}
	printf("输出结果:");
	printf("%d", maxPower( s));
	
	return 0;
} 
