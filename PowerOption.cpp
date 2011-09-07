#include "PowerOption.h"
#include <minmax.h>
#include <math.h>

//using std::pow;

PayoffPowerCall::PayoffPowerCall(int Power_, double Strike_) 
	: Power(Power_), Strike(Strike_)
{
}

double PayoffPowerCall::operator()(double Spot) const
{
	return max(pow(Spot,Power)-Strike, 0.0);
}



PayoffPowerPut::PayoffPowerPut(int Power_, double Strike_) 
	: Power(Power_), Strike(Strike_)
{
}

double PayoffPowerPut::operator()(double Spot) const
{
	return max(Strike - pow(Spot,Power), 0.0);
}
