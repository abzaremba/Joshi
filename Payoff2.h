#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff
{
public:
	Payoff(){};
	virtual double operator()(double Spot) const=0;
	virtual ~Payoff(){}
private:
};


class PayoffCall : public Payoff
{
public:
	PayoffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayoffCall(){}
private:
	double Strike;
};


class PayoffPut : public Payoff
{
public:
	PayoffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayoffPut(){}
private:
	double Strike;
};

#endif