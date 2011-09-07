#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "Payoff1.h"

// ...ok, had to change the name of the monte carlo function in SimpleMC 
// from SimpleMonteCarlo2 to SimpleMonteCarlo1, so that it's not defined in SimpleMC and SimpleMC2 in the same way...

double SimpleMonteCarlo(const Payoff& thePayoff,
						 double Expiry,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberofPaths);


#endif