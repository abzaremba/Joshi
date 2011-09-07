#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff
{
public:
	//enum OptionType {call, put};
	//Payoff(double Strike_, OptionType TheOptionsType_);
	virtual double operator()(double Spot) const = 0;

private:
	//double Strike;
	//OptionType TheOptionsType;
};


class VanillaPayoff : public Payoff
{
public:
	enum OptionType {call, put};
	VanillaPayoff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	double Strike;
	OptionType TheOptionsType;
};


class DoubleBarrierPayoff : public Payoff
{
public:
	enum OptionType {in, out};
	DoubleBarrierPayoff(double BarrierLower_, double BarrierUpper_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	double BarrierLower, BarrierUpper;
	OptionType TheOptionsType;
};



#endif