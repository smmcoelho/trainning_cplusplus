#pragma once
#include <string>

//REQUIREMENTS: Create a Garden that contains one flower

class Garden
{
public:
	Garden(double x_size, double y_size, const std::string& f_name, const std::string& f_color);
	~Garden();

	//Garden(double x_size, double y_size);
	//void AddFlower(const std::string& f_name, const std::string& f_color);

private:
	//variables for garden details
	double size_in_x;
	double size_in_y;

	//variables for flower details
	std::string flower_name;
	std::string flower_color;
};
