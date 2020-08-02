/*思路：申请一段内存，遍历字符串S,当S[i]是空格时，字符串ans的元素赋值为%20,否则就将S中非空格元素填充到ans中*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 500000 

char* replaceSpaces(char* S, int length)
{
    int spacelength=0;
    for(int i=0;i<length;i++)
    if(S[i]==' ')
    spacelength++;
    
    char *ans = (char *)malloc(sizeof(char) * (length+spacelength*2+1));
    int i, j;
    for (i = 0, j = 0; i < length; i++) 
    {
        if (S[i] == ' ')
        {
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        } 
        else ans[j++] = S[i];
    }
    ans[j] = '\0';
    return ans;
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
	char* ret=replaceSpaces(s,i);
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
