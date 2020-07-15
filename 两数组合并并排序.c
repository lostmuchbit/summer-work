/*没什么问题*/
/*思路：直接将nums2中元素装到nums1中，然后冒泡排序*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define Max 10000

void maopao(int *nums,int t)
{
    for(int i=0;i<t;i++)
        for(int j=0;j<t-i-1;j++)
            if(nums[j]>nums[j+1])
            {
                int temp;
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int j=0;
     for(int i=m;i<m+n;i++)
     {
         nums1[i]=nums2[j];
         j++;
     }
     maopao(nums1,m+n);
}

int main()
{
	int m,n,nums1Size,nums2Size;
	int nums1[Max],nums2[Max];
	
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	scanf("%d",&nums1[i]);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&nums2[i]);
	
	nums1Size=m+n;
	nums2Size=n;
	
	merge(nums1,nums1Size,m,nums2,nums2Size,n);
	
	for(int j=0;j<m+n;j++)
    printf("%d ",nums1[j]);
    
    return 0;
}
