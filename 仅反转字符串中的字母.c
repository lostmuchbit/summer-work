#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 1000

/*left从0开始，right从最后开始，同时向中遍历，当都是字母时交换彼此，不是字母则跳过*/
char * reverseOnlyLetters(char * S)
{
    if(S==NULL) return NULL;
    int left=0,right=strlen(S);
    while(left<=right)
    {
        if((S[left]<='z'&&S[left]>='a')||(S[left]>='A'&&S[left]<='Z'))
        {
            if((S[right]<='z'&&S[right]>='a')||(S[right]>='A'&&S[right]<='Z'))
            {
                char ch;
                ch=S[left];
                S[left]=S[right];
                S[right]=ch;
                left++;
                right--;
            }
            else right--;
        }
        else left++;
    }
    return S;
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
	char* ret=reverseOnlyLetters(s);
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
