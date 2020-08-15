#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int minFallingPathSum(int** A, int ASize, int* AColSize)
{
    for(int i=ASize-2;i>=0;i--)//由下往上找路径可以有效地处理下边界的问题 
    for(int j=0;j<*AColSize;j++)
    {
    	//best=fmin(A[i+1][j],A[i+1][j-1],A[i+1]j+1])
        int best=A[i+1][j];
        if(j>0)//处理边界问题（元素在第一列时由于左边没有元素，所以只能向下或向右下） 
        best=fmin(best,A[i+1][j-1]);
        if(j<(*AColSize)-1)// /处理边界问题（元素在最后一列时由于右边没有元素，所以只能向下或向左下）
        best=fmin(best,A[i+1][j+1]);
        A[i][j]+=best;
    }

    int min=A[0][0];
    for(int i=1;i<*AColSize;i++)
    min=fmin(min,A[0][i]);

    return min;
}

int main()
{
	int ASize,AColSize;
	printf("输入矩阵行数和列数：");
	scanf("%d%d",&ASize,&AColSize);
	
	int** A=(int**)malloc(sizeof(int*)*ASize);
	for(int i=0;i<ASize;i++)
	A[i]=(int*)malloc(sizeof(int)*AColSize); 
	
	printf("输入矩阵：\n");
	for(int i=0;i<ASize;i++)
	for(int j=0;j<AColSize;j++)
	scanf("%d",&A[i][j]);
	
	printf("最小下降路径和为%d",minFallingPathSum(A,ASize,&AColSize));
	
	free(A);
	for(int i=0;i<AColSize;i++)
	free(A[i]);
	
	return 0;
}
