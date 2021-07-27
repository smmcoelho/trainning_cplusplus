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

	//double Calculate()
	//{
	//	auto flowers = m_garden.GetFlowers();
	//	return std::accumulate(flowers.begin(),
	//		flowers.end(),
	//		0,
	//		[&](int sum, const Flower& f) { return sum + f.GetPrice(); }
	//	);
	//}

private:
	GardenMore m_garden;
};

