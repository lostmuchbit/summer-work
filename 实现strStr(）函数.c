/*思路：用malloc申请空间输入数组，用strlen函数统计数组长度；如果needle为空则返回0，反之则从第一个元素开始遍历，若出现符合要求（详情见注释）*/
#include "stdio.h"
#include "string.h" 
#include "stdlib.h"

#define Max 100
 
int strStr(char * haystack, char * needle)
{
    int haystackSize=strlen(haystack);
    int needleSize=strlen(needle);
    int i=0,j=0;
    if(needleSize==0) return 0;//needle数组为空则返回0
    while((i<haystackSize)&&(j<needleSize))//两个数组都要遍历
    {
        if(haystack[i]==needle[j])//如果下标为i的元素和下标为j的元素相同
        {i++;j++;}//就测下标为i+1的元素和下标为j+1的元素是否相等
        else {i=i-j+1,j=0;}//如果下标为i的元素和下标为j的元素不相同，则就测下标为i-j+1的元素和下标为0的元素是否相等
    }
    if(j==needleSize) return i-needleSize;//如果haystack中含有needle则返回从第几个元素开始相同
    else return -1;//如果haystack中含有needle则返回-1
}

int main()
{
	char *haystack,*needle;
	
	haystack=(char *)malloc(sizeof(char));
	scanf("%s",haystack);
	
	needle=(char *)malloc(sizeof(char));
	scanf("%s",needle);
	
	printf("%d",strStr(haystack,needle));
	
	return 0;
}
