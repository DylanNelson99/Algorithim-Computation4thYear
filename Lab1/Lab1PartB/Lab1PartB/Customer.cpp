//Dylan Nelson - X00144862

#include "Customer.h"
#include <iostream>

Customer::Customer() : Person("") {
	message = "";
}

Customer::Customer(string nameIn, string messageIn) : Person(nameIn) {
	message = messageIn;
}

string Customer::printname() const {
	return Person::printname() + " " + message;
}