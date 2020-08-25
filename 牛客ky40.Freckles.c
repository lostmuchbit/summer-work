#include "stdio.h"
#include "math.h"
#include "stdlib.h"
struct edge
{
    int s;
    int d;
    float dis;
}e[5000];

int cmp(const void *a,const void *b)
{
    return (*(edge*)a).dis>(*(edge*)b).dis ? 1:-1;
}

int root[101];

int find(int x)
{
    int k=x,j;
    while(x!=root[x])x=root[x];
    while(k!=root[k])
    {
        j=root[k];
        root[k]=x;
        k=j;
    }
    return x;
}

float krusk(int num,int n)
{
    qsort(e,n,sizeof(e[0]),cmp);
    float sum=0;
    int numofedg=0;
    for(int i=0;i<num+1;i++)root[i]=i;
    for(int i=0;i<n;i++)
    {
        int a=e[i].s,b=e[i].d;
        if(find(a)!=find(b))
        {
            root[find(a)]=find(b);
            sum+=e[i].dis;
            numofedg++;
        }
        if(numofedg==num-1)break;
    }
    return sum;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        float dot[n][2];
        int p=0;
        for(int i=0;i<n;i++)scanf("%f%f",&dot[i][0],&dot[i][1]);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                e[p].s=i;
                e[p].d=j;
                e[p++].dis=sqrt((dot[i][0]-dot[j][0])*(dot[i][0]-dot[j][0])+(dot[i][1]-dot[j][1])*(dot[i][1]-dot[j][1]));
            }
        }
        printf("%.2f\n",krusk(n,(n*(n-1))/2));
    }
    return 0;
}
