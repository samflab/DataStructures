#include<stdio.h>
#include<stdlib.h>

void insert(int data, int pri);
void del(int n);
void display();
struct node
{
    int data;
    int pri;
    struct node *next;
}*front=NULL;

int main()
{
    int choice=-1,data, pri, n;
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
        printf("Enter the priority of the data: \n");
        scanf("%d", &pri);
        insert(data,pri);
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


void insert(int data, int pri)
{
    struct node *temp, *p;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Overflow \n");
        return;
    }
    if((front == NULL)|| pri < front->pri)
    {
        temp->next=front;
        front=temp;
    }
    else
    {
        p=front;
        while((p->next!= NULL)&& (pri >= p->next -> pri))
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
     struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        printf("%d ", temp->pri);
        temp=temp->next;
    }
    printf("\n");
}

void del(int n)
{

}

void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        printf("%d ", temp->pri);
        temp=temp->next;
    }
    printf("\n");
}
