/**
 * C++ program to add two polynomials through arrays
 */
#include<iostream>
using namespace std;

/*
* List of functions to be used in the program
*/

void display(int n, int arr[]);
void add(int n, int arr[], int arr1[]);
void mul(int n, int arr[], int arr1[]);
int main()
{
    int arr[10],arr1[10];
    int n;
    cout<<"Enter the number of terms in your polynomial\n"; //the maximum number of x
    cin>>n;
    cout<<"Enter the first polynomial\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the coefficient of x^"<<i<<" "; //according to the power of x, coefficients will
        cin>>arr[i];                                // be entered and stored in an array
    }
    cout<<"Enter the second polynomial\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the coefficient of x^"<<i<<" ";
        cin>>arr1[i];
    }
    cout<<"The polynomial that you entered are as follows:\n";
    cout<<"First Polynomial:\n";
    display(n,arr);             //display the 1st entered polynomial
    cout<<"Second Polynomial:\n";
    display(n,arr1);            //display the 2nd entered polynomial
    add(n,arr,arr1);            //for adding of polynomials
    mul(n,arr,arr1);            //for multiplication of polynomials
    return 0;
}

void add(int n, int arr[], int arr1[])
{
    int sum[10];                //third array to store the result
    for(int i=0; i<n; i++)
    {
        sum[i]=arr[i]+arr1[i];      //adding the same indexed numbers together and storing it in the sum array
    }
    cout<<"The sum of both the polynomials are:\n";
    display(n,sum);
}

void mul(int n, int arr[], int arr1[])
{
    int mul[10];
    for(int i=0; i<n; i++)
    {
        mul[i]=arr[i]*arr1[i];  //multiplying the same indexed numbers together and storing it in the mul array
    }
    cout<<"The product of both the polynomials are:\n";
    display(n,mul);
}

void display(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"x^"<<i<<" ";
    }
    cout<<endl;
}
