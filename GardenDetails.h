#pragma once
#include <iostream>

class GardenDetails
{
public:
	GardenDetails();
	GardenDetails(double x, double y);
	       
	GardenDetails(const GardenDetails& other); // copy constructor
	GardenDetails(GardenDetails&& other) noexcept; // move constructor
	GardenDetails& operator=(const GardenDetails& other); // copy assignment
	GardenDetails& operator=(GardenDetails&& other) noexcept; // move assignment


	double GetXSize() const;
	double GetYSize() const;

	bool IsValid();

	//convertion operator
	operator std::string() const
	{
		return std::to_string(size_in_x) + ":" + std::to_string(size_in_y);
	}


private:
	double size_in_x;
	double size_in_y;

	bool is_valid;
};












//operator< compares the area (size_in_x * size_in_y)
inline bool operator<(const GardenDetails& lhs, const GardenDetails& rhs)
{
	auto lhs_area = lhs.GetXSize() * lhs.GetYSize();
	auto rhs_area = rhs.GetXSize() * rhs.GetYSize();
	return lhs_area < rhs_area;
}

inline bool operator==(const GardenDetails& lhs, const GardenDetails& rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

inline bool operator>(const GardenDetails& lhs, const GardenDetails& rhs)
{
	return !(lhs < rhs) && !(lhs == rhs);
}

inline bool operator!=(const GardenDetails& lhs, const GardenDetails& rhs)
{
	return !(lhs == rhs);
}

inline std::ostream& operator<<(std::ostream& os, const GardenDetails& dt)
{
	os << std::string(dt);
	return os;
}