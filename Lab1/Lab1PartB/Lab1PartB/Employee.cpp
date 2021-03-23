//Dylan Nelson - X00144862

#include "Employee.h"
#include <iostream>

Employee::Employee() : Person("") {
	salary = 0;
}

Employee::Employee(string nameIn, double salaryIn) : Person(nameIn) {
	salary = salaryIn;
}

string Employee::printname() const {
	return Person::printname() + " and my salary is €" + to_string(salary);
}