#include<stdio.h>
#include<conio.h>
int queue[50];
int front=-1, rear=-1;
void insert(int);
void del();
void traversal();
void search(int n);
void sort();
void main()
{
    int data,n,choice=-1;
    while(choice!=0)
    {
        printf("1. Insert an element in the queue\n");
        printf("2. Delete an element in the queue\n");
        printf("3. Display the queue\n");
        printf("4. Sort the queue\n");
        printf("5. Search an element in an queue\n");
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
        case 4:
            sort();
            break;
        case 5:
            printf("Enter the element you want to search: ");
            scanf("%d",&n);
            search(n);
            break;
        case 0:
            break;
        default:
            printf("Invalid option. Please choice from 0-5");
            break;

        }//switch
    }//while
}//main
void insert(int val)
{
    if(rear>=49)
        printf("Overflow");
    if(front==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else
    {
        rear=rear+1;
        queue[rear]=val;
    }
}
void del()
{
    if(front <0)
    {
        printf("Underflow");
        return;
    }
    else if(front==rear)
    {
        queue[front]='\0';
        front=rear=-1;
    }
    else
    {
        queue[front]='\0';
        front=front+1;
    }
}
void traversal()
{
    if(front<0)
    {
        printf("Underflow");
        return;
    }
    int temp=front;
    while(temp<=rear)
    {
        printf("%d ",queue[temp]);
        temp=temp+1;
    }
    printf("\n");
}
void search(int n)
{
    int temp=front;
    while(temp<=rear)
    {
        if(queue[temp]==n)
        {
            printf("Element found \n");
        }
        temp=temp+1;
    }
}
void sort()
{
    int size=sizeof(queue)/sizeof(queue[0]);
    printf("%d",size);

        int i, j, a;


        for (i = 0; i <size; ++i)
        {

            for (j = i + 1; j < size; ++j)
            {

                if (queue[i] > queue[j])
                {

                    a =  queue[i];
                    queue[i] = queue[j];
                    queue[j] = a;

                }

            }

        }

        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < size ; ++i)
        {
        	if(queue[i]!=0)
        	{

            printf("%d", queue[i]);}
      }
      printf("\n");

}
