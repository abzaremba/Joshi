#ifndef POWEROPTION_H
#define POWEROPTION_H

#include "Payoff2.h"

class PayoffPowerCall : public Payoff
{
public:
	PayoffPowerCall (int Power_, double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayoffPowerCall(){}
private:
	int Power;
	double Strike;
};

class PayoffPowerPut : public Payoff
{
public:
	PayoffPowerPut (int Power_, double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayoffPowerPut(){}
private:
	int Power;
	double Strike;
};



#endif