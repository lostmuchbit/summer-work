#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 5000 

bool isSubsequence(char * s, char * t)
{
    int i=0,j=0;
    while(i<strlen(s) && j<strlen(t))//每次优先验证靠前的元素，即贪心
    {
        if(s[i]==t[j])
        i++;
        j++;
    }
    return i==strlen(s) ? true :false;
}

int main() 
{
	char s[Max],t[Max],val,i=0,j=0;
	printf("输入字符串s："); 
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
	printf("输入字符串t："); 
	while(scanf("%c",&val))
	{
		if(val!='\n')
		{
		    s[j]=val;
		    i++;	
		}
		else
		break;
	}
	s[j]='\0';
	
	if(isSubsequence(s,t)) printf("有");
	else printf("无"); 
	
	return 0;
}
