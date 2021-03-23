//Dylan Nelson - X00144862

#pragma once
#include "Product.h"

class Book : public Product {
public:
	Book();
	Book(double);
	double getGrossPrice();
};