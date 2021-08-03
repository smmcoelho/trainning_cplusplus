#include "gtest/gtest.h"
#include "GardenStruct.h"


TEST(TestGardenStructOK, GardenStructTest) {
	GardenDetails g = {1.0, 2.0};
	Flower f = {"rose", "white"};

	EXPECT_NO_THROW(GardenStruct(g, f););
}

TEST(TestGardenStructGetFlowerLasy, GardenStructTest) {
	GardenDetails g = { 1.0, 2.0 };
	Flower f = { "rose", "white" };

	GardenStruct garden(g, f);
	auto result = garden.GetFlower();

	//TODO implement Flower::operator== 
	EXPECT_EQ(f.color, result.color);
	EXPECT_EQ(f.name, result.name);
}

TEST(TestGardenStructOKWithBug, GardenStructTest) {
	GardenDetails g = { 1.0};
	Flower f = { "rose"};

	EXPECT_NO_THROW(GardenStruct(g, f););
}

//Wrong behaviour but still passing
TEST(TestGardenStructKOWithBug, GardenStructTest) {
	GardenDetails g = { 1.0 };
	Flower f = { "rose" };

	GardenStruct garden(g, f);
	auto result = garden.GetFlower();

	//TODO implement Flower::operator== 
	EXPECT_EQ(f.color, result.color);
	EXPECT_EQ(f.name, result.name);
}


//BAD EXAMPLE - TEST MULTIPLE THINGS AT ONCE 
TEST(TestGardenStructPleaseDontDoLikeThis, GardenStructTest) {
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