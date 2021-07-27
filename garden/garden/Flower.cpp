#include "pch.h"
#include "Flower.h"

Flower::Flower(const std::string& input_name, const std::string& input_color) :
	name{ input_name },
	color{ input_color }
{
}

Flower::Flower():
	name{ "" },
	color{ "" }
{
}

Flower::Flower(const Flower& other)
{
	//not used member initialized list for mantinence propose and less prone to error
	//performance decrease is acceptable
	//and in this case not having const members in the class the performance it will compile
	//also easier to expande and keep consisetncey with assignement operator method
	*this = other;
}

Flower::Flower(Flower&& other) noexcept
{
	*this = std::move(other);
}

Flower& Flower::operator=(const Flower& other)
{
	if (this != &other) 
	{
		name = other.name;
		color = other.color;
	}
	return *this;
}

Flower& Flower::operator=(Flower&& other) noexcept
{
	if (this != &other)
	{
		name = std::move(other.name);
		color = std::move(other.color);
	}
	return *this;
}

std::string Flower::GetName() const
{
	return name;
}

std::string Flower::GetNamecolor() const
{
	return color;
}
