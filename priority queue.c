#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void create();
void insert(int data);
void del(int n);
void display();
void check(int);

int prq[MAX];
int front, rear;

int main()
{
    int choice=-1,data, n;


    create();
    while(choice != 0)
    {
        printf("1. Insert an element: \n");
        printf("2. Delete an element: \n");
        printf("3. Display the queue: \n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice)
        {

    case 1:
        printf("Enter the data to be entered: \n");
        scanf("%d", &data);
        insert(data);
        break;
    case 2:
        printf("Enter the element to be deleted: \n");
        scanf("%d", &n);
        del(n);
        break;
    case 3:

        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid choice: \n");
        break;
        }

    }
}

void create()
{
    front=rear=-1;
}

void insert(int data)
{
    if(rear >= MAX-1)
    {
        printf("Overflow condition met. \n");
        return;
    }
    if((front == -1)&&(rear == -1))
    {
        front++;
        rear++;
        prq[rear]=data;
        return;
    }
    else
    {
        check(data);
    }
    rear++;
}

void check(int data)
{
  int i, j;
  for(i=0; i<=rear; i++)
  {
      if(data >= prq[i])
      {
          for(j=rear+1; j>i ; j--)
          {
              prq[j]=prq[j-1];
          }
          prq[i]=data;
          return;

      }
  }
  prq[i]=data;
}
void del(int n)
{
   int i;
   if((front==-1)&&(rear==-1))
   {
       printf("Underflow condition met. \n");
       return;
   }
   for(i=0; i<=rear; i++)
   {
       if(n == prq[i])
       {
           for(; i < rear; i++)
           {
               prq[i]=prq[i+1];
           }
       }
       prq[i]= 0;
       rear--;

       if(rear == -1)
        front =-1;
    return;
   }
    printf("\n%d not found in queue to delete", n);
}

void display()
{
    if((front == -1)&&(rear == -1))
    {
        printf("Queue is empty. \n");
        return;
    }
    for(; front<=rear; front++)
    {
        printf("%d ", prq[front]);
    }
    front=0;
    printf("\n");
}
