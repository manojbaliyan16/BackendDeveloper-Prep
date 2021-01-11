#include <iostream>
#include <memory>
using namespace std;



class Resource
{
public:

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource\n";
		return out;
	}
};

void takeOwnership(std::unique_ptr<Resource> res)
{
     if (res)
          std::cout << *res << '\n';
} 

int main(int argc, char const *argv[])
{
	auto ptr{make_unique<Resource>()};
	takeOwnership(std::move(ptr));
	return 0;
}