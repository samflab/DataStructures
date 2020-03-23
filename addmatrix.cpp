#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    clock_t start, end;
    cout<<"Enter the value of n and m";
    cin>>n>>m;
    int a[n][m],b[n][m],sum[n][m];
    cout<<"Enter the elements into A array";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];

        }
    }
    cout<<"Enter the elements into B array";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>b[i][j];

        }
    }
    start = clock();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            sum[i][j]=a[i][j]+b[i][j];

        }
    }
    cout<<"The sum is:";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<sum[i][j]<<" ";

        }
        cout<<endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
