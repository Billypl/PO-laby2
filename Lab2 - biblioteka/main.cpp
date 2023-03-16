#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
	string a = "Billy", t = "Laby2";
	Book e;
	cout << "e: " << e << endl;
	Book b1 = { a, t };
	cout << "b1: " << b1 << endl;
	Book b2 = { "Terry Prattchet","Straz, straz" };
	cout << "b2: " << b2 << endl;
	Book b3 = b1;
	cout << "b3: " << b3 << " b1: " << b1 << endl;
	e = std::move(b2);
	cout << "e: " << e << " b2:" << b2 << endl;
	e.setAuthor("Mickiewicz");
	cout << "e: " << e << endl;
	e.setTitle("Dziekan w Potrzasku");
	cout << "e: " << e << endl;


}