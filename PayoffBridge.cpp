#include "PayoffBridge.h"

PayoffBridge::PayoffBridge(const PayoffBridge& original)
{
	ThePayoffPtr = original.ThePayoffPtr->clone();
}

PayoffBridge::PayoffBridge(const Payoff& innerPayoff)
{
	ThePayoffPtr = innerPayoff.clone();
}

PayoffBridge::~PayoffBridge()
{
	delete ThePayoffPtr;
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge& original)
{
	if (this != &original)
	{
		delete ThePayoffPtr;
		ThePayoffPtr = original.ThePayoffPtr->clone();
	}
	return *this;
}