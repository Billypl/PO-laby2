#pragma once
#include <string>

class Book {

	std::string author, title;

public:

	Book() {};
	Book(const std::string& author, const std::string& title);
	Book(std::string&& author, std::string&& title);
	Book(const Book& other);
	Book(Book&& other);
	Book& operator=(const Book& other);
	Book& operator=(Book&& other);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	std::string getAuthor() const;
	std::string getTitle() const;
	void setAuthor(const std::string& author);
	void setTitle(const std::string& title);
	void setAuthor(std::string&& author);
	void setTitle(std::string&& title);

};



