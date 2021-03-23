//Dylan Nelson - X00144862

#pragma once
#include "Person.h"

class Customer : public Person {
private:
	string message;
public:
	Customer();
	Customer(string, string);
	string printname() const;
};

