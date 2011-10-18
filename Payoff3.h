#ifndef PAYOFF3_H
#define PAYOFF3_H

class Payoff
{
public:
	Payoff(){};

	virtual double operator()(double Spot) const = 0;
	virtual ~Payoff(){}
	virtual Payoff* clone() const = 0;
};


class PayoffCall : public Payoff
{
public:
	PayoffCall(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayoffCall(){}
	virtual Payoff* clone() const;

private:
	double Strike;
};

class PayoffPut : public Payoff
{
public:
	PayoffPut(double Strike_);

	virtual double operator()(double Spot) const;
	virtual ~PayoffPut(){}
	virtual Payoff* clone() const;

private:
	double Strike;
};

#endif