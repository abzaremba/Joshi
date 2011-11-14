#include "Vanilla3.h"

	//VanillaOption(const PayoffBridge &ThePayoff_, double Expiry);
	//double OptionPayoff(double Spot) const;
	//double GetExpiry() const;

VanillaOption::VanillaOption(const PayoffBridge &ThePayoff_, double Expiry_) :
		ThePayoff(ThePayoff_), Expiry(Expiry_)
{
}

double VanillaOption::OptionPayoff(double Spot) const
{
	return ThePayoff(Spot);
}
