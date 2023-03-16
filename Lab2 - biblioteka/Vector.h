#pragma once
#include <iostream>
#include <algorithm>

#include "Book.h"

class Vector
{
	size_t size;
	Book* books;

public:

	Vector() {};
	Vector(std::initializer_list<Book> initList);
	Vector(const Vector& other);
	Vector(Vector&& other);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);
	~Vector();
	Book& operator[](size_t index);
	const Book& operator[](size_t index) const;
	void add(const Book& book);
	void pop_back();

};

