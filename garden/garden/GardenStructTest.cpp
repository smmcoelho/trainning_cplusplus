#include "gtest/gtest.h"
#include "GardenStruct.h"


TEST(GardenStructTest, TestGardenStructOK) {
	GardenDetails g = {1.0, 2.0};
	Flower f = {"rose", "white"};

	EXPECT_NO_THROW(GardenStruct(g, f););
}

TEST(GardenStructTest, TestGardenStructGetFlowerLasy) {
	GardenDetails g = { 1.0, 2.0 };
	Flower f = { "rose", "white" };

	GardenStruct garden(g, f);
	auto result = garden.GetFlower();

	//TODO implement Flower::operator== 
	EXPECT_EQ(f.color, result.color);
	EXPECT_EQ(f.name, result.name);
}

TEST(GardenStructTest, TestGardenStructOKWithBug) {
	GardenDetails g = { 1.0};
	Flower f = { "rose"};

	EXPECT_NO_THROW(GardenStruct(g, f);); //constructor is throwing an exception ???
}

//Wrong behaviour but still passing
TEST(GardenStructTest, TestGardenStructKOWithBug) {
	GardenDetails g = { 1.0 };
	Flower f = { "rose" };

	GardenStruct garden(g, f);
	auto result = garden.GetFlower();

	//TODO implement Flower::operator== 
	EXPECT_EQ(f.color, ""); // by default string is initialized as empty
	EXPECT_TRUE(result.color.empty()); //TODO remove - checking again color
	EXPECT_EQ(f.color, result.color); //TODO remove - checking again color
	EXPECT_EQ(f.name, result.name);
}


//BAD EXAMPLE - TEST MULTIPLE THINGS AT ONCE 
TEST(GardenStructTest, TestGardenStructPleaseDontDoLikeThis) {
	bool r = true;
	try
	{
		GardenDetails g = { 1.0 };
		Flower f = { "rose" };

		GardenStruct garden(g, f);
		auto result = garden.GetFlower();

		//TODO implement Flower::operator== 
		EXPECT_EQ(f.color, result.color);
		EXPECT_EQ(f.name, result.name);
	}
	catch (...)
	{
		r = false;
	}
	EXPECT_TRUE(r);
}