#include "pch.h"
#include "GardenDetails.h"


GardenDetails::GardenDetails() :
	size_in_x{ 0.0 },
	size_in_y{ 0.0 },
	is_valid {false}
{	
}

GardenDetails::GardenDetails(double x, double y) :
	size_in_x{ x },
	size_in_y{ y }
{

}


GardenDetails::GardenDetails(const GardenDetails& other)
{
	//not used member initialized list for mantinence propose and less prone to error
	//performance decrease is acceptable
	//and in this case not having const members in the class the performance it will compile
	//also easier to expande and keep consisetncey with assignement operator method
	*this = other;
}

GardenDetails::GardenDetails(GardenDetails&& other) noexcept
{
	*this = std::move(other);
}

GardenDetails& GardenDetails::operator=(const GardenDetails& other)
{
	if (this != &other)
	{
		size_in_x = other.size_in_x;
		size_in_y = other.size_in_y;
		is_valid = other.is_valid;
	}
	return *this;
}

GardenDetails& GardenDetails::operator=(GardenDetails&& other) noexcept
{
	if (this != &other) 
	{
		size_in_x = std::move(other.size_in_x);
		size_in_y = std::move(other.size_in_y);
		is_valid = std::move(other.is_valid);
	}
	return *this;
}

double GardenDetails::GetXSize() const
{
	return size_in_x;
}

double GardenDetails::GetYSize() const
{
	return size_in_y;
}

bool GardenDetails::IsValid()
{
	return is_valid;
}