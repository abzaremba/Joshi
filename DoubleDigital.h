#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H

#include "Payoff2.h"

class PayoffDoubleDigital : public Payoff
{
public:
	PayoffDoubleDigital(double LowerLevel_, double UpperLevel_);
	virtual double operator()(double Spot) const;
	virtual ~PayoffDoubleDigital(){}

private:
	double UpperLevel;
	double LowerLevel;
};

#endif