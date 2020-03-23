#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void insert_at_begining(struct node **, int value);
void insert_at_end(struct node **, int value);
void insert_in_middle(struct node **, int pos, int value);
void delete_at_begining(int value);
void delete_at_end(int value);
void delete_in_middle(int value);
void print();

int main()
{
    int value;
    int choice;
    struct node *p= NULL;
    printf("Enter the choice number");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("Enter another choice");
        int choice1;
        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            insert_at_begining(&p,1);
            insert_at_begining(&p,2);
            insert_at_begining(&p,3);
            insert_at_begining(&p,4);
            print();
        break;
        case 2:
            insert_at_end(&p,1);
            insert_at_end(&p,2);
            insert_at_end(&p,3);
            insert_at_end(&p,4);
            print();
        break;
        case 3:
            int pos;
            printf("Enter the position where you want a new value");
            scanf("%d", &pos);
            insert_in_middle(&p,pos,value);
            insert_in_middle(&p,pos,value);
            insert_in_middle(&p,pos,value);
            insert_in_middle(&p,pos,value);
            print();
        break;
        }
        break;
    case 2:
        print();


    }
}
//insertion in the beginning of the list

void insert_at_begining(struct node **q, int value)
{

    struct node *n1;
    n1=(struct node*)malloc(sizeof(struct node));
    n1->data=value;
    n1->next=*q;
    *q=n1;
}
//insertion at end of the linked list

void insert_at_end(struct node **q, int value)
{

    struct node *n1, *n2;

       if(*q==NULL) //check for an empty linked list
       {
           n1=(struct node*)malloc(sizeof(struct node));
           n1->data=value;
           n1->next=NULL;
           *q=n1;
       }
       else
       {
           n1=*q;
           while(n1->next!=NULL)
           {
               n1=n1->next;
               n2=(struct node*)malloc(sizeof(struct node));
               n2->data=value;
               n2->next=NULL;
               n1->next=n2;

           }
      }
}
//insertion in the middle
void insert_in_middle(struct node **q, int pos, int value)
{
    struct node *n1, *n2;
    n1=q;
    for(int i=0; i<pos; i++)
    {
        n1=n1->next;
        if(n1==NULL)
        {
            printf("The elements are less than %d", pos);
        }
    }
    n2=(struct node*)malloc(sizeof(struct node));
    n2->data=value;
    n2->next=n1;
    n1->next=n2;
}
//display the linked list
void print()
{
    struct node *n1;
    while(n1!=NULL)
    {

        printf("%d ",n1->data);
        n1=n1->next;

    }
}
