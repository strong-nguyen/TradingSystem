#include "TradeEngine.h"
#include <iostream>

void runTradingSystem(const std::vector<PriceData>& data, Portfolio& portfolio, int shortWindow, int longWindow) {
	for (size_t i = 0; i < data.size(); ++i) {
		Signal signal = generateSignal(data, i, shortWindow, longWindow);
		const auto& pd = data[i];

		switch (signal) {
		case Signal::BUY:
			portfolio.buy(pd.date, pd.close);
			break;
		case Signal::SELL:
			portfolio.sell(pd.date, pd.close);
			break;
		case Signal::HOLD:
			portfolio.hold(pd.date, pd.close);
			break;
		}
	}
}
