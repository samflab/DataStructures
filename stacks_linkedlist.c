#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10000
struct stack
{
    int data;
    struct stack *next;
} *top;
int size = 0;

void push(int element);
int  pop();


int main()
{
    int choice=-1, data;

    while(choice!=0)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                printf("Data => %d\n", data);
                break;

            case 3:
                printf("Stack size: %d\n", size);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void push(int element)
{
    if (size >= CAPACITY)
    {
        printf("Stack Overflow, can't add more element to stack.\n");
        return;
    }
    else
    {
        struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        size++;
    }
    printf("Data pushed to stack.\n");
}

int pop()
{
    int data = 0;
    struct stack * temp;
    if (size <= 0 || !top)
    {
        printf("Stack is empty.\n");
    }

    else
    {
    temp = top;
    data = top->data;
    top = top->next;
    free(temp);
    size--;
    }
    return data;
}
