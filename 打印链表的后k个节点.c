#include"stdio.h"
#include"stdlib.h"

typedef struct Node{
	int val;
	struct Node *next;
}Node;

Node *getKthFromEnd(Node *head, int k)
{
    Node *p = head;
    Node *q = head;
    
    if (head == NULL || k <= 0)
        return NULL;

    while (k) 
	{
        q = q->next;
        if (q == NULL && k != 1)
            return NULL;
      
        k--;
    }

    while (q != NULL) 
	{
        q = q->next;
        p = p->next;
    }

    return p;
}

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

int main()
{
	int n,k;
	scanf("%d",&n);
	Node *p = InitList(n);
	scanf("%d",&k);
	
	Node* q=getKthFromEnd(p,k);
	ShowList(q,k);
	
	free(p);
	free(q);
	return 0;
}
