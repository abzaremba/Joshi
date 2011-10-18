#include "Vanilla1.h"

VanillaOption::VanillaOption(Payoff& ThePayoff_, double Expiry_)
	: ThePayoff(ThePayoff_), Expiry(Expiry_)
{
}



double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayoff(double Spot) const
{
	return ThePayoff(Spot);
}