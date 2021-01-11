#include <iostream>
#include <memory>

using namespace std;
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};


int main()
{
	unique_ptr<Resource> res(new Resource());
	return 0;
}