#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "person.h" // class Person header file
using namespace std;



int main()
{
  // OPENS data.txt
	fstream ifile("data.txt", ios::in);
  // OPENS HTML OUTPUT FILE
	fstream ofile("outputFile.html", ios::out);
	vector<Person> ppl;
	int SIZE = 3; // I defined a size to the vector (optional)
	Person ob;   // Defines an object of the class Person
  // ADDS MEMORY TO VECTOR 
	for (int i = 0; i < SIZE; i++)
	{
		ppl.push_back(ob);
	}
// READS IN PERSON DATA AND STORES IT
	for (int i = 0; i < ppl.size(); i++)
	{
    ifile >> ppl[i].firstname >> ppl[i].lastname >> ppl[i].salary;
		cout << ppl[i].fulname(ppl[i]) << " " << ppl[i].salary << endl;
	}
  // NOTIFY USER THE DATA IS PROCESSED IN FILE 
	cout << endl << "Output is in file: outputFile.html" << endl;
  	fstream html("outputFile.html", ios::out);
    // WRITES THE HEADER OF HMTL TABLE TO THE OUTPUT FILE 
    html << "<head>" << endl;
		html << "<body bgcolor=\"FFFFFF\">" << endl;
		html << "<table border=1px style=width:100%><tr>"<< endl;
		html << "<th>" << "FIRST NAME</th>"<< endl;
		html << "<th> LAST NAME </th>"  << endl;
		html << "<th> FULL NAME </th>" << endl;
		html << "<th> SALARY </th>" << endl;
		html << "<th> TAX </th>" << endl;
		html << "<th> NET PAY </th>" << endl;
		html << "<tr>" << endl;

    // NOW PROCESSES DATA AND WRITES DATA TO FILE
		for (int i = 0; i < ppl.size(); i++)
		{
			html << "<td> " << ppl[i].firstname << "</td>" << endl;
			html << "<td> " << ppl[i].lastname << "</td>" << endl;
			html << "<td>" << ppl[i].fulname(ppl[i]) << " </td>" << endl;
			html << "<td> $" << ppl[i].salary << "</td> " << endl;
			html << "<td>" << ppl[i].taxpay(ppl[i]) << "</td> " << endl;
			html << "<td> $" <<ppl[i].netpay(ppl[i]) << "</td>" << endl;
			html << "<tr>";
		}
    // END OF TABLE
		html << "</tr></table>" << endl;
		html << "</bodt></head>";

  // CLOSE FILE   
  html.close();
	ifile.close();
	return 0;
}