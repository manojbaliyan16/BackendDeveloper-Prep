#include <iostream>

using namespace std;
template<class T>
class auto_ptr3
{
	T *m_ptr;
public:
	// default 
	auto_ptr3(T *ptr=nullptr):m_ptr(ptr)
	{
		// default 
	}
	~auto_ptr3()
	{
		delete m_ptr;
	}
	// overload * and -> 
	T& operator*()const{ return *m_ptr;}
	T* operator->()const{ return m_ptr;}
	// copy ctor move semantic 
	auto_ptr3(const auto_ptr3 &obj)
	{
		cout << "copy ctor  " << endl;
		m_ptr= new T;
		*m_ptr=*obj.m_ptr;
		//obj.m_ptr=nullptr;

	}
	// assignment operator overload 
	auto_ptr3& operator=(const auto_ptr3 &obj)
	{
		cout << "= operator overload  " << endl;
		if(&obj==this)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr= new T;
		m_ptr= obj.m_ptr;
		return *this;
	}
};

class Resource
{
public:
	Resource()
	{
		cout << "Acquired the Resource " << endl;
	}
	~Resource()
	{
		cout << "Destroyed the Resource " << endl;	
	}
};
auto_ptr3<Resource> generateResource()
{
	auto_ptr3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}
int main()
{	
	
	auto_ptr3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment
	return 0;
}