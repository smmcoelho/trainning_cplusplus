#pragma once

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

private:
	double size_in_x;
	double size_in_y;

	bool is_valid = true;
};
