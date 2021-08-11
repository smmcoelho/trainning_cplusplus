#pragma once

#include "Price.h"

#include "gmock/gmock.h"

class MockPrice : public Price {
public:
	MOCK_METHOD(double, Calculate, (const std::vector<Flower>& flowers), (const, override));
};

