#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
}ListNode;
void insertAtBeg(ListNode **head,int val)
{
    ListNode *temp=NULL;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        temp->next=*head;
        *head=temp;
    }
}
void insertAtEnd(ListNode **head,int val)
{
    ListNode *temp=NULL;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=val;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        ListNode *ptr=*head;
        while(ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insertAtPos(ListNode **head,int val,int pos)
{
    ListNode* temp=NULL;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=val;
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
        ListNode *ptr=*head;
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void delAtBeg(ListNode **head)
{
    if(*head==NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        ListNode *temp=*head;
        *head=(*head)->next;
        printf("Deleted element is : %d \n",temp->val);
        free(temp);
    }
}
void delAtEnd(ListNode **head)
{
    if(*head==NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        ListNode *temp=*head;
        ListNode *ptr=NULL;
        while(temp->next)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        printf("\nDeleted element is : %d\n",temp->val);
        free(temp);
    }

}
void delAtPos(ListNode **head,int pos)
{
    if(*head==NULL)
    {
        printf("\nList is empty.\n");
        return ;
    }
    ListNode *temp=*head;
    ListNode *ptr=NULL;
    if(pos==0)
    {
        ptr=*head;
        *head=(*head)->next;
        printf("\nDeleted element is : %d \n",ptr->val);
        free(ptr);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        ptr=temp->next;
        temp->next=ptr->next;
        printf("\nDeleted element is : %d \n",ptr->val);
        free(ptr);
    }
}
void delKey(ListNode **head,int key)
{
    if(*head==NULL)
    {
        printf("\nList is empty. \n");
        return ;
    }
    ListNode *temp=*head;
    ListNode *ptr=NULL;
    while(temp->next)
    {
        if(temp->val==key)
        {
            ptr=temp;
            *head=(*head)->next;
            temp=temp->next;
            printf("\nDeleted element is : %d\n",ptr->val);
            free(ptr);
        }
        else if(temp->next->val==key)
        {
            ptr=temp->next;
            temp->next=ptr->next;
            printf("\nDeleted element is : %d\n",ptr->val);
            free(ptr);
        }
        else
        {
            temp=temp->next;
        }
    }
    if((*head)->val==key)
    {
        *head=NULL;
    }
}
void display(ListNode *head)
{
    printf("\n");
    printf("Displaying elements: ");
    if(head==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while(head)
        {
            printf("%d ",head->val);
            head=head->next;
        }
    }
    printf("\n");
}
int main()
{
    ListNode *head=NULL;
    insertAtBeg(&head,3);
    insertAtBeg(&head,4);
    insertAtBeg(&head,4);
    insertAtBeg(&head,4);
    insertAtBeg(&head,2);

    //insertAtEnd(&head,10);
    //insertAtEnd(&head,11);
    //insertAtEnd(&head,12);
    //insertAtEnd(&head,13);
    //insertAtEnd(&head,14);

    //insertAtPos(&head,20,0);
    //insertAtPos(&head,22,2);
    //insertAtPos(&head,24,4);
    //insertAtPos(&head,26,6);
    //insertAtPos(&head,28,8);

    display(head);
    //delAtBeg(&head);
    //delAtBeg(&head);
    //delAtBeg(&head);

    //delAtEnd(&head);
    //delAtEnd(&head);
    //delAtEnd(&head);

    //delAtPos(&head,0);
    //delAtPos(&head,1);
    //delAtPos(&head,4);

    delKey(&head,4);
    delKey(&head,4);
    delKey(&head,4);    

    display(head);

    return 0;
}
