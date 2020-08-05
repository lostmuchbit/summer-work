#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 500000 

/*从后往前遍历，从尾端第一个非空格字母开始数，到遇到空格或遍历结束时结束计数*/
int lengthOfLastWord(char * s)
{
    int len=strlen(s);
    if(len==0) return 0;
    int i=len-1;
    int count=0;
    for(i=len-1;i>=0;i--)
    {
        if(s[i]!=' ') count++;
        if(s[i]==' ' && count>0) break;
    }
    return count;
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
    s[i]='\0'; 
	printf("最后一个单词长度：%d",lengthOfLastWord(s));

	return 0;
} 
