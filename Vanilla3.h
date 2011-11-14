#ifndef VANILLA_3_H
#define VANILLA_3_H

#include "PayoffBridge.h"

class VanillaOption
{
public:
	VanillaOption(const PayoffBridge &ThePayoff_, double Expiry_);
	double OptionPayoff(double Spot) const;
	double GetExpiry() const;

private:
	double Expiry;
	PayoffBridge ThePayoff;
};



#endif