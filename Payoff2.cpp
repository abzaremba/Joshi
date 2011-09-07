#include "Payoff2.h"
#include <minmax.h>

PayoffCall::PayoffCall(double Strike_) : Strike(Strike_)
{
}
double PayoffCall::operator () (double Spot) const
{
	return max(Spot-Strike, 0.0);
}
double PayoffPut::operator () (double Spot) const
{
	return max(Strike-Spot, 0.0);
}
PayoffPut::PayoffPut(double Strike_) : Strike(Strike_)
{
}

