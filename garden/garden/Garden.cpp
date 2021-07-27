#include "pch.h"
#include "Garden.h"

Garden::Garden(double x_size, double y_size, const std::string& f_name, const std::string& f_color) :
	size_in_x{ x_size },
	size_in_y{ y_size },
	flower_name{ f_name },
	flower_color{ f_color }
{

}

Garden::~Garden()
{

}