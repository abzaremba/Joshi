#include "Vanilla2.h"


VanillaOption::VanillaOption (const Payoff& ThePayoff_, double Expiry_)
	: Expiry(Expiry_)
{
	ThePayoffPtr = ThePayoff_.clone();
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
	Expiry = original.Expiry;
	ThePayoffPtr = original.ThePayoffPtr->clone();
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayoff(double Spot) const
{
	return (*ThePayoffPtr)(Spot);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
	if(this != &original){
		Expiry = original.Expiry;
		delete ThePayoffPtr;
		ThePayoffPtr = original.ThePayoffPtr->clone();
	}
	return *this;
}

VanillaOption::~VanillaOption()
{
	delete ThePayoffPtr;
}