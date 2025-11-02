#include "Strategy.h"
#include <numeric>

double movingAverage(const std::vector<PriceData>& data, int start, int window) {
	if (start + window > data.size()) return -1;
	double sum = 0;
	for (int i = start; i < start + window; ++i) {
		sum += data[i].close;
	}
	return sum / window;
}

Signal generateSignal(const std::vector<PriceData>& data, int index, int shortWindow, int longWindow) {
	if (index < longWindow) return Signal::HOLD;

	double shortMA = movingAverage(data, index - shortWindow, shortWindow);
	double longMA = movingAverage(data, index - longWindow, longWindow);

	if (shortMA > longMA) return Signal::BUY;
	if (shortMA < longMA) return Signal::SELL;
	return Signal::HOLD;
}

