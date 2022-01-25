#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node * next;
}ListNode;
ListNode * insertAtBeg(ListNode *head,int value)
{
    ListNode *temp=NULL;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=value;
    temp->next=head;
    head=temp;
    return head;
}
ListNode *insertAtEnd(ListNode *head,int value)
{
    ListNode *temp=NULL;
    ListNode *ptr=head;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}
ListNode *insertAtPos(ListNode *head,int value,int pos)
{
    ListNode *temp=NULL;
    ListNode *ptr=head;
    temp=(ListNode *)malloc(sizeof(ListNode));
    if(temp==NULL)
    {
        printf("Memory Error....");
    }
    temp->val=value;
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
            
    return head;
}
ListNode * delAtBeg(ListNode *head)
{
    if(head==NULL)
    {
        printf("List is empty. ");
    }
    ListNode *temp=head;
    head=head->next;
    printf("\nDeleted element is : %d \n",temp->val);
    free(temp);
    return head;
}
ListNode * delAtEnd(ListNode * head)
{
    if(head==NULL)
    {
        printf("List is empty. ");
    }
    ListNode *temp=head;
    ListNode *ptr=NULL;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=NULL;
    printf("\nDeleted element is  : %d \n",ptr->val);
    free(ptr);
    return head;
}
ListNode * delAtPos(ListNode *head,int pos)
{
    if(head==NULL)
    {
        printf("List is empty. ");
        return NULL;
    }
    ListNode *temp=head;
    ListNode *ptr=NULL;
    if(pos==0)
    {
        ptr=head;
        head=head->next;
        printf("\nDeleted element is : %d\n",ptr->val);
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
    return head;
}
ListNode * delKey(ListNode * head,int key)
{
    if(head==NULL)
    {
        printf("\nList is empty. \n");
    }
    ListNode *temp=head;
    ListNode *ptr=NULL;
    while(temp->next)
    {
        if(temp->val==key)
        {
            ptr=temp;
            head=head->next;
            temp=temp->next;
            printf("\nDeleted element is : %d\n",ptr->val);
            free(ptr);
        }
        else if(temp->next->val==key)
        {
            ptr=temp->next;
            temp->next=temp->next->next;
            printf("\nDeleted element is : %d\n",ptr->val);
            free(ptr);
        }
        else
        {
            temp=temp->next;
        }
    }
    if(head->val==key)
    {
        head=NULL;
    }
    return head;
}
void displayAleternate(ListNode *head)
{
    ListNode * ptr=head;
    while(ptr)
    {
        printf("%d ",ptr->val);
        ptr=ptr->next->next;
    }
    printf("\n");
}
void display(ListNode *head)
{
    ListNode *temp=head;
    printf("\n Elements of list are : ");
    while(temp)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    ListNode *head=NULL;

    head=insertAtBeg(head,31);
    head=insertAtBeg(head,32);
    head=insertAtBeg(head,33);
    head=insertAtBeg(head,34);
    head=insertAtBeg(head,35);

    head=insertAtEnd(head,36);
    head=insertAtEnd(head,37);
    head=insertAtEnd(head,38);
    head=insertAtEnd(head,39);
    head=insertAtEnd(head,10);   

    //head=insertAtPos(head,16,0);
    //head=insertAtPos(head,17,1);
    //head=insertAtPos(head,18,2);
    //head=insertAtPos(head,19,3);
    //head=insertAtPos(head,20,4); 

    display(head);
    //head=delAtBeg(head);
    //head=delAtEnd(head);
    head=delAtPos(head,2);
   // head=delKey(head,3);
    display(head);
    //displayAleternate(head);
    return 0;
}