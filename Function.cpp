#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
#include "FileModel.h"
using namespace std;
vector<pair<float,float>> Openvalues(string onen, string twot, int &length, int one, int two) {
	ifstream plik;
	plik.open("Values.txt");
	if (plik.is_open()) {
		if (plik.eof() == true) {
			cout << "If you want to use this properly, then you should put"
				"some values in the values.txt in pairs, which will allows the program to compare them.";
		}
		vector<pair<string, string>>;
		vector<pair<float, float>> w;
		plik >> onen >> twot;
		do {
			plik >> one;
			plik >> two;
			w.push_back({ one, two }); //Reads data from values.txt to a vector of float pairs, until the file is over.
		} while (!plik.eof());
		length = w.size();
		cout << length;
		return w;
	}
}
vector<string> Setrules(string rule, string &znak, string &znakprim, float &value, float &valueprime, string &wynik1, string &wynik2, string &wynik3) {
	ifstream plikdwa;
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
	wynik1 = p[5]; // Positive result of the first condition, changed into a slightly more friendly for eyes variable.
	wynik2 = p[11]; // Positive result of the second condition, changed into a slightly more friendly for eyes variable, just like before.
	wynik3 = p[10]; // The same as the one above, but a negative result instead of a positive one.
	return p;
}





vector<pair<float, float>> Variables(string znak, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3) {
	ofstream plikprim;
	plikprim.open("Results.txt"); //Hell begins, here we go...
	vector<pair<float, float>> firstresult;
	vector<pair<float, float>> secondresult;
	vector<vector<pair<float, float>>> wektorow;
	vector<pair<float, float>> w;
	if (znak == ">") { //If mark from the first condition is this one, checks if it is true.
		for (int j = 0; j < length; j++) {
			if (w[j].first > value) {
				firstresult.push_back({ w[j].first, w[j].second });
				cout << wynik1 << endl;
			}
			else { //If not true, checks the inequality or equality mark in the second condition.
				if (znakprim == ">") {
					if (w[j].second > valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						secondresult.push_back({ w[j].first, w[j].second });
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						secondresult.push_back({ w[j].first, w[j].second });
						cout << wynik3 << endl;
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
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



	if (znak == "=") { //The same as before, but in case the equality/inequality mark is different, but code will do the same job.
		for (int j = 0; j < length; j++) {
			if (w[j].first = value) { //Checks if the first condition is correct.
				firstresult.push_back({ w[j].first, w[j].second });
				cout << wynik1 << endl;
			}
			else {
				if (znakprim == ">") { //If not, checks for every other possibility.
					if (w[j].second > valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						cout << wynik2 << endl;
						firstresult.push_back({ w[j].first, w[j].second });
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					}
				}
			}

		}
	}



	if (znak == "<") { //And the same for the third possible mark or equality/inequality.
		for (int j = 0; j < length; j++) {

			if (w[j].first < value) {
				firstresult.push_back({ w[j].first, w[j].second });
				cout << wynik1 << endl;
			}
			else {
				if (znakprim == ">") {
					if (w[j].second > valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });// Is anyone still reading this?
						cout << wynik2 << endl;
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					}
				}
				if (znakprim == "=") {
					if (w[j].second = valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					}
				}
				if (znakprim == "<") {
					if (w[j].second < valueprime) {
						firstresult.push_back({ w[j].first, w[j].second });
						cout << wynik2 << endl;
					}
					else {
						cout << wynik3 << endl;
						secondresult.push_back({ w[j].first, w[j].second });
					} //If so, congratulations, it is almost the end of this code.

				}
			}

		}

	}
	return firstresult;

}
void Dividing(vector<pair<float, float>>firstresult, vector<pair<float, float>>secondresult , string wynik1, string wynik3) {
	ofstream plikprim;
	plikprim.open("Results.txt");
	int lengthresult1 = firstresult.size();
	int lengthresult2 = secondresult.size();
	plikprim << wynik1 << endl;

	for (int i = 0; i < lengthresult1; i++) {
		plikprim << firstresult[i].first << " " << firstresult[i].second << endl;
	}
	plikprim << wynik3 << endl;
	for (int i = 0; i < lengthresult1; i++) {
		plikprim << secondresult[i].first << " " << secondresult[i].second << endl;

	}
}
