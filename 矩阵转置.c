/*问题：动态内存分配和函数返回数组（根据leetcode中的函数写main真的写不倒）*/
/*思路：交换矩阵的行索引与列索引，这个没什么好说的*/
#include "stdio.h"
#include "stdlib.h"

int** transpose(int** A, int ASize, int* AColSize)
{
    int **res = (int **)malloc(sizeof(int *) * AColSize[0]);
    
    for (int i = 0; i < AColSize[0]; ++i) {
        res[i] = (int *)malloc(sizeof(int) * ASize);
    }

    for (int i = 0; i < ASize; ++i) {
        for (int j = 0; j < AColSize[0]; ++j) {
            res[j][i] = A[i][j];
        }
    }

    return res;
}

int main()
{
    int r,c;                                
    int **a;                                
    printf("Please enter the r & c:");      
    scanf("%d %d",&r,&c);
    a = (int**)malloc(sizeof(int*)*r);    

    for(int i=0;i<r;i++)
    a[i] = (int*)malloc(sizeof(int)*c);
    
    for(int i=0;i<r;i++)                  
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
 
    int** b=transpose(a,r,&c);
    
    for(int i=0;i<c;i++)
    {
    	for(int j=0;j<r;j++)
        printf("%d ",b[i][j]);
        printf("\n");
        free(b[i]); 
	}
	free(b);
    
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}

