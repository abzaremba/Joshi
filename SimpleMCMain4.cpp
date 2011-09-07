/*  requires Payoff2.cpp
			 Random1.cpp
			 SimpleMC2.cpp */

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

	unsigned long optionType;

	cout << "\nenter 0 for call, otherwise put ";
	cin >> optionType;

	Payoff* thePayoffPointer;

	if (optionType == 0)
		thePayoffPointer = new PayoffCall(Strike);
	else
		thePayoffPointer = new PayoffPut(Strike);

	double result = SimpleMonteCarlo2(*thePayoffPointer,
									  Expiry,
									  Spot,
									  Vol,
									  r,
									  NumberOfPaths);

	cout << "\nthe price is: " << result << endl;

	double tmp;
	cin >>tmp;

	return 0;

}