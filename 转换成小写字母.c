/*思路：根据ASCII表，依次遍历，把大写字母换成小写字母*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 100000

char * toLowerCase(char * str)
{
    if(str==NULL) return NULL;
    int len=strlen(str);
    for(int i=0;i<len;i++)
        if(str[i]<='Z'&&str[i]>='A')
        str[i]=str[i]-'A'+'a';
    return str;
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
	char* ret=toLowerCase(s);
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
