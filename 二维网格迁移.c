/*问题：函数如何返回数组*/
/*思路：写在注释*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 void CatK(int* buf, int size, int k) {
    int* profix = (int*)malloc(sizeof(int) * (size - k));//分配空间给profix
    int* befix = (int*)malloc(sizeof(int) * k);//分配空间给befix
    memcpy(profix, buf, sizeof(int) * (size - k));//将buf的前size-k个数copy到profix中
    memcpy(befix, buf + (size - k), sizeof(int) * k);//将buf的后k个数copy到befix中
    memcpy(buf, befix, sizeof(int) * k);//将befix中的copy到buf前K个空中
    memcpy(buf + k, profix, sizeof(int) * (size - k));//将profix中的数copy到buf的后size-k个空中
}

void shiftGrid(int** grid, int gridSize, int *gridColSize, int k)
{
	int* buf = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
    int p = 0;
    for(int i = 0; i < gridSize; i++) //将二维数组转化成一维数组
    {
        for (int j = 0; j < *gridColSize; j++) {
            buf[p] = grid[i][j]; 
            p++;
        }
    }
    k = k % (gridSize * (*gridColSize));//保证k<grid元素个数
    CatK(buf, gridSize * (*gridColSize), k);
    p = 0;
    for (int i = 0; i < gridSize; i++) //将一维数组转化成二维数组
    {
        for (int j = 0; j < *gridColSize; j++) {
            grid[i][j] = buf[p];
            p++;
        }
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
    
    int k;
    scanf("%d",&k);
    
    shiftGrid( a, r, &c, k);
    
    for(int i=0;i<r;i++)
    {
	    for(int j=0;j<c;j++)
    	printf("%d ",a[i][j]);
    	printf("\n");
	}
  
    //返还空间
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}
