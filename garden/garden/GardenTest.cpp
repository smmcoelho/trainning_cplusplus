#include "gtest/gtest.h"

#include "Garden.h"

TEST(TestGardenCreationOK, GardenTest) {
	auto result = true;
	try
	{
		Garden g(0.0, 0.0, "rose", "pink");
	}
	catch (...)
	{
		result = false;
	}

  EXPECT_TRUE(result);
}


//TEST(TestGardenCreationThrowException, GardenTest) {
//	auto result = true;
//	try
//	{
//		Garden g(0.0, 0.0);
//		g.AddFlower("rose", "pink");
//	}
//	catch (...)
//	{
//		result = false;
//	}
//
//	EXPECT_FALSE(result);
//}
//
//TEST(TestGardenCreationNoException, GardenTest) {
//	auto result = true;
//	try
//	{
//		Garden g(1.0, 2.0);
//		g.AddFlower("rose", "pink");
//	}
//	catch (...)
//	{
//		result = false;
//	}
//
//	EXPECT_TRUE(result);
//}