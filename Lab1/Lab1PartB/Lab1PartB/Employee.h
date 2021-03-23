//Dylan Nelson - X00144862

#pragma once
#include "Person.h"

class Employee : public Person {
private:
	double salary;

public:
	Employee();
	Employee(string, double);
	string printname() const;
};
