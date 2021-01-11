#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int findSmallestDifference(int arr1[],int arr2[], int m , int n)
{
   int l=0,r=0;
   int mindiff=std::numeric_limits<int>::max();
   sort(arr1,arr1+m);
   sort(arr2,arr2+n);
   while(l<m && r < n)
   {
       if(abs(arr1[l]-arr2[r])<mindiff)
       {
           mindiff=abs(arr1[l]-arr2[r]);
       }
       if(arr1[l] < arr2[r])
       {
           l++;
       }
       else
       {
           r++;
       }
   }
   return mindiff;
}


int main()
{

    int A[] = {1, 2, 11, 5}; 
    int B[] = {4, 12, 19, 23, 127, 235}; 
    int m = sizeof(A) / sizeof(A[0]); 
    int n = sizeof(B) / sizeof(B[0]); 
    cout << findSmallestDifference(A, B, m, n); 
  
    return 0;
}