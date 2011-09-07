/* requires Payoff1.cpp,
			Random1.cpp,
			SimpleMC.cpp
			*/

#include "SimpleMC.h"
#include <iostream>

using namespace std;

int main_OLD2()
{
	double Expiry;
	double Strike;
	double BarrierLower;
	double BarrierUpper;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter lower barrier for double digital\n";
	cin >> BarrierLower;

	cout << "\nEnter upper barrier for double digital\n";
	cin >> BarrierUpper;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter Vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nEnter number of paths\n";
	cin >> NumberOfPaths;

	VanillaPayoff callPayoff(Strike, VanillaPayoff::call);
	VanillaPayoff putPayoff(Strike, VanillaPayoff::put);
	DoubleBarrierPayoff inDigitalPayoff(BarrierLower, BarrierUpper, DoubleBarrierPayoff::inside);
	DoubleBarrierPayoff outDigitalPayoff(BarrierLower, BarrierUpper, DoubleBarrierPayoff::outside);

	double resultCall = SimpleMonteCarlo(callPayoff,
										  Expiry,
										  Spot,
										  Vol,
										  r,
										  NumberOfPaths);

	double resultPut = SimpleMonteCarlo(putPayoff,
										 Expiry,
										 Spot,
										 Vol,
										 r,
										 NumberOfPaths);

	double resultInDoubleDigital = SimpleMonteCarlo(inDigitalPayoff,
										 Expiry,
										 Spot,
										 Vol,
										 r,
										 NumberOfPaths);

	double resultOutDoubleDigital = SimpleMonteCarlo(outDigitalPayoff,
										 Expiry,
										 Spot,
										 Vol,
										 r,
										 NumberOfPaths);

	cout << "the prices are: " << resultCall
							   << " for the call and "
							   << resultPut
							   << " for the put.\n"
							   << resultInDoubleDigital
							   << " for the digital in "
							   << resultOutDoubleDigital
							   << " for the digital out\n";

	double tmp;
	cin >> tmp;
	return 0;
}