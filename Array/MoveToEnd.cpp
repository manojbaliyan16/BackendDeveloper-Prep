#include <vector>
#include <array>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

// Move a traget Element to the end 



vector<int> &moveToEnd(vector<int> &myvec, int elem)
{
    int i=0;
    int j=myvec.size()-1;
    while(i<j)
    {
        while((i<j) && myvec[j]==elem)
        {
            j--;
        }
        if(myvec[i]==elem)
        {
            swap(myvec[i],myvec[j]);
            
        }
        i++;
        
    }
    return myvec;
}


int main()
{
    std::vector<int> myvec{2, 1, 2, 2, 2, 3, 4, 2};
    int element=2;
    vector<int> myUpdatedVec= moveToEnd(myvec,element);
    for(const auto elem:myUpdatedVec)
    cout << elem << " " ;
    
    return 0;
}