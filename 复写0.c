/*思路：从第一个元素开始遍历，到倒数第二个元素结束，如果元素不为0，则结束本次循环，如果为0，则后面的元素都后移一位，下标为i+1的元素写为0*/
#include "stdio.h"
#include "stdlib.h"

void duplicateZeros(int* arr, int arrSize)
{
        for (int i = 0; i < arrSize - 1; i++) 
        {
            if (arr[i] != 0) continue;

            for (int j = arrSize- 2; j > i; j--)
                arr[j+1] = arr[j];
            arr[++i] = 0;
        }

}
int main()
{
	int *nums;
	int numsSize;
	scanf("%d",&numsSize);
	
	nums=(int*)malloc(sizeof(int)*numsSize);
	
	for(int i=0;i<numsSize;i++)
	scanf("%d",&nums[i]);
	
	duplicateZeros(nums,numsSize);
	for(int i=0;i<numsSize;i++)
	printf("%d ",nums[i]);
	
	free(nums);
	return 0;
}
