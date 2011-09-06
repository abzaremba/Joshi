#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff
{
public:
	enum OptionType {call, put, digital_call};
	Payoff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	double Strike;
	OptionType TheOptionsType;
};

#endif