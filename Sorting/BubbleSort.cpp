
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bubbleSort(std::vector<int> &vec)
{
	int counter=0;
	bool isSorted=false;
	while(!isSorted)
	{
		isSorted=true;
		for(int i=0;i<vec.size()-1-counter;++i)
		{
			if(vec[i]>vec[i+1])
			{
				swap(vec[i],vec[i+1]);
				isSorted=false;
			}
		}
		counter+=1;
	}
	return vec;
}

int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=bubbleSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}
