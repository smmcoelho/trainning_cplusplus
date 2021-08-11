#pragma once
#include <string>

//REQUIREMENTS: Create a Garden that contains one flower

class Garden
{
public:
	Garden(double x_size, double y_size, const std::string& f_name, const std::string& f_color) :
		size_in_x{ x_size },
		size_in_y{ y_size },
		flower_name{ f_name },
		flower_color{ f_color }
	{}

	~Garden()
	{}

private:
	//variables for garden details
	double size_in_x;
	double size_in_y;

	//variables for flower details
	std::string flower_name;
	std::string flower_color;
};
