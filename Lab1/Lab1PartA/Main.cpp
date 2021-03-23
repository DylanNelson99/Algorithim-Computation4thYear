//Dylan Nelson - X00144862

#include <iostream>
#include <string>
#include "Product.h"
#include "Software.h"
#include "Book.h"
using namespace std;

int main() {

	Product* productArray[8];

	Software* software;

	Book* book;

	double priceIn = 0;

	cout << "Please enter the price of the software\n";
	cin >> priceIn;

	software = new Software(priceIn);
	cout << "Software price is € " << software->getGrossPrice() << "\n";

	cout << "Please enter the price of the book\n";
	cin >> priceIn;

	book = new Book(priceIn);
	cout << "Book price is € " << book->getGrossPrice() << "\n";

	productArray[0] = software;
	productArray[1] = book;

	string choice = "";

	for (int i = 2; i < 10; i++) {
		cout << "Please enter Book or Software as a product\n";
		cin >> choice;
		cout << "Please enter the price for the " << choice << "\n";
		cin >> priceIn;

		if (choice == "Software" || choice == "software") {
			productArray[i] = new Software(priceIn);
		}
		else if (choice == "Book" || choice == "book") {
			productArray[i] = new Book(priceIn);
		}
	}

	for (int i = 0; i < 8; i++) {
		cout << "Gross Price for Item " << i << " is €" << productArray[i]->getGrossPrice() << "\n";
	}

	double priceHolder = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {

			if (productArray[i]->getNetPrice() > productArray[j]->getNetPrice()) {
				priceHolder = productArray[i]->getNetPrice();
				productArray[i]->setNetPrice(productArray[j]->getNetPrice());
				productArray[j]->setNetPrice(priceHolder);
			}
		}
	}

	cout << "\n**********Sorted Array**********\n";
	for (int i = 0; i < 8; i++) {
		cout << "Gross Price for Item " << i << " is €" << productArray[i]->getGrossPrice() << "\n";
	}

	system("pause");
	return 0;
}