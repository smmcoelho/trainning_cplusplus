#include "pch.h"
#include "GardenMore.h"
#include <stdexcept>


GardenMore::GardenMore(const GardenDetails& garden)
{
	details = garden;
}

GardenMore::~GardenMore()
{

}

void GardenMore::AddFlower(const Flower& flower)
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

