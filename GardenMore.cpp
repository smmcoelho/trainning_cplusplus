#include "pch.h"
#include "GardenMore.h"
#include "Price.h"


#include <stdexcept>
#include <iostream>
#include <typeinfo>

GardenMore::GardenMore(const GardenDetails& garden)
{
	details = garden;
}

GardenMore::~GardenMore()
{

}

void GardenMore::AddFlower(Flower& flower)
{
	if (!details.IsValid())
	{
		throw std::runtime_error("garden size is not valid");
	}
	flowers.push_back(std::move(flower));
}
bool GardenMore::DoesHaveFlowers()
{
	return flowers.size() > 0; // return flowers.size() would cast size_t to bool and will give a PVS warnning
}


//not implemented by the caller just for didactic purpose -> to mock Price::Calculate method
double GardenMore::GetPrice(const Price& p)
{
	if (!details.IsValid())
	{
		throw std::runtime_error("garden size is not valid");
	}

	auto r = p.Calculate(flowers);

	return r;
}
