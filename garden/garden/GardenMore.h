#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Flower.h"
#include "GardenDetails.h"

//REQUIREMENTS: Create a Garden that contains one flower


class GardenMore
{
public:
	GardenMore(const GardenDetails& garden);
	~GardenMore();

	//GardenMore() = delete;
	//GardenMore(const GardenMore& other) = delete; // copy constructor
	//GardenMore(GardenMore&& other) noexcept = delete; // move constructor
	//GardenMore& operator=(const GardenMore& other) = delete; // copy assignment
	//GardenMore& operator=(GardenMore&& other) noexcept = delete; // move assignment

	void AddFlower(Flower& flower);
	bool DoesHaveFlowers();
	//double GetPrice();

	//inline std::vector<Flower> GetFlowers() const
	//{
	//	return flowers;
	//}

private:
	//variables for garden details
	GardenDetails details;

	//variables for flower details
	std::vector<Flower> flowers;
};
