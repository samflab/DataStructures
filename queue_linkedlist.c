#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
}*front,*rear;

void insert(int);
void del();
void traversal();

void main()
{
    int data,n,choice=-1;
    while(choice!=0)
    {
        printf("1. Insert an element in the queue\n");
        printf("2. Delete an element in the queue\n");
        printf("3. Display the queue\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the data of the new element :");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            del();
            break;
        case 3:
            traversal();
            break;
        case 0:
            break;
        default:
            printf("Invalid option. Please choice from 0-6");
            break;

        }//switch
    }//while
}//main
void insert(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Overflow");
    temp->next=NULL;
    temp->val=val;
    if(front==NULL)
        front=rear=temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void del()
{
    if(front==NULL)
        printf("Underflow");
    struct node *temp;
    temp=front;
    if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
    free(temp);
}
void traversal()
{
    if(front==NULL)
        printf("Underflow");
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d \t",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
