#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the value of n and m";
    cin>>n>>m;
    int a[n][m],b[n][m],prod[n][m];
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
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            prod[i][j]=0;

        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<m; k++)
            {
                prod[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    cout<<"The product is:";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<prod[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}
