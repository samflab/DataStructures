#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int arr[], int size);
void insert_Beginning(int arr[], int size, int data);
void insert_End(int arr[], int size, int data);
void insert_Position(int arr[], int size, int data, int position);
void delete_Beginning(int arr[], int size);
void delete_End(int arr[], int size);
void delete_Position(int arr[], int size, int n);
void concate(int arr[], int size);
void reverse(int arr[], int size);

int main()
{
    int size, i, arr[50], choice=-1, data, n;
    printf("Enter the size of the array ");
    scanf("%d",&size);
    printf("Enter the elements into the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    while(choice != 0)
    {
        printf("1. Insert element - at beginning\n");
        printf("2. Insert element - at end\n");
        printf("3. Insert element - at a position\n");
        printf("4. Display list\n");
        printf("5. Delete element - at beginning\n");
        printf("6. Delete element - at end\n");
        printf("7. Delete element - at a position\n");
        printf("8. Concatenate 2 arrays\n");
        printf("9. Reverse the array\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch(choice)
        {

            case 1:
                printf("Enter data of first node : ");
                scanf("%d", &data);
                insert_Beginning(arr,size,data);
                break;

            case 2:
                printf("Enter data of last node : ");
                scanf("%d", &data);
                insert_End(arr,size,data);
                break;

            case 3:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);
                insert_Position(arr,size,data, n);
                break;

            case 4:
                display(arr,size);
                break;

            case 5:
                delete_Beginning(arr,size);
                break;

            case 6:
                delete_End(arr,size);
                break;

            case 7:
                 printf("Enter the position where you want to delete the node: ");
                scanf("%d", &n);
                delete_Position(arr,size,n);
                break;
            case 8:
                concate(arr, size);
                break;
            case 9:
                reverse(arr,size);
                break;

            case 0:
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-8");
        }//switch
    }//while

    return 0;
} //main





void display(int arr[], int size)
{
   for(int i=0; i<size; i++)
   {
       printf("%d ",arr[i]);
   }
   printf("\n");
}



void insert_Beginning(int arr[], int size, int data)
{
    for(int i=0; i<size; i++)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=data;
}



void insert_End(int arr[], int size, int data)
{
    arr[size-1]=data;
}



void insert_Position(int arr[], int size,int data, int position)
{
   for(int i=10; i>=position; i--)
   {
       arr[i]=arr[i-1];
   }
   arr[position-1]=data;
}

void delete_Beginning(int arr[], int size)
{
    arr[0]=0;
    printf("The array is:\n");
    for(int i=1; i<size; i++)
    {
        printf("%d",arr[i]);
    }
}
void delete_End(int arr[], int size)
{
    arr[size-1]=0;
    printf("The array is:\n");
    for(int i=0; i<size-2; i++)
    {
        printf("%d",arr[i]);
    }
}
void delete_Position(int arr[], int size,int n)
{
    for(int i=n; i<=size; i++)
    {
        arr[i-1]=arr[i];
    }
    size--;
}
void concate(int arr[], int size)
{
   int i, len, arr2[20], ori, j=0;
   printf("Enter the size of the 2nd array: ");
   scanf("%d", &len);
   printf("Enter the elements into the array: ");
   for(i=0; i<len; i++)
   {
       scanf("%d", &arr2[i]);
   }
   ori=size;
   size+=len;
   for(i=ori; i<=size; i++)
   {
       arr[i]=arr2[j];
       j++;
   }
}
void reverse(int arr[], int size)
{
    printf("The reversed array is: ");
    for(int i=size; i>=0; i--)
    {
        printf("%d",arr[i]);
    }
}

