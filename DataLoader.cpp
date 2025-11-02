#include "DataLoader.h"
#include <fstream>
#include <sstream>

std::vector<PriceData> loadPriceData(const std::string& filename) {
	std::vector<PriceData> data;
	std::ifstream file(filename);
	std::string line;
	getline(file, line); // skip header

	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string date, closeStr;
		getline(ss, date, ',');
		getline(ss, closeStr, ',');

		PriceData pd{ date, std::stod(closeStr) };
		data.push_back(pd);
	}
	return data;
}

