#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "Payoff1.h"

double SimpleMonteCarlo2(const Payoff& thePayoff,
						 double Expiry,
						 double Spot,
						 double Vol,
						 double r,
						 unsigned long NumberofPaths);


#endif