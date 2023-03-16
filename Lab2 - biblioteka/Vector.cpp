#include "Vector.h"
using namespace std;

Vector::Vector(std::initializer_list<Book> initList)
	: size{ initList.size() }, books{ new Book[initList.size()] }
{
	std::cout << "Vector(std::initializer_list)" << std::endl;
	std::size_t i = 0;
	for (Book v : initList)
	{
		books[i] = v;
		i++;
	}
}

Vector::Vector(const Vector& other)
{
	books = new Book[other.size];
	size = other.size;
	for(size_t i = 0; i < other.size; i++)
		books[i] = other.books[i];
}

Vector::Vector(Vector&& other)
{
	size = other.size; //Pobranie wskaźnika na dane
	books = other.books; //Kopiowanie rozmiaru wektora
	other.books = nullptr; //Usuwanie odniesienia do danych obiekcie
	other.size = 0; //Ustawianie rozmiaru wektora na 0
}

Vector& Vector::operator=(const Vector& other)
{
	Vector tmp(other);
	std::swap(size, tmp.size);
	std::swap(books, tmp.books);
	return *this;
}

Vector& Vector::operator=(Vector&& other)
{
	std::cout << "operator=(Vector&&)" << std::endl;
	std::swap(books, other.books); //Zamiana wskaźników na tablice
	std::swap(size, other.size); //Zamiana informacji o wielkości
	return *this;

}

Vector::~Vector()
{
	if(books != nullptr)
	{
		delete[] books;
	}
}

Book& Vector::operator[](size_t index)
{
	if (index >= 0 && index < size)
		return books[index];
	else throw;
}

const Book& Vector::operator[](size_t index) const
{
	if (index >= 0 && index < size)
		return books[index];
	else throw;
}

void Vector::add(const Book& book)
{
	Book* tmp = new Book[size + 1];
	//memcpy(tmp, books, sizeof(Book)*size);
	for (size_t i = 0; i < size; i++) {
		tmp[i] = books[i];
	}
	tmp[size] = book;
	size += 1;
	delete[] books;
	books = tmp;
}

void Vector::pop_back()
{
	if (size > 0)
		size--;
	else throw;
}

std::ostream& operator<<(std::ostream& ostr, const Vector& vector)
{
	for (size_t i = 0; i < vector.size; i++)
		cout << i << ". " << vector.books[i] << endl;
	return ostr;
}