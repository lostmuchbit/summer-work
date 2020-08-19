#include"stdio.h"
#include"stdlib.h"
 
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct DualNode{
    int val;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DualList;

Node *InitList(int n)
{
    int i;
    Node *p = (Node *)malloc(sizeof(Node));
    Node *t = p;
    for(i = 1;i <= n;i++)
    {
        Node *input= (Node *)malloc(sizeof(Node));
        scanf("%d",&(input->val));
        input->next = NULL;
        t->next = input;
        t = t->next;
    }
    return p;
}

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

void ShowList(Node *p,int n)
{
    int i;
    Node *t = p;
    for(i = 0;i < n;i++)
    {
        t = t->next;
        printf("%d ",t->val);
    }
}

void ShowReverseDuList(DualNode *p,int n)
{
    int i;
    DualNode *t = p;
    for(i = 0;i < n;i++)
    {
        t = t->next;
    }
    for(i = 0;i < n;i++)
    {
        printf("%d ",t->val);
        t = t->prior;
    }
}

void ReverseList(Node *p,int L,int R)
{
    int i;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    Node *t = temp;
    Node *s = p;
    for(i = 0;i < L;i++)
    {
        s = s->next;
    }
    for(i = 0;i <= (R - L);i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->val = s->val;
        t->next = temp->next;
        temp->next = t;
        s = s->next;
    }
    s = p;
    for(i = 0;i < R;i++)
        s = s->next;
    t = temp;
    for(i = 0;i <(R - L + 1);i++)
        t = t->next;
    t->next = s->next;
    s = p;
    for(i = 0;i < (L - 1);i++)
        s = s->next;
    s->next = temp->next;
 
}
int main()
{
    int i;
    int n,m;
    scanf("%d",&n);
    Node *p = InitList(n);
    scanf("%d",&m);
    DualNode *q = InitDuList(m);
    ReverseList(p,1,n);
    ShowList(p,n);
    printf("\n");
    ShowReverseDuList(q,m);
    return 0;
}
