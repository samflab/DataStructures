#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


void create(int n);
void display();
void insert_Beginning(int data);
void insert_End(int data);
void insert_Position(int data, int position);
void delete_Beginning();
void delete_End();
void delete_Position(int n);
void search(int n);


int main()
{
    int n, data, choice=1;
    head = NULL;
    last = NULL;
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
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                create(n);
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

            case 0:
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }
    }

    return 0;
}

void create(int n)
{
    int i, data;
    struct node *newn;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;

        for(i=2; i<=n; i++)
        {
            newn = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newn->data = data;
            newn->prev = last;
            newn->next = NULL;
            last->next = newn;
            last = newn;
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void display()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DOUBLY LINKED LIST:\n");

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            n++;
            temp = temp->next;
        }
    }
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
        newn->prev = NULL;
        head->prev = newn;
        head = newn;

        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}



void insert_End(int data)
{
    struct node * newn;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newn = (struct node *)malloc(sizeof(struct node));
        newn->data = data;
        newn->next = NULL;
        newn->prev = last;
        last->next = newn;
        last = newn;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}



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
            newn->prev = temp;
            temp->next = newn;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }

}
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
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        free(temp);
    }
    printf("NODE DELETED SUCCESSFULLY \n");

}
void delete_End()
{
    struct node *temp;
    if(last==NULL)
    {
        printf("List is empty");
    }
    else
    {
       temp=last;
       last=last->prev;
       if(last!=NULL)
       {
           last->next=NULL;
       }
       free(temp);
    }
    printf("NODE DELETED SUCCESSFULLY \n");
}
void delete_Position(int n)
{
    struct node *temp;
    int i;
    temp=head;
    for(i=1; i<n && temp!=NULL; i++)
    {
        temp=temp->next;

    }
    if(temp!=NULL)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    free(temp);
    printf("NODE DELETED SUCCESSFULLY \n");
}
void search(int n)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            printf("Data found ");
        }
    }

}
