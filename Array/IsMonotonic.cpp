#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
// If any array eitheris in increasing order or Decreasing order than it is called Monotonic array

bool isIncreasing(vector<int> &vec)
{
    for(int i=1;i<vec.size();++i)
    {
        if(vec[i]<vec[i-1])
        return false;
    }
    return true;
}


bool isDecreasing(vector<int> &vec)
{
    for(int i=1;i<vec.size();++i)
    {
        if(vec[i] > vec[i-1])
        return false;
    }
    return true;
}
bool isMonotonic(vector<int> &vec)
{
    return isIncreasing(vec) || isDecreasing(vec);
}

int main()
{

    //vector<int> vec{-1,-5,-10,-1100,-1100,-1101,-1102,-9001};

    vector<int> vec{1,1,1,2,3,4,3,4,5};
    cout << std::boolalpha << isMonotonic(vec) << endl;
    return 0;
}
