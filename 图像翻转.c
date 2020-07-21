/*思路：直接遍历，0赋值为1，1赋值为0*/
#include "stdio.h"
#include "stdlib.h"

void flipAndInvertImage(int** A, int ASize, int* AColSize)
{
    int col=ASize;
    int row=*AColSize;
    int ret[col][row];

    for(int i=0;i<col;i++)
    for(int j=0;j<row;j++)
     ret[i][j] = A[i][row-1-j] == 0 ? 1 : 0;

    for(int i=0;i<col;i++)
    for(int j=0;j<row;j++)
    A[i][j]=ret[i][j];
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
    
    flipAndInvertImage(a,r,&c);
    
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
