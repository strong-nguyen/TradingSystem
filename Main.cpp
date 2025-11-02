#include "DataLoader.h"
#include "TradeEngine.h"
#include "Portfolio.h"

#include <iostream>

int main() {
	std::string filename = "data/prices.csv";
	auto data = loadPriceData(filename);

	Portfolio portfolio(1000.0); // Starting with $1000
	int shortWindow = 3;
	int longWindow = 5;

	std::cout << "Date       | Signal | Price | Shares | Cash\n";
	std::cout << "---------------------------------------------\n";
	runTradingSystem(data, portfolio, shortWindow, longWindow);

	return 0;
}
