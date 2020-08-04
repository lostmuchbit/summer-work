#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h" 

#define Max 500

char* compressString(char* S)
{
    int len=strlen(S);
    
    if(len==1||len==2) return S;
    
    char *res=(char*)malloc(sizeof(char)*(2*len));
    int i,j,k=0;
    
    for(i=j=0;i<len;)
	{
        res[k++]=S[i];
        while(j<len&&S[i]==S[j]) j++;
        int temp=j-i;   //计算字符个数
        int c=log10(temp)+1;    //计算字符重复数的位数
        k=k+c-1;
        while(temp)
		{
            res[k--]=temp%10+'0';   //从个位开始赋值
            temp/=10;
        }
        k=k+c+1;    //重新定位k
        i=j;
    }
    
    res[k]='\0';
    
    int len_res=strlen(res);
    if(len_res<len) return res;
    
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
	char* ret=compressString(s);
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
