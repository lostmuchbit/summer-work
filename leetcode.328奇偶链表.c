#include"stdio.h"
#include"stdlib.h"

typedef struct Node{
	int val;
	struct Node *next;
}Node; 

Node* oddEvenList(Node* head){
    if(head ==NULL || head->next==NULL) return head;
    Node* evenHead=head->next;  //记录偶数位置链表的表头，用于最后奇偶相连
    Node* odd=head;            //奇数位置指针
    Node* even=odd->next;      //偶数位置指针
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;         //指向后面第二个结点，即把奇数和偶数分开了
        even->next=even->next->next;
        odd=odd->next;
        even=odd->next;
    }
    odd->next=evenHead;
    return head;
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
	int n;
	scanf("%d",&n);
	Node *p = InitList(n);
	
	Node* q= oddEvenList(p);
	ShowList(p,n);
	
	free(p);
	free(q);
	return 0;
}
