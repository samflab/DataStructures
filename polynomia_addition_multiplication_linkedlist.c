/* C Program to add two polynomials through Linked List*/
#include<stdio.h>
#include<stdlib.h>
//structure of the two linked lists
struct node
{

    int data;
    int expo;
    struct node *next;
}*head;

struct node1
{
    int expo1;
    int data1;
    struct node1 *next1;
}*head1;

//list of functions to be used in the program

void add(struct node *head, struct node1 *head1);
void mul(struct node *head, struct node1 *head1);
void create(int n);
void create_second(int n);
void create_third(int n, int data, int expo);
void display(struct node *head);
void display_second(struct node1 *head1);
void display_third(struct node2 *head2);

int main()
{
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&n); //number of nodes in the linked list = number of terms in the polynomial
    create(n);      //creating the 1st polynomial and storing it in the linked list
    create_second(n); ////creating the 2nd polynomial and storing it in the linked list
    printf("The first polynomial is:\n");
    display(head);
    printf("The second polynomial is:\n");
    display_second(head1);
    add(head, head1);   //add both the polynomials
    mul(head, head1);   //multiply both the polynomials
}

void create(int n)
{
    struct node *newn, *temp;
    int data, i,expo;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Empty list");
    }
    //creating the head node
    printf("Enter the first polynomial\n");
    printf("Enter the data of node 1:");
    scanf("%d", &data);
    printf("Enter the exponent of node 1:");
    scanf("%d", &expo);

    head->data=data;
    head->expo=expo;
    head->next=NULL;

    temp=head;
    //creating all the other nodes
    for(i=2; i<=n; i++)
    {
        newn=(struct node *)malloc(sizeof(struct node));
        if(newn==NULL)
        {
            printf("Empty list");
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        printf("Enter the exponent of node %d: ", i);
        scanf("%d", &expo);
        newn->data=data;
        newn->expo=expo;
        newn->next=NULL;
        temp->next=newn;
        temp=temp->next;

    }
}

void create_second(int n)
{
    struct node1 *newn, *temp;
    int data, i,expo;
    head1=(struct node1 *)malloc(sizeof(struct node1));
    if(head1==NULL)
    {
        printf("Empty list");
    }
    printf("Enter the second polynomial\n");
    printf("Enter the data of node 1:");
    scanf("%d", &data);
    printf("Enter the exponent of node 1:");
    scanf("%d", &expo);
    head1->data1=data;
    head1->expo1=expo;
    head1->next1=NULL;

    temp=head1;
    for(i=2; i<=n; i++)
    {
        newn=(struct node1 *)malloc(sizeof(struct node1));
        if(newn==NULL)
        {
            printf("Empty list");
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        printf("Enter the exponent of node %d: ",i);
        scanf("%d", &expo);
        newn->data1=data;
        newn->expo1=expo;
        newn->next1=NULL;
        temp->next1=newn;
        temp=temp->next1;

    }
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        printf("x^%d ",temp->expo);
        temp=temp->next;
    }
    printf("\n");
}

void display_second(struct node1 *head1)
{
    struct node1 *temp;
    temp=head1;
    while(temp!=NULL)
    {
        printf("%d",temp->data1);
        printf("x^%d ",temp->expo1);
        temp=temp->next1;
    }
    printf("\n");
}

void add(struct node *head, struct node1 *head1)
{
    //taking two temp nodes and assigning them the value head
    struct node *temp;
    struct node1 *temp1;
    temp=head;
    temp1=head1;
    int d,e;
    printf("The sum of the polynomials are:\n");
    while((temp!=NULL)&&(temp1!=NULL))
    {
            if(temp->expo==temp1->expo1)
            {
                d=temp->data+temp1->data1; //adding both the polynomials with the same coefficients
                e=temp->expo;
                //displaying the results
                printf("%d",d);
                printf("x^%d ",e);
            }
            temp=temp->next; temp1=temp1->next1;
    }
    printf("\n");
}

void mul(struct node *head, struct node1 *head1)
{
    struct node *temp;
    struct node1 *temp1;
    temp=head;
    temp1=head1;
    int d,e;
    printf("The product of the polynomials are:\n");
    while((temp!=NULL)&&(temp1!=NULL))
    {
            if(temp->expo==temp1->expo1)
            {
                d=temp->data*temp1->data1; //multiplying both the polynomials with the same coefficients
                e=temp->expo;
                printf("%d",d);
                printf("x^%d ",e);
            }
            temp=temp->next; temp1=temp1->next1;
    }
    printf("\n");
}
