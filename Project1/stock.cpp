#include<iostream>
#include<cstring>
using namespace std;

class Stock
{
private:
	string  company;
	long shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares * share_val;
	}
public:


	void acquire(string co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};

void Stock::acquire(string  co, long n, double pr)
{
	company = co;

	if (n < 0)
	{
		cout << "Number of shares cant be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
}


void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased cant be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares sold cant be negatie. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You cant sell more than you have!"
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company: " << company
		<< " Shares: " << shares << '\n'
		<< " Shares Price: $" << share_val;
	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
int main() {
	Stock st1;
	st1.acquire("NanoSmart", 20, 2.5);
	st1.show();
	st1.buy(20, 126.32);
	st1.show();


}