//Dylan Nelson - X00144862

#include "Product.h"
#include "Book.h"
#include "Software.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Product::Product() {
	netPrice = 0.0;
}

Product::Product(double price) {
	netPrice = price;
}

double Product::getNetPrice() {
	return netPrice;
}

void Product::setNetPrice(double price) {
	netPrice = price;
}

double Product::getGrossPrice() {
	netPrice = netPrice * 1.21;
	return netPrice;
}
