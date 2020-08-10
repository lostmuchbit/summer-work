#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    int i=0,j=0;
    qsort(g,gSize,sizeof(int),cmp);//升序使胃口小的孩子优先喂饱（贪心思想） 
    qsort(s,sSize,sizeof(int),cmp);
    while(i<gSize&&j<sSize)
    {
        if(s[j]>=g[i])
        i++;
        j++;
    }
    return i;
}

int main()
{
	int gsize,ssize;
	printf("输入孩子个数:");
	scanf("%d",&gsize);
	int* g=(int*)malloc(sizeof(int)*gsize);
	printf("输入孩子饥饿度：");
	for(int i=0;i<gsize;i++)
	scanf("%d",&g[i]);
	printf("输入饼干个数:");
	scanf("%d",&ssize);
	int* s=(int*)malloc(sizeof(int)*ssize);
	printf("输入饼干尺寸：");
	for(int i=0;i<ssize;i++)
	scanf("%d",&s[i]);
	printf("有%d个孩子可以喂饱",findContentChildren(g,gsize,s,ssize));
	free(g);
	free(s);
	return 0;	
} 
