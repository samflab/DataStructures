#include <bits/stdc++.h>

using namespace std;

int main()
{
    clock_t start, end;
    int n,m,i,q;
    cout<<"Number of elements in A array: ";
    cin>>n;
    cout<<"Number of elements in B array: ";
    cin>>m;
    int k=n+m;
    int a[n], b[m], merge[k];
    cout<<"Enter the elements into A array: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the elements into B array ";
    for(i=0; i<m; i++)
    {
        cin>>b[i];
    }
//merge
    start = clock();
    for(i=0; i<n; i++)
    {
        merge[i]=a[i];
    }
    for(int j=n, i=0; j<k, i<m; j++, i++)
    {
        merge[j]=b[i];
    }
    cout<<"Now the new array after merging is :\n ";
    sort(merge, merge+k);
    for(i=0; i<k; i++)
    {
        cout<<merge[i]<<" ";
    }
     end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout <<endl<< "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
