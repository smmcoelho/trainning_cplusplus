#include "gtest/gtest.h"

#include <numeric>

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

TEST(DummyTestCase1, Test1) {
	EXPECT_EQ(Calc(), 15);
	EXPECT_TRUE(true); // unnecessary
}