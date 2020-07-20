/*思路：i<m-1实现最后一行不算，j<m-1实现最后一列不算，i+j!=m-1实现副对角线不算*/
#include "stdio.h"
#include "stdlib.h"
#define Max 100

int main()
{
    int a[Max][Max];
    int m;
    scanf("%d",&m);
    
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
            
    int sum=0;
    for(int i=0;i<m-1;i++)
        for(int j=0;j<m-1;j++)
            if(i+j!=m-1)
                sum+=a[i][j];
    
    printf("%d",sum);
    
    return 0;
}
