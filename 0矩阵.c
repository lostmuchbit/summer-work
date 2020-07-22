/*思路：先用数组记录0所在的行和列，再把对应的行和列的元素赋值为0*/
#include "stdio.h"
#include "stdlib.h" 
#define Max 10000

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
     int indexi[Max],indexj[Max],k=0;

     for(int i=0;i<matrixSize;i++)
     for(int j=0;j<matrixColSize[0];j++)
     if(matrix[i][j]==0)
     {
         indexi[k]=i;
         indexj[k]=j;
         k++;
     }

     for(int i=0;i<k;i++)
     {
         int index=indexi[i];
         for(int j=0;j<matrixColSize[0];j++)
         matrix[index][j]=0;
     }

      for(int i=0;i<k;i++)
     {
         int index=indexj[i];
         for(int j=0;j<matrixSize;j++)
         matrix[j][index]=0;
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
    
    setZeroes(a,r,&c);
    
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
