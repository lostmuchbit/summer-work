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
		t = t->next;
		printf("%d ",t->val);
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
	/*free(s);
	free(t);
	free(temp);*/
}
int main()
{
	int n,L,R;
	int i;
	scanf("%d",&n);
	Node *p = InitList(n);
	scanf("%d %d",&L,&R);
	ReverseList(p,L,R);
	ShowList(p,n);
	return 0;
}
