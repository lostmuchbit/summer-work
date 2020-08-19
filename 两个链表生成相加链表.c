#include"stdio.h"
#include"stdlib.h"
 
typedef struct DualNode{
    int val;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DualList;
 
DualNode *InitDuList(int n)
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
    return L;
}
 
void ShowDualList(DualNode *p,int n)
{
    int i;
    DualNode *t = p;
    t = t->next;
    if(t->val >= 10)
        printf("1 %d ",t->val - 10);
    else
        printf("%d ",t->val);
    for(i = 0;i < (n - 1);i++)
    {
        t = t->next;
        printf("%d ",t->val);
    }
}
 
DualNode *AddList(DualNode *p,DualNode *q,int n,int m)
{
    DualNode *t,*t1,*t2;
    int i;
    if(n == m)
    {
        t1 = p;
        t2 = q;
        for(i = 0;i < n;i++)
        t1 = t1->next;
        t = t1;
        for(i = 0;i < m;i++)
            t2 = t2->next;
        for(i = 0;i < m;i++)
        {
            t1->val += t2->val;
            t1 = t1->prior;
            t2 = t2->prior;
        }
        for(i = 0;i < (m - 1);i++)
        {
            if(t->val >= 10)
            {
                t->val -= 10;
                t->prior->val++;
            }
            t = t->prior;
        }
        return p;
    }
    else if(n > m)
    {
        t1 = p;
        t2 = q;
        for(i = 0;i < n;i++)
            t1 = t1->next;
        t = t1;
        for(i = 0;i < m;i++)
            t2 = t2->next;
        for(i = 0;i < m;i++)
        {
            t1->val += t2->val;
            t1 = t1->prior;
            t2 = t2->prior;
        }
        for(i = 0;i < (n - 1);i++)
        {
            if(t->val >= 10)
            {
                t->val -= 10;
                t->prior->val++;
            }
            t = t->prior;
        }
        return p;
    }
    else
    {
        t1 = p;
        t2 = q;
        for(i = 0;i < n;i++)
            t1 = t1->next;
        for(i = 0;i < m;i++)
            t2 = t2->next;
        t = t2;
        for(i = 0;i < n;i++)
        {
            t2->val += t1->val;
            t1 = t1->prior;
            t2 = t2->prior;
        }
        for(i = 0;i < (m - 1);i++)
        {
            if(t->val >= 10)
            {
                t->val -= 10;
                t->prior->val++;
            }
            t = t->prior;
        }
        return q;
    }
}
 
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    DualNode *p = InitDuList(n);
    DualNode *q = InitDuList(m);
    p = AddList(p,q,n,m);
    if(n >= m)
        ShowDualList(p,n);
    else
        ShowDualList(p,m);
    return 0;
}
