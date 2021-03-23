//Dylan Nelson - X00144862


//No.8 When you remove virtual in Person class and re-run it , 
//uses the base class printName function.


#include "Customer.h"
#include "Employee.h"
#include <iostream>

void printArray(Person* []);

int main() {

	Employee* employee = new Employee("Tom", 34000.00);
	cout << employee->printname() << "\n";

	Customer* customer = new Customer("Adam", "and I want to make a complaint");
	cout << customer->printname() << "\n";

	Person* peopleArray[6];
	peopleArray[0] = employee;
	peopleArray[1] = customer;
	peopleArray[2] = new Employee("Tod", 15000);
	peopleArray[3] = new Employee("Dylan", 10000);
	peopleArray[4] = new Customer("Michael", "and I want to make a complaint");
	peopleArray[5] = new Customer("David", "and I want to make a complaint");

	cout << "\n unsorted\n\n";
	printArray(peopleArray);

	Person* duplicateUnsortedArray[6];
	for (int i = 0; i < 6; i++) {
		duplicateUnsortedArray[i] = peopleArray[i];
	}

	Person* personHolder;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (peopleArray[i]->operator>(peopleArray[j])) {
				personHolder = peopleArray[i];
				peopleArray[i] = peopleArray[j];
				peopleArray[j] = personHolder;
			}
		}
	}

	cout << "\nArray sorted using operator overloading\n\n";
	printArray(peopleArray);

	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (duplicateUnsortedArray[i]->getName() > duplicateUnsortedArray[j]->getName()) {
				personHolder = duplicateUnsortedArray[i];
				duplicateUnsortedArray[i] = duplicateUnsortedArray[j];
				duplicateUnsortedArray[j] = personHolder;
			}
		}
	}

	cout << "\nArray sorted not using operator overloading\n\n";
	printArray(duplicateUnsortedArray);

	system("pause");
	return(0);
}

void printArray(Person* peopleArray[]) {
	for (int i = 0; i < 6; i++) {
		cout << peopleArray[i]->printname() << "\n";
	}
}