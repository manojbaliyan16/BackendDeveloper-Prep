#include <iostream>

using namespace std;
template<class T>

class auto_ptr1
{
	T *m_ptr;
	public:
		auto_ptr1(T *ptr=nullptr):m_ptr(ptr)
		{
			cout << "default ctor " << endl;
		}
		~auto_ptr1()
		{
			cout << "default Dtor " << endl;
			delete m_ptr;
		}
		// Overload the * operator and operator -> so that auto_ptr1 acts like m_ptr
		T& operator*() const
		{
			cout << "* overload  " << endl;
			return *m_ptr;
		}
		T* operator->() const
		{
			cout << "-> overload  " << endl;
			return m_ptr;
		}
};

class Resource
{
	public:
		Resource()
		{
			cout << "Resouce acquired " << endl;
		}
		~Resource()
		{
			cout << "Resouce destroyed " << endl;
		}
		void SayHi()
		{
			cout << "Hi " << endl;
		}
};

void dosomething()
{
	auto_ptr1<Resource> ptr(new Resource());// ptr owns the Resource obj now 
	int x{};
	cout << "Enter the value of x" << endl;
	cin >> x;
	cin.ignore();
	if(x==0)
		return ;
	ptr->SayHi();
}
int main()
{
	//dosomething();
	auto_ptr1<Resource> res1(new Resource());
	auto_ptr1<Resource> res2(res1);
	auto_ptr1<Resource> res3=res1;
	return 0;
}
