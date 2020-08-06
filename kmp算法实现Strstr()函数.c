#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 1000

void CalcNext(char* p, int next[])
{
    int nLen = (int)strlen(p);
    next[0] = -1;
    int k = -1; //k表示next[j-1];
    int j = 0;
    while (j < nLen - 1)
    {
        if (k == -1 || p[j] == p[k]) //如果相等
        {
            ++k;
            ++j;
            next[j] = k;//next[j+1]=k+1;
        }
        //不相等，去找next[k]
        else
        k = next[k];
    }
}

int strStr(char * haystack, char * needle)
{
   if(needle[0]=='\0') return 0;

   int p_len = (int)strlen(needle);
   int t_len = (int)strlen(haystack);
   int* n;
   n = (int*)malloc(sizeof(int) * p_len);
   CalcNext(needle, n);
   int i = 0;
   int j = 0;
   int ans = -1;
   while (i < t_len)
   {
        if (j == -1 || haystack[i] ==needle[j])
        {
            ++i;
            ++j;
        }
        else
        j = n[j];

        if (j == p_len)
        {
           ans = i - p_len;
           break;
        }
    }
    return ans;
}

int main()
{
	char s[Max],k[Max],val,i=0,j=0;
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
	printf("输入字符串："); 
	while(scanf("%c",&val))
	{
		if(val!='\n')
		{
		    k[j]=val;
		    j++;	
		}
		else
		break;
	}
	k[j]='\0';
	printf("输出结果:%d",strStr(s,k));
	
	return 0;
} 
