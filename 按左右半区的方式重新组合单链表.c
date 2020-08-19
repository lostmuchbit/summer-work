#include "stdio.h"
#include "stdlib.h"

int n;

typedef struct ListNode{
    int val;
    struct ListNode *next;
}LIST;

LIST *CreateList()
{
    scanf("%d", &n);
    LIST *head=NULL, *cur=NULL, *pre=NULL;
    for(int i=1; i<=n; i++)
    {
        cur=(LIST*)malloc(sizeof(LIST));
        scanf("%d", &cur->val);
        cur->next=NULL;
        if(head==NULL){
            head=cur;
            pre=cur;
        }
        else {
            pre->next=cur;
            pre=cur;
        }
    }
    pre->next = NULL;
    return head;
}

void RecombineList(LIST *head)
{
    LIST *cur1=head, *cur2=head;
    for(int i=1; i<=n/2; i++)
    {
        cur2=cur2->next;
    }
    LIST *p1=NULL, *p2=NULL;
    for(int i=1; i<n/2; i++){
        p1=cur1->next, p2=cur2->next;
        cur1->next = cur2;
        cur2->next = p1;
        cur1=p1;
        cur2=p2;
     }
    p1->next=p2;
}

void PrintfList(LIST *head)
{
    LIST *cur=head;
    while( cur!=NULL)
    {
        printf("%d ", cur->val);
        cur=cur->next;
    }
}

void FreeList(LIST *head)
{
    LIST *temp=head;
    while(head!=NULL)
    {
        LIST *temp=head;
        head=head->next;
        free(temp);
    }
}

int main()
{
    LIST *head=CreateList();
    RecombineList(head);
    PrintfList(head);
    FreeList( head);
    return 0;
}
