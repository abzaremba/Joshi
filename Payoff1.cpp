#include "Payoff1.h"
#include <MinMax.h>

Payoff::Payoff(double Strike_, OptionType TheOptionsType_)
	:
Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

double Payoff::operator()(double spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return max(spot - Strike, 0.0);

	case put:
		return max(Strike - spot, 0.0);

	case digital_call:
		return Strike > spot ? 1 : 0;

	default:
		throw("Unknown option type found.");
	}
}