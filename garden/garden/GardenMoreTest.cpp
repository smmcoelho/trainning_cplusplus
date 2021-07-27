#include "pch.h"

#include "GardenDetails.h"
#include "GardenMore.h"
#include "Flower.h"

//GardenDetailsTest
TEST(TestGardenDetailsNotValid, GardenDetailsTest) {
  GardenDetails gDetails;

  EXPECT_FALSE(gDetails.IsValid());

  //auto r = gDetails.IsValid();
  //EXPECT_EQ(r, false);
}

TEST(TestGardenDetailsValid, GardenDetailsTest) {
	GardenDetails gDetails(1.0, 2.0);

	EXPECT_TRUE(gDetails.IsValid());
}


//GardenMoreTest
TEST(TestGardenDetailsHasFlowersTrue1, GardenMoreTest) {
	const GardenDetails gDetails;
	GardenMore garden(gDetails);

	auto hasFlowers = garden.DoesHaveFlowers();

	EXPECT_EQ(hasFlowers, false);
}

TEST(TestGardenDetailsHasFlowersTrue2, GardenMoreTest) {
	GardenMore garden(GardenDetails(0.0, 0.0));

	EXPECT_FALSE(garden.DoesHaveFlowers());
}

TEST(TestGardenDetailsHasFlowersFalse1, GardenMoreTest) {
	GardenDetails gd(1.0, 2.0);
	ASSERT_TRUE(gd.IsValid()); //should be coverd in GardenDetails

	GardenMore garden(gd);
	ASSERT_TRUE(gd.IsValid());//should be coverd in GardenMore in other test

	Flower f("rose", "red");
	garden.AddFlower(f);

	ASSERT_TRUE(garden.DoesHaveFlowers());
}

//should be testing the same as previous test
TEST(TestGardenDetailsHasFlowersFalse2, GardenMoreTest) {
	GardenMore garden(GardenDetails(1.0, 2.0));
	garden.AddFlower(Flower("rose", "red"));

	ASSERT_TRUE(garden.DoesHaveFlowers());
}

TEST(TestGardenDetailsAddFlowerThrowException1, GardenMoreTest) {
	auto result = false;

	try
	{
		GardenDetails gDetails;
		GardenMore garden(gDetails);
		Flower f("rose", "red");

		garden.AddFlower(f);
	}
	catch (...)
	{
		result = true;
	}
	ASSERT_TRUE(result);
}

//same/similar as previous test but using ASSERT_THROW
TEST(TestGardenDetailsAddFlowerThrowException2, GardenMoreTest) {
	GardenDetails gDetails;
	GardenMore garden(gDetails);
	Flower f("rose", "red");

	ASSERT_THROW(garden.AddFlower(f), std::runtime_error);
}