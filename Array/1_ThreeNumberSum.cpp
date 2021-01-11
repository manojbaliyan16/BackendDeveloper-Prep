#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
// Find the triple whose sum is equal to the target sum 
/*
	Time Complexity T =O(n^2)
	Space Complexity T=O(n)
*/
void findSumofTriplet(std::array<int,8> &myarray, int size, int tSum)
{
   
    int l,r;
    sort(myarray.begin(),myarray.end());
    // up to size -2 beacuse we have to to take 3 ptr and out of three ptr we have top move 2 by keeping 1 as fixed 
   for(int i=0;i<size-2;++i)
   {
       l=i+1;
       r=size-1;
       while(l<r)
       {
           if(myarray[i]+myarray[l]+myarray[r]==tSum)
           {
               cout << "Triplet is " << myarray[i] << ", " << myarray[l] << ", " << myarray[r] << endl;
           }
           if(myarray[i]+myarray[l]+myarray[r] < tSum)
           {
               l++;
           }
           else
           {
               r--;
           }
       }
   }
    
}


int main()
{
    constexpr int size = 8;
    int tSum=0;
    std::array<int,size> myarray{-8,-6,1,2,3,5,6,12};
    findSumofTriplet(myarray,size,tSum);
    
    return 0;
}