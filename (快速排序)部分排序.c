/*思路：若数组为空则返回-1，-1.否则用快速排序将数组排序，对比原数组与排序后的数组，返回第一个不同的元素的下标和最后一个不同的元素的下标，若并无不同的元素则返回-1，-1.*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int split(int a[], int low, int high)
{
    int i = low;
    int x = a[i]; 
     for(int j = low+1;j<=high;j++)
         if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[low], a[i]);
    return i;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
         int i = split(a, low, high);
        quicksort(a, low, i - 1);
        quicksort(a, i + 1, high);
    }
}

int* subSort(int* array, int arraySize)
{

    int *tmp = (int *)malloc(sizeof(int) * arraySize);
    memcpy(tmp, array, sizeof(int) * arraySize);

    quicksort(array,0,arraySize-1);
    int *retAns = (int *)malloc(2 * sizeof(int));
    retAns[0] = -1;
    retAns[1] = -1;

    for (int i = 0; i < arraySize; i++)
	if (array[i] != tmp[i] ) 
	{
        retAns[0] = i;
        break; 
    }
    for(int i=arraySize-1;i>=0;i--)
    if (array[i] != tmp[i])
	{
        retAns[1] = i;
        break; 	
	}
    return retAns;
} 

int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	nums=(int*)malloc(sizeof(int)*numsSize);
	
    for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	int* ret=subSort(nums,numsSize);
	
	for(int i=0;i<2;i++)
	printf("%d ",ret[i]);
	
	free(ret);
	free(nums);
	return 0；
}
