#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include "Function.h"
using namespace std;
vector<pair<float, float>> Openvalues(int& length) { 
	ifstream plik;
	float one, two; 
	string onen, twot;
	plik.open("Values.txt");
	if (plik.is_open()) {
		if (plik >> onen >> twot) {
			vector<pair<float, float>> w;
			do {
				plik >> one;
				plik >> two;
				w.push_back({ one, two }); 
			} while (!plik.eof());
			length = w.size();
			length = length - 1;
			cout << length;
			return w;
		}
		else {
			cout << "If you want to use this properly, then you should put"
				"some values in the values.txt in pairs, which will allows the program to compare them.";
			length = 0;
			vector<pair<float, float>> empty = {};
			return empty;
		}
	}
}	

void Setrule(string &znak, string &znakprim, string &test, float &value, float &valueprime, string &wynik1, string &wynik2, string &wynik3) {
	ifstream plikdwa;
	string rule;
	plikdwa.open("Rules.txt");
	vector<string> p;
	do {
		plikdwa >> rule;
		p.push_back({ rule }); // Reads data from rules.txt to a vector of strings, which will be used for the Grand Finale of this code.
	} while (!plikdwa.eof());

	znak = p[2]; //Types the equality or inequality mark from the first condition into a "znak" variable
	znakprim = p[8]; //Types the equality or inequality mark from the second rule condition a "znakprim" variable
	value = stof(p[3]); //Changes the value from the first rule condition a float and puts it as a "value" variable
	valueprime = stof(p[9]); //Changes the value from the second condition into a float and puts it as a "valueprime" variable
	test = p[4];
	wynik1 = p[5]; // Positive result of the first condition, changed into a slightly more friendly for eyes variable.
	wynik2 = p[11]; // Positive result of the second condition, changed into a slightly more friendly for eyes variable, just like before.
	wynik3 = p[10]; // The same as the one above, but a negative result instead of a positive one.
}





void Variables(vector<pair<float, float>> w,string znak, string test, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3) {
	ofstream plikprim;
	plikprim.open("Results.txt"); 
	vector<pair<float, float>> firstresult;
	vector<pair<float, float>> secondresult;
	vector<pair<float, float>> thirdresult;
	if (test == "1") { //Checks, if the function has to jump in case of a negative or positive solution of the first rule
		if (znak == ">") { //If mark from the first condition is this one, checks if it is true.
			for (int j = 0; j < length; j++) {
				if (w[j].first > value) {
					firstresult.push_back({ w[j].first, w[j].second });
					cout << wynik1 << endl;
				}
				else { //If not true, checks the inequality or equality mark in the second condition.
					if (znakprim == ">") {
						if (w[j].second > valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							secondresult.push_back({ w[j].first, w[j].second });
							cout << wynik3 << endl;
						}
					}
					if (znakprim == "<") {
						if (w[j].second < valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}
					}
				}

			}
		}
		if (znak == "<") { 
			for (int j = 0; j < length; j++) {

				if (w[j].first < value) {
					firstresult.push_back({ w[j].first, w[j].second });
					cout << wynik1 << endl;
				}
				else {
					if (znakprim == "=") {
						if (w[j].second == valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}
					}
					if (znakprim == "<") {
						if (w[j].second < valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}

					}
				}

			}
		}
		int lengthresult1 = firstresult.size();
		int lengthresult2 = secondresult.size();
		int lengthresult3 = thirdresult.size();
		plikprim << wynik1 << endl;
		for (int i = 0; i < lengthresult1; i++) {
			plikprim << firstresult[i].first << " " << firstresult[i].second << endl;
		}
		plikprim << wynik3 << endl;
		for (int i = 0; i < lengthresult2; i++) {
			plikprim << secondresult[i].first << " " << secondresult[i].second << endl;

		}
		plikprim << wynik2 << endl;
		for (int i = 0; i < lengthresult3; i++) {
			plikprim << thirdresult[i].first << " " << thirdresult[i].second << endl;

		}
	}
	else{
		if (znak == ">") { 
			for (int j = 0; j < length; j++) {
				if (w[j].first < value or w[j].first==value) {
					firstresult.push_back({ w[j].first, w[j].second });
					cout << test << endl;
				}
				else {
					if (znakprim == ">") {
						if (w[j].second > valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							secondresult.push_back({ w[j].first, w[j].second });
							cout << wynik3 << endl;
						}
					}
					if (znakprim == "<") {
						if (w[j].second < valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}
					}
				}

			}
		}
		if (znak == "<") { 
			for (int j = 0; j < length; j++) {

				if (w[j].first > value or w[j].first == value) {
					firstresult.push_back({ w[j].first, w[j].second });
					cout << test << endl;
				}
				else {
					if (znakprim == ">") {
						if (w[j].second > valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}
					}
					if (znakprim == "<") {
						if (w[j].second < valueprime) {
							thirdresult.push_back({ w[j].first, w[j].second });
							cout << wynik2 << endl;
						}
						else {
							cout << wynik3 << endl;
							secondresult.push_back({ w[j].first, w[j].second });
						}

					}
				}

			}
		}
		int lengthresult1 = firstresult.size();
		int lengthresult2 = secondresult.size();
		int lengthresult3 = thirdresult.size();
		plikprim << test << endl;

		for (int i = 0; i < lengthresult1; i++) {
			plikprim << firstresult[i].first << " " << firstresult[i].second << endl;
		}
		plikprim << wynik3 << endl;
		for (int i = 0; i < lengthresult2; i++) {
			plikprim << secondresult[i].first << " " << secondresult[i].second << endl;

		}
		plikprim << wynik2 << endl;
		for (int i = 0; i < lengthresult3; i++) {
			plikprim << thirdresult[i].first << " " << thirdresult[i].second << endl;
		}
	}
}

