/* requires DoubleDigital.cpp
			Payoff2.cpp
			Random1.cpp
			SimplreMC2.cpp */

#include "SimpleMC2.h"
#include "DoubleDigital.h"
#include "PowerOption.h"
#include <iostream>

using namespace std;

int main()
{

	double Expiry;
	double Low, Up;
	double Strike;
	int Power;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;
	cout << "\nEnter low barrier and up barrier\n";
	cin >> Low >> Up;
	cout << "\nEnter power for the power opiton\n";
	cin >> Power;
	cout << "\nEnter strike for the power opiton\n";
	cin >> Strike;
	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nEnter r\n";
	cin >> r;
	cout << "\nEnter number of paths\n";
	cin >> NumberOfPaths;

	PayoffDoubleDigital thePayoff(Low, Up);

	double result = SimpleMonteCarlo2(thePayoff,
									  Expiry,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);

	PayoffPowerCall thePayoffPowerCall(Power, Strike);
	PayoffPowerPut thePayoffPowerPut(Power, Strike);

	double resultDoubleDigit = SimpleMonteCarlo2(thePayoff,
									  Expiry,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);

	double resultPowerCall = SimpleMonteCarlo2(thePayoffPowerCall,
									  Expiry,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);
	double resultPowerPut = SimpleMonteCarlo2(thePayoffPowerPut,
									  Expiry,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);

	cout << "\nthe price of the option is: " << resultDoubleDigit << "\n"
		 << "\nthe price for power call is: " << resultPowerCall 
		 << " and for power put: " << resultPowerPut << "\n";
		 
	double tmp;
	cin >> tmp;

	return 0;
}