#ifndef VANILLA_1_H
#define VANILLA_1_H

#include "Payoff2.h"

class VanillaOption
{
public:
	VanillaOption(Payoff& ThePayoff_, double Expiry_);
	double GetExpiry() const;
	double OptionPayoff(double Spot) const;

private:
	double Expiry;
	Payoff& ThePayoff;
};

#endif