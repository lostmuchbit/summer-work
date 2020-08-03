#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 500

char * reverseStr(char * s, int k){
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        int left = i;
        int right = (i + k - 1 < len) ? i + k - 1 : len - 1; //是否超界？
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
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
	int k;
	printf("输入k:");
	scanf("%d",&k); 
	char* ret=reverseStr(s,k);
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
