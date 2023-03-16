#include "Book.h"
#include <iostream>

Book::Book(const std::string& author, const std::string& title)
	: author(author), title(title) {}

Book::Book(std::string&& author, std::string&& title)
	: author(author), title(title) {}

Book::Book(const Book& other)
	: author(other.author), title(other.title) {}

Book::Book(Book&& other)
	: author(std::move(other.author)), title(std::move(other.title)){}

Book& Book::operator=(const Book& other)
{
	title = other.title;
	author = other.author;
	return *this;
}

Book& Book::operator=(Book&& other)
{
	std::swap(author, other.author);
	std::swap(title, other.title);
	return *this;
}

std::string Book::getAuthor() const
{
	return author;
}

std::string Book::getTitle() const
{
	return title;
}

void Book::setAuthor(const std::string& author)
{
	this->author = author;
}

void Book::setTitle(const std::string& title)
{
	this->title = title;
}

void Book::setAuthor(std::string&& author)
{
	this->author = author;
}

void Book::setTitle(std::string&& title)
{
	this->title = title;
}

std::ostream& operator<<(std::ostream& ostr, const Book& book)
{
	ostr << "Book{title: " << book.title << " author: " << book.author << '}';
	return ostr;
}