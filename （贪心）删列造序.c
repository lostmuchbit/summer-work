#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int minDeletionSize(char ** A, int ASize)
{
    int len=strlen(A[0]);
    int count=0;
    for(int j=0;j<len;j++)
    for(int i=0;i<ASize-1;i++)
    if(A[i][j]>A[i+1][j])//非降序列的可能比升序列的多，故判断是否为升序列更方便（贪心思想）
    {
        count++;
        break;
    }
    return count;
}

int main()
{
	int m,n;
	printf("输入矩阵的行m和列n:");
	scanf("%d%d",&m,&n);
	char** A=(char**)malloc(sizeof(char*)*m);
	for(int i=0;i<m;i++)
	A[i]=(char*)malloc(sizeof(char)*n);
	printf("输入矩阵：\n");
	for(int i=0;i<m;i++)
	scanf("%s",A[i]);
	printf("需要删去%d列才都是非降序列",minDeletionSize(A,m));
	free(A);
	for(int i=0;i<m;i++)
	free(A[i]);
	return 0;
}
