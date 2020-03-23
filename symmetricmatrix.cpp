#include <bits/stdc++.h>
#define n 10
using namespace std;
//find transporse of a matrix
void transpose(int arr1[][n], int arr2[][n], int a)
{
   for (int i = 0; i < a; i++)
      for (int j = 0; j < a; j++)
         arr2[i][j] = arr1[j][i];
}
//check symmetric or not
bool check(int arr1[][n], int a)
{
   int arr2[a][n];
   transpose(arr1, arr2, a);
   for (int i = 0; i < a; i++)
      for (int j = 0; j < a; j++)
         if (arr1[i][j] != arr2[i][j])
            return false;
   return true;
}
int main(){

   int arr1[][n] = { { 1, 2, 3 },
      { 2, 2, 4 },
      { 3, 4, 1 } };
   if (check(arr1, 3))
      cout << "its a symmetric matrix";
   else
      cout << "its not a symmetric matrix";
   return 0;
}
