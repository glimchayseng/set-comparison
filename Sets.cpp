//File: Sets.cpp
//Author: Gavin Limchayseng
//Date: 2/3/2019

#include <iostream>
using namespace std;


int main()
{
	//Starting variables
	int setA = 0;
	int setB = 0;
	int setTemp = 0;
	int temp = 0;
	int input = 0;
	

	//Loading setA
	cout << "Please input numbers from 0->9 for set A and enter -1 when finished: ";
	while (input != -1) {
		cin >> input;
		if (input != -1) {
			setA |= (1 << input);
		}		
	} 
	//Loading setB
	input = 0;
	cout << "Please input numbers from 0->9 for set B and enter -1 when finished: ";
	while (input != -1) {
		cin >> input;
		if (input != -1) {
			setB |= (1 << input);
		}
	}
	cout << endl;

	
	//Printing Set A
	cout << "Set A = {";
	for (int i = 0; i < 10;i++){
		//reading the bit string and outputting the index
		if ((((setA >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
	cout << "}" << endl;
	

	//Printing Set B
	cout << "Set B = {";
	for (int i = 0; i < 10; i++){
		if ((((setB >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
	cout << "}" << endl;
	


	//Union
	setTemp |= setA;
	setTemp |= setB;

	//Printing Union
	cout << "Union of A and B = {";
	for (int i = 0; i < 10; i++){
		if ((((setTemp >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
	cout << "}" << endl;
	setTemp = 0;


	//Intersection
	setTemp |= setA;
	setTemp &= setB;

	//Printing Intersection
	cout << "Intersection of A and B = {";
	for (int i = 0; i < 10; i++){
		if ((((setTemp >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
	cout << "}" << endl;

	//Subtraction
	//Flipping setB
	for (int i = 0; i < 10; i++){
		if ((((setB >> i) % 2) ? '0' : '1') == '1')
			temp |= (1 << i);
	}

	setTemp |= setA;
	setTemp &= temp;

	//Printing Subtraction
	cout << "Subraction of A minus B = {";
	for (int i = 0; i < 10; i++) {
		if ((((setTemp >> i) % 2) ? '1' : '0') == '1')
			cout << i << " ";
	}
	cout << "}" << endl << endl;

	int lemon;
	cin >> lemon;
	return 0;
}
