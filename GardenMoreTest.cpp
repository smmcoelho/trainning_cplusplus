#include "pch.h"
#include "mock_price.h"


#include "GardenDetails.h"
#include "GardenMore.h"
#include "Flower.h"
#include "Price.h"

//GardenDetailsTest
TEST(GardenDetailsTest, TestGardenDetailsNotValid) {
  GardenDetails gDetails;

  EXPECT_FALSE(gDetails.IsValid());
}

TEST(GardenDetailsTest, TestGardenDetailsValid) {
	GardenDetails gDetails(1.0, 2.0);

	EXPECT_TRUE(gDetails.IsValid());
}

//bad test -> magic numbers with 6 decimal digits
TEST(GardenDetailsTest, TestGardenDetailsConvertionToString) {
	GardenDetails d(1.0, 2.0);
	EXPECT_EQ(std::string(d), "1.000000:2.000000"); // unnecessary
}


//GardenMoreTest
TEST(GardenMoreTest, TestGardenDetailsHasFlowersTrue1) {
	const GardenDetails gDetails;
	GardenMore garden(gDetails);

	auto hasFlowers = garden.DoesHaveFlowers();

	EXPECT_EQ(hasFlowers, false);
}

TEST(GardenMoreTest, TestGardenDetailsHasFlowersTrue2) {
	GardenMore garden(GardenDetails(0.0, 0.0));

	EXPECT_FALSE(garden.DoesHaveFlowers());
}

TEST(GardenMoreTest, TestGardenDetailsHasFlowersFalse1) {
	GardenDetails gd(1.0, 2.0);
	ASSERT_TRUE(gd.IsValid()); //should be coverd in GardenDetails

	GardenMore garden(gd);
	ASSERT_TRUE(gd.IsValid());//should be coverd in GardenMore in other test

	Flower f("rose", "red");
	garden.AddFlower(f);

	ASSERT_TRUE(garden.DoesHaveFlowers());
}

//should be testing the same as previous test
TEST(GardenMoreTest, TestGardenDetailsHasFlowersFalse2) {
	GardenMore garden(GardenDetails(1.0, 2.0));
	garden.AddFlower(Flower("rose", "red"));

	ASSERT_TRUE(garden.DoesHaveFlowers());
}

TEST(GardenMoreTest, TestGardenDetailsAddFlowerThrowException1) {
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
TEST(GardenMoreTest, TestGardenDetailsAddFlowerThrowException2) {
	GardenDetails gDetails;
	GardenMore garden(gDetails);
	Flower f("rose", "red");

	ASSERT_THROW(garden.AddFlower(f), std::runtime_error);
}


TEST(GardenMoreTest, TestGardenDetailsMinor) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 2));

	ASSERT_TRUE(g1 < g2);
}

TEST(GardenMoreTest, TestGardenDetailsMinor2) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 2));

	ASSERT_FALSE(g2 < g1);
}

TEST(GardenMoreTest, TestGardenDetailsMajor) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 2));

	ASSERT_TRUE(g2 > g1);
}

TEST(GardenMoreTest, TestGardenDetailsMajor2) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 2));

	ASSERT_FALSE(g1 > g2);
}

TEST(GardenMoreTest, TestGardenDetailsEqual) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 1));

	ASSERT_TRUE(g2 == g1);
}

TEST(GardenMoreTest, TestGardenDetailsDifferent) {
	GardenMore g1(GardenDetails(1, 2));
	GardenMore g2(GardenDetails(2, 1));

	ASSERT_FALSE(g2 != g1);
}

//example for using mock
TEST(GardenMoreTest, TestGardenDetailsCalcPriceWithMockOfPrice) {
	GardenDetails gDetails(1.0, 2.0);
	GardenMore garden(gDetails);
	garden.AddFlower(Flower("rose", "red"));

	//MOCK part
	using ::testing::_;
	using ::testing::Return;
	const MockPrice mock;
	EXPECT_CALL(mock, Calculate) //use Calculate is similar to Calculate(_) and Calculate(garden.GetFlowers()) is more restrictive
		.WillOnce(Return(10.0));
	//end mock
	auto price = garden.GetPrice(mock);

	EXPECT_EQ(price, 10.0);
}


//mock not necessary if GardenMore is not responsible to compute price
TEST(GardenMoreTest, TestGardenDetailsIntegrationWithPrice) {
	GardenDetails gDetails(1.0, 2.0);
	GardenMore garden(gDetails);
	garden.AddFlower(Flower("rose", "red"));//rose price 1.0 by default

	EXPECT_EQ(Price().Calculate(garden.GetFlowers()), 1.0);
}