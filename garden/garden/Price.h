#pragma once

#include "GardenMore.h"
#include <numeric>


class Price
{
public:

	virtual double Calculate(const std::vector<Flower>& flowers) const
	{
		double total_price = 0.0;
		for (const auto& flower : flowers)
		{
			total_price += flower.GetPrice();
		}
		return total_price;
	}

	//version 2
	//double Calculate()
	//{
	//	auto flowers = m_garden.GetFlowers();
	//	return std::accumulate(flowers.begin(),
	//		flowers.end(),
	//		0,
	//		[&](int sum, const Flower& f) { return sum + f.GetPrice(); }
	//	);
	//}

	//version 3
	//auto func_accumulate_price = [&](int sum, const Flower& f)
	//{
	//	return sum + f.GetPrice();
	//};

	//double Calculate()
	//{
	//	auto flowers = m_garden.GetFlowers();
	//	return std::accumulate(flowers.begin(), flowers.end(), 0, func_accumulate_price);
	//}

};

