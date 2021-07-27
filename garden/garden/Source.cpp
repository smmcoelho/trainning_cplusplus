#include "pch.h"

#include "GardenDetails.h"

//GardenDetailsTest
TEST(TestGardenDetailsNotValid, GardenDetailsTest) {
	GardenDetails gDetails;

	auto r = gDetails.IsValid();
	EXPECT_EQ(r, false);
}

TEST(TestGardenDetailsValid, GardenDetailsTest) {
	GardenDetails gDetails(1.0, 2.0);

	auto r = gDetails.IsValid();
	EXPECT_EQ(r, true);
}
