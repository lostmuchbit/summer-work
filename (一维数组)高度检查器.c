/*没有问题*/
/*思路：冒泡排序使数组升序，再比较原数组与后数组相同位置的数字，不一样则计数器加一*/

#include "stdio.h"
#define Max 100

void maopao(int* heights, int heightsSize)
{
	for(int i=0;i<heightsSize;i++)
	for(int j=0;j<heightsSize-i-1;j++)
	if( heights[j]>heights[j+1])
	{
		int temp;
		temp=heights[j];
		heights[j]=heights[j+1];
		heights[j+1]=temp;
	}
}
 
int heightChecker(int* heights, int heightsSize)
{
	int a[Max],count=0;
    for(int i=0;i<heightsSize;i++)
    a[i]=heights[i];
    
    maopao(heights,heightsSize);
    
    for(int j=0;j<heightsSize;j++)
    {
    	if(a[j]!=heights[j])
    	count++;
	}
	return count;
}

int main()
{
	int heights[Max],heightsSize;
	
	printf("输入字符串长度:");
	scanf("%d",&heightsSize);
	
	printf("输入字符串:");
	for(int i=0;i<heightsSize;i++)
	scanf("%d",&heights[i]);
	
	printf("需要调换%d人",heightChecker(heights,heightsSize));
	
	return 0;
	
}
