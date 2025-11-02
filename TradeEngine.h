#pragma once
#include "DataLoader.h"
#include "Strategy.h"
#include "Portfolio.h"

void runTradingSystem(const std::vector<PriceData>& data, Portfolio& portfolio, int shortWindow, int longWindow);

