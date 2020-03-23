#include<stdio.h>
#include<conio.h>
#define MAX 50

int cqueue[MAX];
int front=1;
int rear=-1;
void insert(int val);
int del();
void traverse();

void main()
{
    int n, data, choice=1;
    while(choice != 0)
    {
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Delete element\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch(choice)
        {

            case 1:
                printf("Enter data of new node : ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
               traverse();
                break;

            case 3:
                del();
                break;

            case 0:
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-5");
                break;
        }
    }
}
void insert(int val)
{
    if((rear == MAX )&&(front ==0)||(front == rear+1))
      //  printf("Overflow condition met.");
    if(front == -1)
        front=rear=0;
    if(rear == MAX-1)
        rear=0;
    else
        rear=rear+1;
    cqueue[rear]=val;
    printf(" New element added\n");
}

int del()
{
    int temp;
    if(front == -1)
        printf("Underflow condition met.");
    temp=cqueue[front];
    if(front == rear)
        front=rear-1;
    else if(front==MAX-1)
        front =0;
    else
        front=front+1;
    printf("Element deleted\n");
    return temp;
}
void traverse()
{
    int temp=front;
    if (front ==- 1)
        printf("Underflow condition met.");
    int f=front, r=rear;
    if(front<=rear)
    {
        while(f <= r)
        {
            printf("%d ", cqueue[f]);
            f++;
        }
    }
    else
    {
        if(front <= MAX-1)
        {
            while(f <= MAX-1)
            {
                printf("%d",cqueue[f]);
                f++;
            }
            f=0;
        }
        while( f <= r)
        {
            printf("%d", cqueue[f]);
            f++;
        }
    }
    printf("\n");
}
