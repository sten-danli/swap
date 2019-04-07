#include<iostream>
using namespace std;

class Swap
{
public:
	void swapNumber(int &x, int &y);

private: 
	int a; int b;

};

void Swap::swapNumber(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	Swap s1;
	int a = 1;
	int b = 2;

	s1.swapNumber(a, b);

	cout << "a ist: " << a << endl;
	cout << "b ist: " << b << endl;
}


