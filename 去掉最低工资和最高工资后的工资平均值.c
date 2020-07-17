/*思路：先用冒泡排序升序，再从第二个元素开始遍历，直到倒数第二个元素，累加得sum，最后用sum除以（salarySize-2），并返回*/
#include "stdio.h"
#include "stdlib.h"

void maopao(int *salary,int salarySize)
{
    for(int i=0;i<salarySize;i++)
        for(int j=0;j<salarySize-i-1;j++)
            if(salary[j]<salary[j+1])
            {
                int temp;
                temp=salary[j];
                salary[j]=salary[j+1];
                salary[j+1]=temp;
            }
}

double average(int* salary, int salarySize)
{
    maopao(salary,salarySize);
    
    double sum=0;
    
    for(int i=1;i<salarySize-1;i++)
        sum+=salary[i];
    
    return sum/(salarySize-2);
}

int main()
{
	int *salary,salarySize=0;
	
	salary=(int *)malloc(sizeof(int));
	
	scanf("%d",salary+salarySize);
    while(getchar()!='\n')
    {
    	salarySize++;
    	scanf("%d",salary+salarySize);
	}
	
	
	printf("%lf",average(salary, salarySize+1));
	
	return 0;
}
