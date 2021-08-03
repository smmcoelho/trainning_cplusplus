#pragma once

#include "GardenMore.h"
#include <numeric>

class Price
{
public:
	Price(const GardenMore& garden):
		m_garden{ garden }
	{	
	}

	//double Calculate()
	//{
	//	double total_price = 0.0;
	//	for (const auto& flower : m_garden.GetFlowers())
	//	{
	//		total_price += flower.GetPrice();
	//	}
	//	return total_price;
	//}

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

private:
	GardenMore m_garden;
};

