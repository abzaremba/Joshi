/* requires Payoff3.cpp
		    Random1.cpp
			SimpleMC4.cpp
			Vanilla2.cpp
*/

#include "SimpleMC4.h"
#include "Vanilla2.h"
#include <iostream>

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;
	cout << "\nEnter strike\n";
	cin >> Strike;
	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nEnter r\n";
	cin >> r;
	cout << "\nEnter number of paths\n";
	cin >> NumberOfPaths;

	PayoffCall thePayoff(Strike);
	VanillaOption theOption(thePayoff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);



	cout << "\nthe price is: " << result << "\n";

	VanillaOption secondOption(theOption);
	result = SimpleMonteCarlo3(theOption,
							   Spot,
							   Vol,
							   r,
							   NumberOfPaths);

	cout << "\nthe price is: " << result << "\n";

	PayoffPut otherPayoff(Strike);
	VanillaOption thirdOption(otherPayoff, Expiry);
	theOption = thirdOption;
	result = SimpleMonteCarlo3(theOption,
							   Spot,
							   Vol,
							   r,
							   NumberOfPaths);

	cout << "\nthe price is: " << result << "\n";

		 
	double tmp;
	cin >> tmp;

	return 0;
}