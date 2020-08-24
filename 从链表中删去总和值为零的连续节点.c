/*双指针循环向前；链表前添加pre结点，解决头节点特殊情况*/
#include"stdio.h"
#include"stdlib.h"

typedef struct Node{
	int val;
	struct Node *next;
}Node; 

Node* removeZeroSumSublists(Node* head){
    if (NULL == head){
        return NULL;
    }
    Node list_head;
    list_head.next = head;
    list_head.val = 0;
    Node *pre = &list_head;

    while (pre != NULL) {
        Node *last = pre->next;
        int sum  = 0;
        
        while (last) {
            sum += last->val;
            if (0==sum) {
                pre->next = last->next;
                break;
            }
            last = last->next;
        }
        
        if (NULL == last) {
            pre = pre->next;
        }
    }

    return list_head.next;
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

void ShowList(Node *p)
{
	int i;
	Node *t = p;
	while(t!=NULL)
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
	
	Node* q=removeZeroSumSublists(p);
	ShowList(q);
	return 0;
}
