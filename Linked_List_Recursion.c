#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node * next;
}ListNode;
void insert(ListNode **head,int val)
{
    if(*head==NULL)
    {
        ListNode *temp=NULL;
        temp=(ListNode *)malloc(sizeof(ListNode));
        if(temp==NULL)
        {
            printf("\nMemory Error...\n");
            return ;
        }
        temp->val=val;
        temp->next=NULL;
        *head=temp;
    }
    else
    {
        insert(&((*head)->next),val);
    }
}
void del(ListNode **head,int key)
{
    if(*head==NULL)
    {
        return;
    }   
    else if((*head)->val==key)
    {
        ListNode *ptr=*head;
        *head=(*head)->next;
        printf("\nDeleted element is : %d",ptr->val);
        free(ptr); 
        del(&(*head),key);
    }
    else
    {
        del(&((*head)->next),key);
    }
}
void display(ListNode *head)
{
    if(head)
    {
        printf("%d ",head->val);
        display(head->next);
    }
}
void displayReverse(ListNode *head)
{
    if(head)
    {
        displayReverse(head->next);
        printf("%d ",head->val);
    }
}
int main()
{
    ListNode* head=NULL;
    insert(&head,2);
    insert(&head,2);
    insert(&head,2);
    insert(&head,2);
    insert(&head,2);   
    printf("\nDisplaying elements: \n ");display(head); 
    
    
    del(&head,2);
    
    
    printf("\nDisplaying elements: \n ");display(head);
    
    //printf("\nDisplaying elements: \n ");displayReverse(head);
    return 0;
}