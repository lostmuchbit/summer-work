#include "stdio.h"
#include "stdlib.h" 
 
typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode;
 
Lnode *creat_List(int nums[], int n){
    Lnode *head = (Lnode*)malloc(sizeof(Lnode));
    head -> data = NULL;
    head -> next = NULL;
    Lnode *p = head;
    for(int i = 0; i < n; ++i){
        Lnode *q = (Lnode*)malloc(sizeof(Lnode));
        q -> data = nums[i];
        q -> next = NULL;
        p -> next = q;
        p = p -> next;
    }
    return head;
}
 
void delete_Num(Lnode *head, int m){
    Lnode *p = head;
    int count = 1;
    while(count != m){
        ++count;
        p = p -> next;
    }
    Lnode *q = p -> next;
    p -> next = q -> next;
    free(q);
}
 
void print_List(Lnode *head){
    while(head -> next){
        printf("%d ", head -> next -> data);
        head = head -> next;
    }
}
 
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int nums[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &nums[i]);
    }
    Lnode *head;
    head = creat_List(nums, n);
    delete_Num(head, m);
    print_List(head);
    return 0;
}
