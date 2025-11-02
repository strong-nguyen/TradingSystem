#pragma once
#include <vector>
#include "DataLoader.h"

enum class Signal { BUY, SELL, HOLD };

Signal generateSignal(const std::vector<PriceData>& data, int index, int shortWindow, int longWindow);
