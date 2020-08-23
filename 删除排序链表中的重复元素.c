#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
	int val;
	struct Node *next;
}Node;

Node* deleteDuplicates(Node* head,int* n)
{

	if(head == NULL)//单链表为空，返回链表
	{
		return head;
		*n=0;
	}	

	Node *lp;
	Node *p = head;//指针指向单链表
	lp = p;//最后链表返回的位置
	while(p ->next != NULL){
		if(p -> val == p ->next -> val){
			p -> next = p -> next -> next;//删除后者节点，继续遍历
			(*n)--;
		}
		else{
			p = p -> next;
		}
	}
	return lp;
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
		t = t->next;
		printf("%d ",t->val);
	}
}

int main()
{
	int n,L,R;
	int i;
	scanf("%d",&n);
	Node *p = InitList(n);
	
	Node* q=deleteDuplicates(p,&n);
	ShowList(q,n);
	return 0;
}
