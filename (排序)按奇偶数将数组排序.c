/*思路：让偶数部分下标 i 之前的所有数都是偶数。为了实现这个目标，把奇数部分作为暂存区，不断增加指向奇数部分的指针，直到找到一个偶数，然后交换指针 i，j 所指的数*/
#include "stdio.h" 
#include "stdlib.h"
#include "string.h"

int* sortArrayByParityII(int* A, int ASize, int* returnSize){

    int i=0, j=1;
    for (i=0; i<ASize; i+=2)
    {
        while (j < ASize && A[j] % 2 == 1)
          { j += 2;} 

        if (j >= ASize)
            break;

        if (A[i] % 2 == 1)
        {
            int temp;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }

    *returnSize = ASize;
    return A;
}

int main()
{
	int numsSize;
	printf("输入numsSize:");
	scanf("%d",&numsSize);
	
	int* nums=(int*)malloc(sizeof(int)*numsSize);
	printf("输入数组:");
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	int returnSize=0;
	int* ret= sortArrayByParityII(nums,numsSize,&returnSize);
	printf("输出数组：");
	for(int i=0;i<returnSize;i++)
	printf("%d ",ret[i]); 
	
	free(nums);
	free(ret);
	return 0;
}
