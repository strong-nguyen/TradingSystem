#pragma once
#include <string>

class Portfolio {
	double cash;
	int shares;
public:
	Portfolio(double initialCash);
	void buy(const std::string& date, double price);
	void sell(const std::string& date, double price);
	void hold(const std::string& date, double price);
};
