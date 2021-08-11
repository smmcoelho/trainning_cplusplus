#pragma once

#include <vector>
#include <numeric>

#include "Flower.h"

auto func_accumulate_price = [&](int sum, const Flower& f)
{
	return sum + f.GetPrice();
};


class PriceCorrect
{
public:


	double Calculate(const std::vector<Flower>& flowers) const
	{
		return std::accumulate(flowers.begin(), flowers.end(), 0, func_accumulate_price);
	}
};

