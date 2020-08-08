#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int multiply(int A, int B)
{
    int ret;
    if(B==0) return 0;
    if(abs(B)==1) ret=A;//出口
    else ret=multiply(A,abs(B)-1)+A;
    if(B>0) return ret;
    else 
    {
        ret=(-1)*ret;
        return ret;
    }
}

int main()
{
	int A,B;
	printf("输入A和B:");
	scanf("%d%d",&A,&B);
	printf("A和B的乘积：%d",multiply(A,B));
	return 0;
}
