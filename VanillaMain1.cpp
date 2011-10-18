/* requires DoubleDigital.cpp
			Payoff2.cpp
			Random1.cpp
			SimpleMC3.cpp
			Vanilla1.cpp
*/

#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include <iostream>
#include "Vanilla1.h"

using namespace std;

int main_OLDVanilla1()
{
	double Expiry;
	double Low, Up;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;
	cout << "\nEnter low barrier and up barrier\n";
	cin >> Low >> Up;
	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nEnter r\n";
	cin >> r;
	cout << "\nEnter number of paths\n";
	cin >> NumberOfPaths;

	PayoffDoubleDigital thePayoff(Low, Up);
	VanillaOption theOption(thePayoff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);



	cout << "\nthe price is: " << result << "\n";
		 
	double tmp;
	cin >> tmp;

	return 0;

}