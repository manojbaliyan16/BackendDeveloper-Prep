#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
// Solve it with T(o) = O(n);
// this is the optimized solution 
// lets have a hash_table in the form of unordered_set

/*
    let Say tSum=10;
    X+Y=10;
    y=10-x
   Array : {3,5,-4,8,11,1,-1,6}
   y= 10-3=7; not in the has  hash_table {3:ture}
      10-5=5 ==============================={3:ture, 5:true}
      10+4=14=============================={3:ture, 5:true,-4:true}
      10-8=2============================={3:ture, 5:true,-4:true,2:true}
      10-11=-1============================{3:ture, 5:true,-4:true,2:true,11:true}
      10-1=9============================={3:ture, 5:true,-4:true,2:true,11:true:1:true}
      10-(-1)=11 already exist in the hash table 
      so 11 and -1 are the number 


*/

tuple<int,int> findSumofpair(std::array<int,8> &myarray, int size, int tSum)
{
    
    tuple <int, int> mypair;
    unordered_set<int> s;
  //sort(myarray.begin(),myarray.end());  // nlogn
    
    for(int i=0;i<size;i++)
    {
        int temp=tSum-myarray[i];
        if(s.find(temp)!=s.end())
        {
            mypair=make_tuple(temp,myarray[i]);
        }
        s.insert(myarray[i]);
        
    }
    return mypair;
}


int main()
{
    constexpr int size = 8;
    int tSum=10;
    std::array<int,size> myarray{3,5,-4,8,11,1,-1,6};
    tuple<int,int> mypair=findSumofpair(myarray,size,tSum);
    cout << get<0>(mypair) << " " << get<1>(mypair) << " " << endl;
    
    return 0;
}