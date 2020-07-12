#include "stdio.h"
#define Max 10000

int missingNumber(int nums[], int numsSize)
{
    int i=0;
    for(i=0;i<numsSize;i++)
        if(nums[i]!=i)
            break;
    return i;
}

int main()
{
    int nums[Max],numsSize;
    printf("输入字符串长度:");
    scanf("%d",&numsSize);

    printf("输入字符串:");
    for(int i=0;i<numsSize;i++)
    scanf("%d",&nums[i]);

    printf("%d",missingNumber(nums,numsSize));
    return 0;
}
