/*问题：bool函数的用法*/
/*思路：先判断数组是否为空，若为空则返回false，不为则进行以下操作：由于数组是自上而下，从左到右递增，先从右上角开始判断，若大于目标，向左移一个，若小于目标，则向下移一个，若相等则返回true，若循环结束还没有相等的，则返回false*/

#include "stdio.h"
#include "stdlib.h"
 
 bool findNumberIn2DArray(int** matrix, int matrixSize, int *matrixColSize, int target)
{
     int i=0,j=*matrixColSize-1;

     if(matrixSize==0||*matrixColSize==0)
     return false;

     while(i<matrixSize&&j>=0)
     {
         if(target>matrix[i][j]) i++;
         else if(target<matrix[i][j]) j--;
         else  return true;
     }
     return false;

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
    
    int target;
    scanf("%d",&target);
    
    if(findNumberIn2DArray(a,r,&c,target))
    printf("yes");
    else
    printf("no");
    
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}
