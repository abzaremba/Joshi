/* requires: Paoff2.cpp
			 Random1.cpp
			 simpleMC2.cpp */

#include "SimpleMC2.h"
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

	PayoffCall callPayoff(Strike);
	PayoffPut putPayoff(Strike);

	double resultCall = SimpleMonteCarlo2(callPayoff,
										  Expiry,
										  Spot,
										  Vol,
										  r,
										  NumberOfPaths);

	double resultPut  = SimpleMonteCarlo2(putPayoff,
										  Expiry,
										  Spot,
										  Vol,
										  r,
										  NumberOfPaths);

	cout << "the prices are " << resultCall << " for the call option and " 
							  << resultPut << "for the put.\n";

	double tmp;
	cin >> tmp;

	return 0;

}
