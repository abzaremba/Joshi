#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

// the basic math functions should be in
// namespace std but arent' in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif


double SimpleMonteCarlo(const Payoff& thePayoff,
						 double Expiry,
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
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		double thisPayoff = thePayoff(thisSpot);
		runningSum += thisPayoff;
	}
	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}