/*思路：用冒泡排序对对角线元素进行排序*/
#include "stdio.h"
#include "stdlib.h"

void diagonalSort(int** mat, int matSize, int* matColSize)
{
    int row = matSize;
    int col = matColSize[0];

    for(int i = 0; i < row - 1; i++)
        for(int j = 0; j < row - 1 - i; j++)
            for(int k = 0; k < col - 1; k++)
                if(mat[j][k] > mat[j + 1][k + 1])
                {
                    int tmp = mat[j][k];
                    mat[j][k] = mat[j + 1][k + 1];
                    mat[j + 1][k + 1] = tmp;
                }    
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
    
    diagonalSort(a,r,&c);
    
    for(int i=0;i<r;i++)                  
    {
        for(int j=0;j<c;j++)
        printf("%d ",a[i][j]);
        printf("\n");
	}
    
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}
