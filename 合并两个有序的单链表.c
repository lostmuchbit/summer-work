#include "stdio.h"
#include "stdlib.h"
  
typedef struct List
{
    struct List* next;
    int data;
}List;
  
List* init_List(List* list)
{
    int i, len;
    List* p = list;
    
    scanf ("%d", &len);
      
    for (i = 0; i < len-1; i++)
    {
        scanf ("%d", &(p->data));
        p->next = (List*)malloc(sizeof(List));
        p = p->next;
         
    }
    scanf ("%d", &(p->data));
    p->next = NULL;
      
   
    return list;
}
  
void merge (List* list1, List* list2)
{
    while (1)
    {
        if (list1 == NULL && list2 == NULL)
            return;
          
        if (list1 == NULL)
        {
            printf ("%d ", list2->data);
            list2 = list2->next;
            continue;
        }
          
        if (list2 == NULL)
        {
            printf ("%d ", list1->data);
            list1 = list1->next;
            continue;
        }
          
        if (list1->data <= list2->data)
        {
            printf ("%d ", list1->data);
            list1 = list1->next;
        }
        else{
            printf ("%d ", list2->data);
            list2 = list2->next;
        }
    }
      
}
  
int main()
{
    List* list1 = (List*)malloc(sizeof(List));
    List* list2= (List*)malloc(sizeof(List));
    list1 = init_List (list1);
    list2 = init_List (list2);
    merge(list1, list2);
    return 0;
}
