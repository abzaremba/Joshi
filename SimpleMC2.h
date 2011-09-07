#ifndef SIMPLEMC_H
#define SIMPLEMC_H


// note SimpleMC2.h differs from SimpleMC.h only in that it uses Payoff2.h istrwad of Payoff1.h
// the appropriate cpp files are identical!

// ...ok, had to change the name of the monte carlo function in SimpleMC 
// from SimpleMonteCarlo2 to SimpleMonteCarlo1, so that it's not defined in SimpleMC and SimpleMC2 in the same way...

#include "Payoff2.h"

double SimpleMonteCarlo2(const Payoff& thePayoff,
						 double Expiry,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberofPaths);


#endif