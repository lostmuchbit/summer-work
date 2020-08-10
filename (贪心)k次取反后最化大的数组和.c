//优先取反的是最小的数（贪心）
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int largestSumAfterKNegations(int* A, int ASize, int K)
{
    int sum=0;
    int count=0;
    qsort(A,ASize,sizeof(int),cmp);//升序

    for(int i=0;i<ASize;i++)//记录数组中负数的个数
    {
        if(A[i]<0) count++;
        else break;
    }

    if(count>=K)//如果负数的个数比取反次数多，就将数组由小到大取反，直至取反次数用尽，再取和
    {
        for(int i=0;i<K;i++)
        A[i]=-A[i];
        for(int i=0;i<ASize;i++)
        sum+=A[i];
    }
    else//如果负数的个数比取反次数少
    {
        for(int i=0;i<count;i++)就先把所有负数取反
        {
            A[i]=-A[i];
            K--;
        }
        qsort(A,ASize,sizeof(int),cmp);
        if(K%2==0) //再看剩余的取反次数若是偶数，就不变就可达到最大和
        {
            for(int i=0;i<ASize;i++)
            sum+=A[i];
        }
        else //若为奇数，只有是把最小的数取反，才可能得到最大和
        {
            A[0]=-A[0];
            for(int i=0;i<ASize;i++)
            sum+=A[i];
        }

    }
    return sum;
}

int main()
{
	int ASize;
	printf("输入数组元素个数：");
	scanf("%d",&ASize);
	
	int* A=(int*)malloc(sizeof(int)*ASize);
	printf("输入数组元素:");
	for(int i=0;i<ASize;i++)
	scanf("%d",&A[i]);
	
	int k;
	printf("输入变换次数:");
	scanf("%d",&k);
	
	printf("%d次取反后数组和最大值为%d",k,largestSumAfterKNegations( A,ASize,k));
	
	free(A);
	return 0;
 
} 
