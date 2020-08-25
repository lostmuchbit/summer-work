#include<stdio.h>

#define N 1001

int FindRoot(int Tree[],int x){
    if(Tree[x]==-1) return x;//如果无根跟就是自己
    else{
        return FindRoot(Tree,Tree[x]);//有根找根,并更新根，赋值最新的根,因为可能会出现情况变化
         
    }
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int Tree[N];
        int i,a,b;
        for(i=1;i<=n;i++)
            Tree[i]=-1;
        while(m--){
            scanf("%d%d",&a,&b);
            a=FindRoot(Tree,a);//找a的根
            b=FindRoot(Tree,b);
            if(a!=b) Tree[b]=a;
        }
        int ans=0;
        for(i=1;i<=n;i++)
            if(Tree[i]==-1) ans++;
        puts(ans>1?"NO":"YES");
    }
}
