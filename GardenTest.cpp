#include "gtest/gtest.h"

#include "Garden.h"

TEST(GardenTest, TestGardenCreationOK) {
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