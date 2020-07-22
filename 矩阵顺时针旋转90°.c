/*思路：将矩阵先转置，再左右镜像*/
#include "stdio.h"
#include "stdlib.h"

 void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int col=matrixSize;
    int row=*matrixColSize;
     for(int i=0;i<col;i++)
     for(int j=i;j<row;j++)
     {
         int tmp;
         tmp=matrix[i][j];
         matrix[i][j]=matrix[j][i];
         matrix[j][i]=tmp;
     }

     for(int i=0;i<col;i++)
     for(int j=0;j<row/2;j++)
     {
         int temp;
         temp=matrix[i][j];
         matrix[i][j]=matrix[i][row-1-j];
         matrix[i][row-1-j]=temp;
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
    
    rotate(a,r,&c);
    
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
