#include"stdio.h"
#include"stdlib.h"
 
typedef struct DualNode{
    char val;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DualList;
 
DualNode *InitReDuList(int n)
{
    int i;
    DualNode *q,*p,*L;
    L = (DualNode *)malloc(sizeof(DualNode));
    L->next = NULL;
    L->prior = NULL;
    p = L;
    for(i = 0;i < n;i++)
    {
        q = (DualNode *)malloc(sizeof(DualNode));
        scanf("%d",&(q->val));
        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    p->next = L->next;
    L->next->prior = p;
    return L;
}
void ShowDualList(DualNode *p,int n)
{
    int i;
    DualNode *t = p;
    for(i = 0;i < n;i++)
    {
        t = t->next;
        printf("%d ",t->val);
    }
}
 
int main()
{
    int n;
    int i,flag = 1;
    scanf("%d",&n);
    DualNode *p = InitReDuList(n);
    DualNode *t1 = p->next,*t2 = p->next->prior;
    for(i = 0;i < (n/2);i++)
    {
        if((t1->val) != (t2->val))
        {
            flag = 0;
            break;
        }
        t1 = t1->next;
        t2 = t2->prior;
    }
    if(flag)
        printf("true");
    else
        printf("false");
    return 0;
}
