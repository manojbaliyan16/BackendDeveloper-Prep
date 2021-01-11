#include <iostream>
#include <memory>


using namespace std;



class Resource
{
public:

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main(int argc, char const *argv[])
{
//	Resource *res = new Resource();
	auto ptr1 = std::make_shared<Resource>();
//	std::shared_ptr<Resource> ptr1(res);
	{
	//		std::shared_ptr<Resource> ptr2(ptr1);
		auto ptr2=ptr1;
		std::cout << "Killing one shared pointer\n";
	}

	std::cout << "Killing another shared pointer\n";
	return 0;
}