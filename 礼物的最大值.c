/*问题：动态规划的边界着实难以确定，每次都越界*/
/*思路：先把第一列和第一行进行运算，在进行其他运算（难以说清，图示表达）*/
/* 1 3 1 第一行运算   1 4 5          1 4 5
   1 5 1  =========>  2 5 1  ======> 2 9 10   最后一个元素就是我们要输出的
   4 2 1 第一列运算   6 2 1          6 11 12*/
   
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_HTL(a, b) ((a) > (b) ? (a) : (b))

int maxValue(int** grid, int gridSize, int *gridColSize)
{
    if (grid == NULL || gridSize <= 0) 
        return 0;
    

    int row = gridSize;
    int col = *gridColSize;
    for (int i = 1; i < col; i++) 
        grid[0][i] += grid[0][i - 1];
    
    for (int i = 1; i < row; i++) 
        grid[i][0] += grid[i - 1][0];
    

    for (int i = 1; i < row; i++) 
        for (int j = 1; j < col; j++) 
            grid[i][j] += MAX_HTL(grid[i - 1][j], grid[i][j - 1]);

    return grid[row - 1][col - 1];
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
    
    printf("%d",maxValue(a,r,&c));
    
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}
