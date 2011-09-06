// requires Random1.cpp

#include "Random1.h"
#include <iostream>
#include <cmath>
using namespace std;

double SimpleMontecarlo1(double Expiry, 
						 double Strike1,
						 double Strike2,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberOfPaths)
{
	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*exp(r*Expiry +itoCorrection);
	double thisSpot;
	double runningSum=0;

	for (unsigned long i=0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		// double thisPayoff = thisSpot - Strike;
		// payoff for put option
		// double thisPayoff = Strike - thisSpot;
		//thisPayoff =thisPayoff >0 ? thisPayoff : 0;
		// this payoff is for double digitals
		double thisPayoff = Strike2 - thisSpot > 0 ? 1 : 0;
		thisPayoff = thisSpot - Strike1 >0 ? thisPayoff : 0;
		
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}


int main ()
{
	double Expiry;
	double Strike1;
	double Strike2;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	cout << "\nEnter expiry \n";
	cin >> Expiry;
	cout << "\nEnter strike 1 \n";
	cin >> Strike1;
	cout << "\nEnter strike 2 \n";
	cin >> Strike2;
	cout << "\nEnter spot \n";
	cin >> Spot;
	cout << "\nEnter vol \n";
	cin >> Vol;
	cout << "\nEnter r \n";
	cin >> r;
	cout << "\nEnter number of paths \n";
	cin >> NumberOfPaths;

	double result = SimpleMontecarlo1(Expiry,
									  Strike1,
									  Strike2,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);
	cout << "The price is " << result << "\n";

	double tmp;
	cin >> tmp;

	return 0;
}