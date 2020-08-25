#include "stdio.h"
#include "stdlib.h"
 
int parent[1000];
 
int findroot(int a){
    if(parent[a]==-1)
        return a;
    else{
        int tmp=findroot(parent[a]);
        parent[a]=tmp;
        return tmp;
    }
}

void Exit()//结束程序
{
	char sure;
	printf("Are you sure to exit?(y/n):");
	getchar();
	sure=getchar();
	if(sure=='y'||sure=='Y')
	exit(0);
} 
 
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n>0){
        int i,j,a,b;
        for(i=0;i<=n;i++)
            parent[i]=-1;
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            a=findroot(a);
            b=findroot(b);
            if(a!=b)
                parent[a]=b;
        }
        int s=0;
        for(i=1;i<=n;i++)
            if(parent[i]==-1)
                s++;
        printf("%d\n",s-1);
        Exit();
        system("pause");
        system("cls");
    }
 
    return 0;
}
