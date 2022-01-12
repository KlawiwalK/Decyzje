#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
using namespace std;
int main() {
	float value, valueprime, one, two;
	int length, lengthprim;
	double* pint;
	string znak, znakprim, rule, onen, twot, wynik1, wynik2, wynik3;
	length = 0;
	pint = nullptr;
	ifstream plik;
	plik.open("Values.txt");
	vector<pair<string, string>>l;
	plik >> onen >> twot;
	vector<pair<float, float>> w;
	do {
		plik >> one;
		plik >> two;
		w.push_back({ one, two }); //Reads data from values.txt to a vector of float pairs, until the file is over.
	} while (!plik.eof());
	length = w.size();
	cout << length;
	if (length == 0) {
		cout << "If you want to use this properly, then you should put some values in the values.txt in pairs, which will allows the program to compare them.";
		return 0;
	}




	ifstream plikdwa;
	plikdwa.open("Rules.txt");
	vector<string> p;
	do {
		plikdwa >> rule;
		p.push_back({ rule }); // Reads data from rules.txt to a vector of strings, which will be used for the Grand Finale of this code.
	} while (!plikdwa.eof());
	lengthprim = p.size();
	if (lengthprim == 0) {
		cout << "No rules? You need to put rules in rules.txt in a form like this:" << endl;
		cout << "0, name of a compared value, equality or inequality mark, value for the condition which has to be met, goto1(result if false), result if true" << endl;
		cout << "1, name of a compared value, equality or inequality mark, value for the condition which has to be met, result if false, result if true";
		return 0;
	}


	znak = p[2]; //Types the equality or inequality mark from the first condition into a "znak" variable
	znakprim = p[8]; //Types the equality or inequality mark from the second rule condition a "znakprim" variable
	value = stof(p[3]); //Changes the value from the first rule condition a float and puts it as a "value" variable
	valueprime = stof(p[9]); //Changes the value from the second condition into a float and puts it as a "valueprime" variable
	wynik1 = p[5]; // Positive result of the first condition, changed into a slightly more friendly for eyes variable.
	wynik2 = p[11]; // Positive result of the second condition, changed into a slightly more friendly for eyes variable, just like before.
	wynik3 = p[10]; // The same as the one above, but a negative result instead of a positive one.




	ofstream plikprim;
	plikprim.open("Results.txt"); //Hell begins, here we go...
	if (znak == ">") { //If mark from the first condition is this one, checks if it is true.
		for (int j = 0; j < length; j++) {
			if (w[j].first > value) {
				plikprim << wynik1 << endl; //If true, writes the result into results.txt...
				cout << wynik1 << endl;  //...And writes it into the console before going back to the beginning of this abomination.
			}
			else { //If not true, checks the inequality or equality mark in the second condition.
				if (znakprim == ">") {
					if (w[j].second > valueprime) {
						plikprim << wynik2 << endl; //And writes it into results.txt and console depending if it is positive...
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl; //... Or negative.
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
			}

		}
	}



	if (znak == "=") { //The same as before, but in case the equality/inequality mark is different, but code will do the same job.
		for (int j = 0; j < length; j++) {
			if (w[j].first = value) { //Checks if the first condition is correct...
				plikprim << wynik1 << endl; //And if yes, writes it into results.txt
				cout << wynik1 << endl; //And console
			}
			else {
				if (znakprim == ">") { //If not, checks for every other possibility.
					if (w[j].second > valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
			}

		}
	}



	if (znak == "<") { //And the same for the third possible mark or equality/inequality.
		for (int j = 0; j < length; j++) {
			if (w[j].first < value) {
				plikprim << wynik1 << endl;
				cout << wynik1 << endl;
			}
			else {
				if (znakprim == ">") {
					if (w[j].second > valueprime) {
						plikprim << wynik2 << endl; // Is anyone still reading this?
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						plikprim << wynik2 << endl;
						cout << wynik2 << endl;
					}
					else {
						plikprim << wynik3 << endl;
						cout << wynik3 << endl;
					} //If so, congratulations, it is the end of this code.

				}
			}

		}
	}
}

