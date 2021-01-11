#include <iostream>
#include <chrono> // for std::chrono functions
using namespace std;


template<class T>
class DynamicArray
{
	T *m_array;
	int m_length;
public:
	DynamicArray(int length)
	{
		m_array= new T[length];
		m_length=length;
	}
	// Dtor
	~DynamicArray()
	{
		delete [] m_array;
	}
	// ctor
	DynamicArray(const DynamicArray& obj)
	{
		m_array= new T[obj.m_length];
		m_length=obj.m_length;
		for(int i=0;i<m_length;++i)
		{
			m_array[i]=obj.m_array[i];
		}
	}
	DynamicArray& operator=(const DynamicArray &obj)
	{
		if(this==&obj)
		{
			return *this;
		}
		if(m_array)
		{
			delete [] m_array;
		}
		m_array= new T[obj.m_length];

		m_length= obj.m_length;
		for(int i=0;i<m_length;++i)
		{
			m_array[i]=obj.m_array[i];
		}
		return *this;
	}
	int getLength()
	{
		return m_length;
	}
	T& operator[](int index)
	{
		return m_array[index];
	}
	const T& operator[](int index)const
	{
		return m_array[index];
	}
};

class Timer
{
	private:
		using clock_t = std::chrono::high_resolution_clock;
		using second_t= std::chrono::duration<double,std::ratio<1> >;
		std::chrono::time_t<clock_t> m_beg;

	public:
		Timer()
		{
			m_beg= clock_t::now();
		}
		void reset()
		{
			m_beg= clock_t::now();
		}

		double elapsed()
		{
			return (std::chrono::duration_cast<second_t>(clock_t::now-clock_t::m_beg));
		}

};
// Return a copy of an array with double value 
DynamicArray<int> cloneArrayAndDouble(DynamicArray<int> &arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;
 
	return dbl;
}



int main(int argc, char const *argv[])
{
	Timer t;
 
	DynamicArray<int> arr(1000000);
 
	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;
 
	arr = cloneArrayAndDouble(arr);
	
	return 0;
}
 
	std::cout << t.elapsed();