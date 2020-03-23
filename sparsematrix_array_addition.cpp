#include<iostream>

using namespace std;

int main()
{
    // sparse matrix of class 5x6 with 6 non-zero values
    int sparseMatrix[5][6] =
    {
        {0 , 0 , 0 , 0 , 9, 0 },
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };
    int sparseMatrix1[5][6] =
    {
        {2 , 0 , 0 , 0 , 2, 0 },
        {3 , 0 , 0 , 0 , 0, 0 },
        {0 , 4 , 0 , 7 , 0, 0 },
        {0 , 0 , 8 , 0 , 0, 0 },
        {0 , 0 , 2 , 0 , 0, 3 }
    };
    int sumMatrix[5][6] =
    {
        {0 , 0 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 0 }
    };
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<6; j++)
        {
            sumMatrix[i][j]+=sparseMatrix[i][j]+sparseMatrix1[i][j];
        }
    }
    int size = 0;
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 6; column++)
            if (sumMatrix[row][column] != 0)
                size++;

    // Defining result Matrix
    int resultMatrix[3][size];
    int k = 0;
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 6; column++)
            if (sumMatrix[row][column] != 0)
            {
                resultMatrix[0][k] = row;
                resultMatrix[1][k] = column;
                resultMatrix[2][k] = sumMatrix[row][column];
                k++;
            }

    // Displaying result matrix
    cout<<"Triplet Representation : "<<endl;
    for (int row=0; row<3; row++)
    {
        for (int column = 0; column<size; column++)
            cout<<resultMatrix[row][column]<<" ";

        cout<<endl;
    }
    return 0;
}
