#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;

struct node1 {
    int data1;
    struct node1 * next1;
}*head1;


void create();
void display();
void insert_Beginning(int data);

void create_two();
void display_two();
void insert_Beginning_two(int data1);

int *merge(struct node *head, struct node1 *head1);
void sort();

int main()
{
    int data;
    head = NULL;
    create();
    insert_Beginning(10);
    insert_Beginning(20);
    insert_Beginning(30);
    insert_Beginning(40);
    insert_Beginning(50);
    insert_Beginning(60);
    insert_Beginning(70);
    printf("First list is: \n");
    display();
    printf("\n");

    int data1;
    head1=NULL;
    create_two();
    insert_Beginning_two(12);
    insert_Beginning_two(22);
    insert_Beginning_two(34);
    insert_Beginning_two(45);
    insert_Beginning_two(55);
    insert_Beginning_two(66);
    insert_Beginning_two(75);
    printf("Second list is: \n");
    display_two();
    printf("\n");

    merge(head, head1);
}
void create()
{
    int data=33;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
}

void create_two()
{
    int data1=1;
    head1 = (struct node *)malloc(sizeof(struct node));
    head1->data1 = data1;
    head1->next1 = NULL;
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

void display_two()
{
    struct node1 * temp1;
    if(head1 == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp1 = head1;

        while(temp1 != NULL)
        {
            printf("%d ",temp1->data1);
            temp1 = temp1->next1;
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

void insert_Beginning_two(int data1)
{
    struct node1 * newn1;

    if(head1 == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newn1 = (struct node *)malloc(sizeof(struct node));

        newn1->data1 = data1;
        newn1->next1 = head1;
        head1 = newn1;
    }
}

int *merge(struct node *head, struct node1 *head1)
{
    struct node *temp;
    if(head == NULL)
        return head;
    if(head1 == NULL)
        return head1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head1;
    head1=head;
    printf("Merged list is: \n");
    display();
    printf("After sorting: \n");
    sort();
    return temp;
}

void sort()
{
    struct node *f, *s;
    f=head;
    int temp;
    for(f=head; f->next!=NULL; f=f->next)
    {
        for(s=f->next; s!=NULL; s=s->next)
        {
            if(f->data > s->data)
            {
                temp=f->data;
                f->data=s->data;
                s->data=temp;
            }
        }
    }
    display();
}
