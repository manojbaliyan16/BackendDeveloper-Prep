#include <iostream>
using namespace std;


template<class T>
class Auto_ptr4
{
	T *m_ptr;
public:
	// default ctor 

	Auto_ptr4(T *ptr=nullptr):m_ptr(ptr)
	{
		cout << "Default ctor " << endl;
	}
	// default dtor 
	~Auto_ptr4()
	{
		delete m_ptr;
	}
	// Copy Ctor
	Auto_ptr4(const Auto_ptr4 &obj)
	{
		m_ptr = new T;
		*m_ptr= *obj.m_ptr;
	}
	// Assignment Oprator
	Auto_ptr4& operator=(const Auto_ptr4& obj)
	{
		if(this==&obj)
			return *this;
		delete m_ptr;
		*m_ptr=*obj.m_ptr;
		return *this;
	}
	// move ctor : transfer ownershipof  obj.mptr to m_ptr
	Auto_ptr4(Auto_ptr4&& obj)
	{
		m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
	}
	// move Assignment 
	Auto_ptr4& operator=(Auto_ptr4&& obj)
	{
		if(this==&obj)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		return *this;
	}
// overload 
	T& operator*() const 
	{
		return *m_ptr;
	}
	T* operator->()const
	{
		return m_ptr;
	}
	bool isNull() const { return m_ptr == nullptr; }

};	


class Resource
{
public:
	 Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};
 
 Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}
 

 int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment
 
	return 0;
}