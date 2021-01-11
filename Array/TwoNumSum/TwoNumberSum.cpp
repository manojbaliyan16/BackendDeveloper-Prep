
#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

// T(o) = O(nlogn)

tuple<int,int> findSumofTwoNumber(std::array<int,8> &myarray, int size, int tSum)
{
    
    tuple <int, int> mypair;
   sort(myarray.begin(),myarray.end());
    int *ptr1, *ptr2;
    ptr1=myarray.begin();
    ptr2=myarray.end()-1;
    for(int i=0;i<size;i++)
    {
        int sum=*ptr1 + *ptr2;
        if(sum==tSum)
        {

            mypair = make_tuple(*ptr1,*ptr2);
            break;
        }
        else if(sum<tSum)
        {
            ptr1++;
        }
        else if(sum > tSum)
        {
            ptr2--;
        }
    }
    return mypair;
}


int main()
{
    constexpr int size = 8;
    int tSum=10;
    std::array<int,size> myarray{3,5,-4,8,11,-1,6};
    tuple<int,int> mypair=findSumofTwoNumber(myarray,size,tSum);
    cout << get<0>(mypair) << " " << get<1>(mypair) << " " << endl;
    
    return 0;
}
