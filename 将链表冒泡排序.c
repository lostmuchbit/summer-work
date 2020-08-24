#include"stdio.h"
#include"stdlib.h"

typedef struct Node{
	int val;
	struct Node *next;
}Node;

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

void ShowList(Node *p,int n)
{
	int i;
	Node *t = p;
	for(i = 0;i < n;i++)
	{
	    printf("%d ",t->val);
		t = t->next;
	}
}

Node* insertionSortList(Node* head) 
{
     if(!head)
        return NULL;
     Node * p,*q;
     int temp;

    for(p=head;p;p=p->next)
    for(q=p->next;q;q=q->next)
    if(p->val>q->val)
    {
        temp=p->val;
        p->val=q->val;
        q->val=temp;
    }
    return head;
}

int main()
{
	int n;
	int i;
	scanf("%d",&n);
	Node *p = InitList(n);
	
	Node* q=insertionSortList(p);
	ShowList(q,n);
	
	free(p);
	free(q);
	return 0;
}
