#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 50000

void reverse(char *str, int i, int j)
{
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

char * reverseWords(char * s)
{
    int left = 0;
    int right = 0;
    //遍历字符串
    while (s[right++] != '\0') {
    //如果right处于空格出或句子结尾，就可以进行单词的收尾对调
        if (s[right] == ' ' || s[right] == '\0') {
            reverse(s, left, right - 1);
            left = right + 1;
        }
    }
    return s;
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
	char* ret=reverseWords(s);
	printf("输出结果:");
	puts(ret); 
	
	free(ret);
	
	return 0;
} 
