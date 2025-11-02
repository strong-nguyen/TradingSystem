#include "Portfolio.h"
#include <iostream>
#include <iomanip>

Portfolio::Portfolio(double initialCash) : cash(initialCash), shares(0) {}

void Portfolio::buy(const std::string& date, double price) {
	int qty = static_cast<int>(cash / price);
	if (qty > 0) {
		cash -= qty * price;
		shares += qty;
		std::cout << date << " | BUY  | $" << price << " | Shares: " << shares << " | Cash: $" << std::fixed << std::setprecision(2) << cash << "\n";
	}
}

void Portfolio::sell(const std::string& date, double price) {
	if (shares > 0) {
		cash += shares * price;
		std::cout << date << " | SELL | $" << price << " | Shares: 0 | Cash: $" << std::fixed << std::setprecision(2) << cash << "\n";
		shares = 0;
	}
}

void Portfolio::hold(const std::string& date, double price) {
	std::cout << date << " | HOLD | $" << price << " | Shares: " << shares << " | Cash: $" << std::fixed << std::setprecision(2) << cash << "\n";
}

