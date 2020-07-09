/*问题：康托展开式中an的确立*/
/*思路：while语句输入元素并记录元素的个数，分别求得元素的排序，如第一个元素需要和剩下的n-1个比较，
第二个元素需要和剩下的n-2个比较，第三个元素需要和剩下的n-3个元素进行比较等等，确立an，再乘上阶乘即可*/
#include "stdio.h" 
#define Max 100
 
//递归求阶乘
int fun(int num)
{
	if(num <= 1)
		return 1;//直到num<=1递归结束 
	else
		return (fun(num-1)*num);
}
 
int main()
{
	int num[Max];
	char s[Max];
	int i=0,j=0,k=0,count=0;
	char val;
	int sum = 0;
 
	while(scanf("%c",&val))
	{
		if(val == '\n')
			break;//输入回车则结束循环 
		else
		{
			s[count] = val;
			count ++;
		}
	}

 
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(s[i]>s[j])
			{
				k ++;
			}
			
		}
		num[i] = k;
		k = 0;
	}
	
	for(j=count-1;j>=0;j--)
	{
		sum += fun(j) * num[k];
		k++;
	}
	printf("是第%d大数\n",sum+1);//sum是该数前面有多少个数 
 
	return 0;
