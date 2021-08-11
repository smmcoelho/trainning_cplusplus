#pragma once
#include <string>

struct GardenDetails
{
	double x_size;
	double y_size;
};

struct Flower
{
	std::string name;
	std::string color;
};

class GardenStruct
{
public:
	GardenStruct(const GardenDetails& details, const Flower& fl) :
		garden{ details },
		flower{ fl }
	{}

	~GardenStruct()
	{}

	inline Flower GetFlower() const {
		return flower;
	}

private:
	GardenDetails garden;
	Flower flower;
};

