#include "stdio.h"
#include "stdlib.h" 

typedef struct list
{
    int data;
    struct list  *next;
}L;
 
 
int insert(int tmp, L *s)
{
    L *p, *q;
    p = s->next;
    if (p == NULL)
    {
        q = (L*)malloc(sizeof(L));
        q->data = tmp;
        q->next = NULL;
        s->next = q;
        return 0;
    }
    if (p)
    {
        q = (L*)malloc(sizeof(L));
        q->data = tmp;
        q->next = p;
        s->next = q;
        return 0;
    }
}
 
int print(L *s)
{
    L *p;
    p = s->next;
    while (p)
    {
        printf("%d ", p->data);
        s = p;
        p = s->next;
    }
    return 0;
}

L* init(void)
{
    L *s = (L*)malloc(sizeof(L));
    s->next = NULL;
    return s;
}
 
int main(void)
{
    L *s0,*s1,*s2;
    s0 = init();
    s1 = init();
    s2 = init();
    int n, cmp, tmp;
    scanf("%d", &n);
    scanf("%d", &cmp);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp < cmp)
            insert(tmp, s0);
        else if (tmp == cmp)
            insert(tmp, s1);
        else
            insert(tmp, s2);
    }
    print(s0);
    print(s1);
    print(s2);
    printf("\b");
    return 0;
}
