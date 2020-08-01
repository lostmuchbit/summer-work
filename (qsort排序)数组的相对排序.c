#include "stdio.h"
#include "stdlib.h"

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int i, j;
    int len1 = 0;
    int len2 = 0;
    int *out_arr = NULL;
    int *tail_arr = NULL;
   
    /*若arr2的长度与arr1的长度相同，则arr2数组的元素顺序已经符合要求，返回arr2即可*/
    if (arr1Size == arr2Size)
    {
        *returnSize = arr1Size;
        return arr2;
    }

    out_arr = (int *)malloc(arr1Size * sizeof(int));
    tail_arr = (int *)malloc((arr1Size - arr2Size) * sizeof(int));

    /*把arr1中元素按照arr2中顺序装入out_arr数组中*/
    for (i = 0; i < arr2Size; i++)
        for (j = 0; j < arr1Size; j++)
            if (arr1[j] == arr2[i])
                out_arr[len1++] = arr1[j];

    //把arr1中arr2没有的元素放入tail_arr数组中
    for (i = 0; i < arr1Size; i++)
    {
        for (j = 0; j < arr2Size; j++)
            if (arr1[i] == arr2[j]) 
                break;
        
        if (j == arr2Size)
            tail_arr[len2++] = arr1[i];
    }
    
    //将tail_arr升序
    qsort(tail_arr, len2, 4, cmp);

    //将tail_arr元素放入out_arr尾部
    for (i = len1; i < arr1Size; i++)
        out_arr[i] = tail_arr[i - len1];

    free(tail_arr);
    *returnSize = arr1Size;
    
    return out_arr;
}

int main()
{
	int arr1Size,arr2Size;
	printf("输入arr1Size:");
	scanf("%d",&arr1Size);
	printf("输入arr2Size:");
	scanf("%d",&arr2Size);
	
	int* arr1=(int*)malloc(sizeof(int)*arr1Size);
	int* arr2=(int*)malloc(sizeof(int)*arr2Size);
	
    printf("输入arr1:");
    for(int i=0;i<arr1Size;i++)
	scanf("%d",&arr1[i]);
	printf("输入arr2:");
	for(int i=0;i<arr2Size;i++)
	scanf("%d",&arr2[i]);
	
	int returnSize=0;
	int* ret=relativeSortArray( arr1, arr1Size, arr2, arr2Size, &returnSize);
	printf("处理后的数组：");
	for(int i=0;i<returnSize;i++)
	printf("%d ",ret[i]);
	
	return 0;
}
