//Dylan Nelson - X00144862

#pragma once

class Product {
protected:
	double netPrice;

public:
	Product();
	Product(double);
	double getNetPrice();
	void setNetPrice(double);
	virtual double getGrossPrice();
};
