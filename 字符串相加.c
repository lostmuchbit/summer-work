/*思路： 设定 i，j 两指针分别指向 num1，num2 尾部，模拟人工加法；

计算进位： 计算 carry = tmp // 10，代表当前位相加是否产生进位；
添加当前位： 计算 tmp = n1 + n2 + carry，并将当前位 tmp % 10 添加至 res 头部；
索引溢出处理： 当指针 i或j 走过数字首部后，给 n1，n2 赋值为 00，相当于给 num1，num2 中长度较短的数字前面填 00，以便后续计算。
当遍历完 num1，num2 后跳出循环，并根据 carry 值决定是否在头部添加进位 11，最终返回 res 即可
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Max 500000 

char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? (len1 + 1) : (len2 + 1);
    int i = len1 - 1;
    int j = len2 - 1;
    int k = len - 1;
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    memset(res, 0, sizeof(char) * (len + 1));
    res[0] = '0';
    
    int carry = 0;
    int num = 0;
    while(i >= 0 || j >= 0 || carry){
        num = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
        num += carry;
        carry = 0;
        if (num > 9) {
            carry = 1;
            num = num - 10;
        }
        res[k] = num + '0';
        k--;
        i--;
        j--;
    }

    if (res[0] == '0')
        res = res + 1;
    return res;
}

int main()
{
	char num1[Max],num2[Max],val,i=0,j=0;
	printf("输入字符串："); 
	while(scanf("%c",&val))
	{
		if(val!='\n')
		{
		    num1[i]=val;
		    i++;	
		}
		else
		break;
	}
	num1[i]='\0';
	printf("输入字符串："); 
	while(scanf("%c",&val))
	{
		if(val!='\n')
		{
		    num2[j]=val;
		    j++;	
		}
		else
		break;
	}
	num2[j]='\0';
	char* ret=addStrings(num1,num2); 
	printf("输出结果:");
	puts(ret);
	
	free(ret);
	
	return 0;
} 
