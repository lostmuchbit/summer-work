#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int val;
    struct Node *next;
}Node;
 
Node *init(int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    for (int i = 0 ; i < n; i++) {
        Node *cur  = (Node *)malloc(sizeof(Node));
        scanf("%d", &cur->val);
        cur->next = NULL;
        temp->next = cur;
        temp = temp->next;
    }
    return head;
}
 
void printList(Node *head)
{
    if (head->next == NULL) {
        return;
    }
    Node *node = head->next;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    return;
}
 
void sortList(Node *head)
{
    if (head->next == NULL) {
        return;
    }
    Node *i, *j;
    int min, temp;
    Node *node;
    for (i = head->next; i != NULL; i = i->next) {
        min = i->val;
        node = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->val < min) {
                min = j->val;
                node = j;
            }
        }
        temp = i->val;
        i->val = node->val;
        node->val = temp;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Node *head = init(n);
   
    sortList(head);
    printList(head);
    return 0;
}
