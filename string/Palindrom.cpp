#include <iostream>
#include <limits>
#include <string>
using namespace std;
bool isPalindrom(string str)
{
	string newstr;
	for(int i=str.length()-1;i>=0;--i)
	{
		newstr.push_back(str[i]);
	}
	cout << "New str is " << newstr << endl;
	return newstr==str;

}
int main()
{
	string str;
	cout << "Enter the string "  << endl;
	cin >> str;
	cin.ignore(numeric_limits<int>::max(),'\n');

	cout << std::boolalpha << isPalindrom(str) << endl;
}
