#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "Payoff3.h"

class PayoffBridge
{
public:
	PayoffBridge(const PayoffBridge& original);
	PayoffBridge(const Payoff& innerPayoff);

	inline double operator()(double Spot) const;
	~PayoffBridge();
	PayoffBridge& operator=(const PayoffBridge& original);

private:
	Payoff* ThePayoffPtr;
};

inline double PayoffBridge::operator()(double Spot) const
{
	return ThePayoffPtr->operator()(Spot);
}


#endif