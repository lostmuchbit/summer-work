#include "stdio.h"
#include "stdlib.h"
 
typedef struct Node{
	int val;
	struct Node *next;
}Node;

int* reversePrint(Node* head, int* returnSize)
{
    if(head==NULL)
	{
        *returnSize=0;
        return NULL;
    }
    
	Node* p=head;
    int num=0;
    
    while(p!=NULL)
	{
        p=p->next;
        num++;
    }
    
    int *res=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++)
	{
        res[num-1-i]=head->val;//将链表中的节点数据域的内容第一个放入res数组的最后一个，以此类推
        head=head->next;
    }
    
    *returnSize=num;
    return res;
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

int main()
{
	int n;
	int i;
	scanf("%d",&n);
	Node *p = InitList(n);
    
    int returnSize=0;
	int* q=reversePrint(p, &returnSize);
	
	for(i=0;i<returnSize-1;i++)
	printf("%d ",q[i]);
	
	free(p);
	free(q);

	return 0;
}
