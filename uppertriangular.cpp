#include <bits/stdc++.h>

using namespace std;

int main()
{
    clock_t start, end;
    int n,m;
    start = clock();
    cout<<"Enter the value of n and m";
    cin>>n>>m;
    int a[n][m];
    cout<<"Enter the elements into A array";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];

        }
    }
    int flag=1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if((i<j) &&(a[i][j]!=0))
            {
                flag =0;
            }
            else
            {
                flag=1;
            }
        }
         if(flag==1)
            {
                cout<<"It is an upper triangular matrix"<<endl;
            }
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;


    return 0;
}
