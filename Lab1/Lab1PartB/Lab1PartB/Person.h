//Dylan Nelson - X00144862

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person {
private:
	string name;
public:
	explicit
		Person();
	Person(string);
	virtual string printname() const = 0;
	string getName();
	bool operator >(Person*);
};
