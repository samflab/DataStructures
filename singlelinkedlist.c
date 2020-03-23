#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;


void create();
void display();
void insert_Beginning(int data);
void insert_End(int data);
void insert_Position(int data, int position);
void delete_Beginning();
void delete_End();
void delete_alternate();
void delete_Position(int n);
void search(int n);


int main()
{
    int n, data, choice=1;
    head = NULL;
    while(choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at a position\n");
        printf("5. Display list\n");
        printf("6. Delete node - at beginning\n");
        printf("7. Delete node - at end\n");
        printf("8. Delete node - at a position\n");
        printf("9. Search an element\n");
        printf("10. Alternate delete\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);
                insert_Beginning(data);
                break;

            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);
                insert_End(data);
                break;

            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);
                insert_Position(data, n);
                break;

            case 5:
                display();
                break;

            case 6:
                delete_Beginning();
                break;

            case 7:
                delete_End();
                break;

            case 8:
                 printf("Enter the position where you want to delete the node: ");
                scanf("%d", &n);
                delete_Position(n);
                break;
            case 9:
                printf("Enter the element to be searched");
                scanf("%d", &n);
                search(n);
            case 10:
                delete_alternate();
                break;

            case 0:
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }
    }

    return 0;
}
//creating the 1st node only
void create()
{
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of 1 node: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
}


//print all the values in the linked list
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
        printf("SINGLY LINKED LIST:\n");

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}


//insert a value at the beginning of the list
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

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}


//insert the value at the end of the linked list
void insert_End(int data)
{
    struct node * newn, *temp;
    temp=head;
    newn = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newn->data = data;
        newn->next = NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}


//insert a value in between 2 existing values
void insert_Position(int data, int position)
{
    int i;
    struct node * newn, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
            newn = (struct node *)malloc(sizeof(struct node));

            newn->data = data;
            newn->next = temp->next;
            temp->next = newn;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }

}

//delete a node at beginning
void delete_Beginning()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    printf("NODE DELETED SUCCESSFULLY \n");

}

//delete a node at the beginning
void delete_End()
{
    struct node *temp,*temp1;

    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        temp1=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
    printf("NODE DELETED SUCCESSFULLY \n");
}


//delete a node between 2 existing nodes
void delete_Position(int n)
{
    struct node *temp, *temp1;
    temp=head;
    temp1=head;
    if(temp==NULL)
    {
        printf("This is an empty list");
    }
    else
    {
        for(int i=2; i<n; i++)
        {
            temp1=temp;
            temp=temp->next;
            if(temp==NULL)
                break;
        }
        if(temp==head)
        {
            head=head->next;
        }
        temp1->next=temp->next;

    }
    free(temp);
    printf("NODE DELETED SUCCESSFULLY \n");
}


//search a node in the linked list
void search(int n)
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==n)
        {
            printf("Data found ");
        }
        temp=temp->next;
    }
    printf("\n");
}

void delete_alternate()
{
    struct node *temp, *h, *temp1;
    temp=head;
    temp1=head->next;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next=temp1->next;
        free(temp1);
        temp=temp->next;
        if(temp!=NULL)
        {
            temp1=temp->next;
        }
    }
    printf("AFTER ALTERNATE DELETION:\n");
    display();

}
