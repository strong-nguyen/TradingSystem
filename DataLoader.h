#pragma once
#include <vector>
#include <string>

struct PriceData {
	std::string date;
	double close;
};

std::vector<PriceData> loadPriceData(const std::string& filename);


