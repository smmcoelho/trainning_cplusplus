#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Flower.h"
#include "GardenDetails.h"

//REQUIREMENTS: Create a Garden that contains one flower

class Price;

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

	double GetPrice(const Price& p);

	inline std::vector<Flower> GetFlowers() const
	{
		return flowers;
	}

	inline GardenDetails GetDetails() const
	{
		return details;
	}

private:
	//variables for garden details
	GardenDetails details;

	//variables for flower details
	std::vector<Flower> flowers;
};

inline bool operator<(const GardenMore& lhs, const GardenMore& rhs)
{
	//COMMENTED wrong implementatopm of GardenDetails operator in  GardenMore
	//auto lhs_area = lhs.GetDetails().GetXSize() * lhs.GetDetails().GetYSize(); //What???
	//auto rhs_area = rhs.GetDetails().GetXSize() * rhs.GetDetails().GetYSize();
	//return lhs_area < rhs_area;

	return  lhs.GetDetails() < rhs.GetDetails();
}

inline bool operator==(const GardenMore& lhs, const GardenMore& rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

inline bool operator>(const GardenMore& lhs, const GardenMore& rhs)
{
	return !(lhs < rhs) && !(lhs == rhs);
}

inline bool operator!=(const GardenMore& lhs, const GardenMore& rhs)
{
	return !(lhs == rhs);
}

