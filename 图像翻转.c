/*思路：直接遍历，0赋值为1，1赋值为0*/
#include "stdio.h"
#include "stdlib.h"

void flipAndInvertImage(int** A, int ASize, int* AColSize)
{
    int col=ASize;
    int row=*AColSize;

    for(int j=0;j<row;j++)
    {
        if(A[0][j]==0) A[0][j]=1;
        else A[0][j]=0;
    }

    for(int i=0;i<col;i++)
    for(int j=0;j<row;j++)
    {
        if(A[i][j]==0) A[i][j]=1;
        else A[i][j]=0;
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
