#include <bits/stdc++.h>
using namespace std;

int main()
{
    clock_t start, end;
    int a[10], n,i;
    cout<<"Enter the number to convert:";
    cin>>n;
    start = clock();
    for(i=0; n>0; i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    cout<<"Binary of the given number: ";
    for(i=i-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout <<endl<< "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
