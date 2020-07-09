/*问题：排除已确立位置的元素而进行下一步操作，即get函数是真的难想*/
/*思路：以while循环语句输入一段数列的元素，并确立元素的个数，再用冒泡排序确保元素从大到小排列，用递归求出阶乘，进而求出商和余数，
精妙之处在get函数，每次把测试过的数放到数列后端，使已确立的元素不会再被测试，即排除，并逐一输出*/
 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Max 100
 
//递归求阶乘
int JieCheng(int num)
{
	int i=1;
 
	if(num <= i)
		return 1;
	else
		return (num*JieCheng(num-1));
}
 
//打印s[]中第num大的元素，找到第num大的元素，对于下标大于num的元素则向前移动一个
void get(int num,char s[],int length)
{
	int j=0;
	for(j=0;j<length;j++)
	{
		if(j==num)
			printf("%c",s[j]);
		if(j>num)
		{
			s[j-1] = s[j];
		}
	}
}

//冒泡对输入的元素升序排序 
void Bubble_sort(char *a,int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=0;j<n-i-1;j++)
	if(a[j]>a[j+1])
	{
		int tmp;
		tmp=a[j];
		a[j]=a[j+1];
		a[j+1]=tmp;
	}
}
 
int main()
{
	char val;		//临时存储元素
	char s[Max];	
	int x;			
 
	int r[Max];		//存储余数
	int p[Max];		//存储商
 
	int i=0,j=0,k=0;
 
	printf("请输入s的集合：");
	while(scanf("%c",&val))//输入元素 
	{
		if(val == '\n')
			break;
		else
		{
			s[i] = val;
			i++;//记录元素个数 
		}	
	}
	Bubble_sort(s,i);
	
	printf("请输入X的值：");
	scanf("%d",&x);//输入数列是第几个 
 
	//循环求p,r
	for(j=i-1;j>=0;j--)//辗转相除 
	{
		p[k] = x/(JieCheng(j));//求商 
		r[k] = x%(JieCheng(j));//求余 
		x = r[k];
		k++;
	}
	//输出结果
	for(j=0;j<i;j++)
	{
		get(p[j],s,i);
	}
	printf("\n");
 
	return 0;
} 
