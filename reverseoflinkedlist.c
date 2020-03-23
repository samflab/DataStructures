#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;
void create();
void display();
void insert_Beginning(int data);
void reverse();
int main()
{
    int n, data;
    head = NULL;
    create();
    insert_Beginning(10);
    insert_Beginning(20);
    insert_Beginning(30);
    insert_Beginning(40);
    insert_Beginning(50);
    insert_Beginning(60);
    insert_Beginning(70);
    printf("The list before reversing is:\n");
    display();
    reverse();
    printf("The list after reversing is: \n");
    display();

}
void create()
{
    int data=33;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
}
void display()
{
    struct node * temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void insert_Beginning(int data)
{
    struct node * newn;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newn = (struct node *)malloc(sizeof(struct node));

        newn->data = data;
        newn->next = head;
        head = newn;
    }
}
void reverse()
{
    struct node *prev, *curr;
    if(head!=NULL)
    {
        prev=head;
        curr=head->next;//second node
        head=head->next;//head moves till the last node
        prev->next=NULL; //first node as last node
        while(head!=NULL)
        {
            head=head->next;
            curr->next=prev;
            prev=curr;
            curr=head;
        }
        head=prev;

    }

}
