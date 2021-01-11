#include <iostream>


using namespace std;
template<class T>
class auto_ptr1
{
	T *m_ptr;
public:
	auto_ptr1(T* ptr=nullptr):m_ptr(ptr)
	{
		cout << "Default ctro " << endl;
	}
	// overload * and ->
	T& operator*() const 
	{
		return *m_ptr;
	}
	T* operator->() const
	{
		return m_ptr;
	}
	~auto_ptr1()
	{
		cout << "Default Dtor" << endl;
		delete m_ptr;
	}
	// a copy ctor that implements the move semantic 
	auto_ptr1(auto_ptr1 &obj) // note : const keyword not being used 
	{
		cout << "Move semantic copy ctor called " << endl;
		m_ptr= obj.m_ptr; // transfer dump ptr from source to local object 
		obj.m_ptr = nullptr ; // make sure source does not hold the pointer 

	}
	// assignment operator that implement the move semantic 
	auto_ptr1& operator=(auto_ptr1& obj)// note : No const keyword 
	{

		cout << "Move semantic assignment overload operator called " << endl;
		if(this==&obj)
			return *this;
		
		delete m_ptr;// make sure delete any pointer that destination holds 
		m_ptr= obj.m_ptr; 
		obj.m_ptr= nullptr;// source no longer owns the object 
		return *this;


	}
};
class Resource
{
public:
	Resource()
	{
		cout << "Resource acquired" << endl;

	}
	~Resource()
	{
		cout << "Resource destroyed " << endl;
	}
};
int main()
{
	auto_ptr1<Resource> res1(new Resource());
	auto_ptr1<Resource> res2;
	//std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	//std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
	res2 = res1; 
	auto_ptr1<Resource> res3(res1); // ownly ownership getting changed 
	return 0;
}

// here still problem of auto_ptr, it is having issue if we are passing auto_ptr as a value to fucntion 
// it can be destroyed with inthe fucntion itself and outside the function program may crash 
// so instread of auto_ptr which has been depriacted we will use unique_ptr and shared_ptr