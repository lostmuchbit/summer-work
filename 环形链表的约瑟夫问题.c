#include"stdio.h"
#include"stdlib.h"
 
typedef struct Node{
    int data;
    struct Node *next;
}Node;
 
Node *InitList(int n)
{
    Node *p = NULL,*head;
    head = (Node *)malloc(sizeof(Node));
    p = head;
    Node *s;
    int i = 1;
    if(0 != n)
    {
        while(i <= n)
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = i;
            p->next = s;
            p = s;
            i++;
        }
         
        s->next = head->next;
         
    }
    free(head);
    return s->next;
}
 
 
 
int main()
{
    int i,n,m;
    scanf("%d %d",&n,&m);
    Node *p = InitList(n);
    Node *temp;
    if((m % n) == 1)
    {
        for(i = 1;i < n;i++)
        {
            p = p->next;
        }
    }
    else{
    while(p != p->next)
    {
        for(i = 1;i < m - 1;i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
        p = p->next;
 
    }
    }
    printf("%d\n",p->data);
    free(p);
    return 0;
}
