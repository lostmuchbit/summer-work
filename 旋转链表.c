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

void ShowList(Node *p,int k)
{
	Node *t = p;
	int i=0;
	while(t!=NULL)
	{
	    printf("%d ",t->val);
	    t = t->next;	   		
    }
}

Node* rotateRight(Node* head, int k){
    if(!head)
    return head;
    int length=1;
    Node *r=head,*p=head,*q=head;
    while(q->next)//到末尾节点
    {
        length++;
        q=q->next;
    }
    if(length==1)//长度为1，不能倒置
    return head;
    k%=length;//取余数
    k=length-k;
    while(k>0)
    {
        k--;
        r=p->next;
        p->next=q->next;
        q->next=p;
        q=p;
        p=r;
    }
    return r;
}

int main()
{
	int n;
	scanf("%d",&n);
	Node *p = InitList(n);
	
	int k;
	scanf("%d",&k);
	
	Node* q=rotateRight(p,k);
	ShowList(q,k);
	
	free(p);
	free(q);
	return 0;
}
