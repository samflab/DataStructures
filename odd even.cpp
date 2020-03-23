#include <bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start, end;
    int arr[6];
    int temp=0;
    cout<<"Enter the elements in the array.";
    for(int i=0; i<6; i++)
    {
        cin>>arr[i];
    }
    start = clock();
    for(int i=0; i<6; i=i+2)
    {

        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;

    }
    for(int i=0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }
        end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout <<endl<< "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
return 0;
}
