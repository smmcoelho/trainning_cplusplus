#pragma once
#include <string>

class Flower
{
public:
	Flower(const std::string& input_name, const std::string& input_color);

	Flower() ;
	Flower(const Flower& other) ; // copy constructor
	Flower(Flower&& other) noexcept; // move constructor
	Flower& operator=(const Flower& other) ; // copy assignment
	Flower& operator=(Flower&& other) noexcept; // move assignment

	std::string GetName() const;
	std::string GetColor() const;

	//double GetPrice() const;

private:
	std::string name;
	std::string color;

	//double price = 1.0;
};


