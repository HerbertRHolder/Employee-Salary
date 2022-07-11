#include <iostream>
#include <string>
using namespace std;



class Person
{
public:
	string firstname = " ", lastname = " ", fullname = firstname + " " + lastname;
	string filename1 = "input", filename2 = "output";
	double salary = 0.0, netPay = 0.0;
	double tax;
	Person()
	{
		const double t = 0.16;
		tax = t;
	}
	// OVERLOADED CONSTRUCTOR 
	Person(string fname, string lname, double slry, double np)
	{
		firstname = fname;
		lastname = lname;
		salary = slry;
		netPay = np;
	}
	// CALCULATES THE TAX PAID IN DOLLARS
	double taxpay(Person ob)
	{
		double dollarTax;
		dollarTax = ob.salary * ob.tax;
		return dollarTax;
	}
	double netpay(Person ob)
	{
		ob.netPay = ob.salary * (1 - ob.tax);
		return ob.netPay;
	}

	string fulname(Person ob)
	{
		string flname;
		flname = ob.firstname + " " + ob.lastname;
		return flname;
	}

};