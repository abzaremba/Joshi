#include "Payoff1.h"
#include <MinMax.h>

VanillaPayoff::VanillaPayoff(double Strike_, OptionType TheOptionsType_)
	:
Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

double VanillaPayoff::operator()(double spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return max(spot - Strike, 0.0);

	case put:
		return max(Strike - spot, 0.0);

	default:
		throw("Unknown option type found.");
	}
}


DoubleBarrierPayoff::DoubleBarrierPayoff(double BarrierLower_, double BarrierUpper_, OptionType TheOptionsType_)
	:
BarrierLower(BarrierLower_), BarrierUpper(BarrierUpper_), TheOptionsType(TheOptionsType_)
{
}

double DoubleBarrierPayoff::operator()(double spot) const
{
	switch (TheOptionsType)
	{
	case in:
		return (BarrierUpper_ > spot && spot > BarrierLower_) ? 1 : 0;

	case out:
		return (BarrierUpper_ < spot || spot < BarrierLower_) ? 1 : 0;

	default:
		throw("Unknown option type found.");
	}
}