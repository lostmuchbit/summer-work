/*思路：对数组快速排序升序，字符串和数组对应，字符串也就正常了*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h" 

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Swap(char &a,char &b)
{
	char t=a;
	a=b;
	b=t;
}

//划分数组的函数
int split(char *s,int *a, int low, int high)
{
    int i = low;//i指向比较元素的期望位置
    int x = a[i]; //将该数组第一个元素设置为比较元素
     //从数组的第二个元素起开始遍历，若找到的元素大于比较元素，则跳过
    for(int j = low+1;j<=high;j++)
  //若找到了小于比较元素的数，则将其与前面较大的数进行交换
    if (a[j] <= x)
    {
        i++;
        swap(a[i], a[j]);
        Swap(s[i],s[j]);
    }
    swap(a[low], a[i]); //将比较元素交换到期望位置
    Swap(s[low],s[i]); 
	return i;
}

//快速排序
void quicksort(char *s,int *a, int low, int high)
{
    if (low < high)
    {
        int i = split(s,a, low, high); //划分数组并获得比较元素位置
        quicksort(s,a, low, i - 1); //对比较元素左边进行排序
        quicksort(s,a, i + 1, high); //对比较元素右边进行排序
    }
}

int main()
{
	int indicesSize;
	char* s=(char*)malloc(sizeof(int));
	printf("字符串："); 
	scanf("%s",s);
	indicesSize=strlen(s);
	int* indices=(int*)malloc(sizeof(int)*(indicesSize));
	printf("数组:");
	for(int i=0;i<indicesSize;i++)
	scanf("%d",&indices[i]);
	
	quicksort( s, indices, 0,indicesSize-1);
	printf("%s",s);
	
	return 0;
	
} 
