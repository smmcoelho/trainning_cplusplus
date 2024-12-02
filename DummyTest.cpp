#include "gtest/gtest.h"

#include <numeric>

#include "GardenDetails.h"

auto func_accumulate_price = [&](int sum, int f)
{
	return sum + f;
};

double Calculate()
{
	std::vector<int> flowers = {1, 2, 3, 4, 5};
	return std::accumulate(flowers.begin(), flowers.end(), 0, func_accumulate_price);
}

double Calc()
{
	std::vector<int> flowers = { 1, 2, 3, 4, 5 };
	auto sum = 0.0;
	for (const auto& i : flowers)
	{
		sum += i;
	}
	return sum;
}

TEST(DummyTestCase, Test1) {
  EXPECT_EQ(Calculate(), 15);
  EXPECT_TRUE(true); // unnecessary
}

TEST(DummyTestCase, Test2) {
	EXPECT_EQ(Calc(), 15);
	EXPECT_TRUE(true); // unnecessary
}

TEST(DummyTestCaseGardenDetails, Test1) {
	GardenDetails d(1.0, 2.0);
	//std::cout << d;
	//printf("%s", std::string(d).c_str());

	EXPECT_TRUE(true); // unnecessary
}
