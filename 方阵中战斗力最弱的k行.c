/*问题：如何避免重复记录*/
/*思路：将数组table中所有元素赋值为0，开始对mat一列列遍历，如出现某一行出现0且该行未被记录过的话，则把该行首地址记录最后再主函数中输出前k个数*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h" 

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k)
{
    int *ans = (int *)malloc(sizeof(int) * k);
    int table[matSize];
    memset(table, 0, sizeof(int) * matSize);

    int count = 0;
    for (int j = 0; j < matColSize[0]; j ++)
        for (int i = 0; i < matSize; i ++)    
            if (mat[i][j] == 0 && table[i] == 0)
            {
                ans[count ++] = i;
                table[i] = 1;
            }
    return ans;
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
    
    int* ret=kWeakestRows(a,r,&c,k);
    
    for(int i=0;i<k;i++)
    printf("%d ",ret[i]);
    
    free(ret);
    free(a);                                
    for(int i=0;i<r;i++)
        free(a[i]);
        
    return 0;
}
