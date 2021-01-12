#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int largestElement(std::vector<int> &v)
{
	int largestElement=numeric_limits<int>::min();
	for(auto elem:v)
	{
		if(elem > largestElement)
		{
			largestElement=elem;
		}

	}
	return largestElement;
}
int main()
{
	std::vector<int> v{1,2,3,50,30,99};
	cout << largestElement(v) << endl;
}
