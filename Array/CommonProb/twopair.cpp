#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_set>
#include <tuple>
using namespace std;

tuple<int, int> PairSum(std::vector<int> &vec,int tsum)
{	tuple<int,int> mypair;
	unordered_set<int> s;
	for(int i=0;i<vec.size();++i)
	{
		int y= tsum-vec[i];
		if(s.find(y)!=s.end())
		{
			mypair=make_tuple(vec[i],y);
		}
		s.insert(vec[i]);
	}
	return mypair;
}
int main()
{
	int tsum= -2;
	std::vector<int> vec{0, -1, 2, -3, 1};
	tuple<int,int> pairval=PairSum(vec,tsum);
	cout << get<0>(pairval) <<", "<<get<1>(pairval) << endl; 
	
	return 0;
}
