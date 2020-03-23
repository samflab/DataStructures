#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;

void create();
void display();
void insert_Beginning(int data);
void insert_Position(int data, int position);

int main()
{
    int n, data, choice=1;
    head = NULL;
    while(choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Insert node- at beginning\n");
        printf("4. Insert node- at a position\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Insert the data of the new node ");
                scanf("%d", &data);
                insert_Beginning(data);
                break;
            case 4:
                printf("Insert the data of the new node ");
                scanf("%d", &data);
                printf("Enter the position ");
                scanf("%d", &n);
                insert_Position(data,n);
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-2 \n");
        }
    }

    return 0;
}

void create()
{
    int i, data;

        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of head node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");

}

void display()
{
    struct node *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("%d  ",current->data);
            current = current->next;
        }while(current != head);
    }
}

void insert_Beginning(int data)
{
    struct node *newNode, *current;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        current = head;

        while(current->next != head)
        {
            current = current->next;

        }
        current->next = newNode;
        head = newNode;
        display();
        printf("NODE INSERTED SUCCESSFULLY\n");

    }
}

void insert_Position(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insert_Beginning(data);
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
}
