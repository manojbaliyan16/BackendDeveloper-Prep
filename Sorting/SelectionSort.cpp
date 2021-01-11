#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// T(n)=o(n^2)
// S(n)=o(1)
vector<int> SelectionSort(std::vector<int> &vec)
{
	// 1. First assume complete list a unsorted list 
	// 2. Select the min and append at the beginig by swaping 
	// 3. Now 2nd element onwards is the unsorted list 
		// repeat  1 and 2
	int currentIndex=0;
	
	while(currentIndex < vec.size()-1)
	{
		
		int smallestIndex=currentIndex;
		for(int i=currentIndex+1;i<vec.size();++i)
		{
		
			if(vec[smallestIndex] > vec[i])
				smallestIndex=i;
		}
		
		swap(vec[currentIndex],vec[smallestIndex]);
		currentIndex++;
	}

	return vec;
}																																																																																																																																																																																																																																																																																																																																																																											

int main()
{

    vector<int> result{8,5,2,9,5,6,3};
    vector<int> res=SelectionSort(result);
    for(auto const &elem:res)
    cout << elem << " ";
    cout << endl;
    return 0;
}