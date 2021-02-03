#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> InsertionSort(std::vector<int> &vec)
{
	for(int i=0;i<vec.size();i++)
    {
        int j=i;
        while(j > 0 && vec[j] < vec[j-1])
        {
            swap(vec[j],vec[j-1]);
            j-=1;
        }

    }
	return vec;
}

int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=InsertionSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}
