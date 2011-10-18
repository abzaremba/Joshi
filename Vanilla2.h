#ifndef VANILLA2_H	
#define VANILLA2_H	

#include "Payoff3.h"

class VanillaOption
{
public:
	VanillaOption(const Payoff& ThePayoff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	VanillaOption& operator=(const VanillaOption& original);
	~VanillaOption();

	double GetExpiry() const;
	double OptionPayoff(double Spot) const;

private:
	double Expiry;
	Payoff* ThePayoffPtr;
};


#endif