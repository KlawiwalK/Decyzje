#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
//#include "FileModel.h"
using namespace std;
int main() {
	float value, valueprime, one, two;
	int length;
	double* pint;
	string rule;
	length = 0;
	pint = nullptr;
	ifstream plik;
	plik.open("Values");
	vector<pair<float, float>> w;
	do {
		plik >> one;
		plik >> two;
		w.push_back({ one, two });
	} while (!plik.eof());
	length = w.size();
	cout << length;


	ifstream plikdwa;
	plikdwa.open("Rules");
	vector<string> p;
	do {
		plikdwa >> rule;
		p.push_back({ rule });
	} while (!plikdwa.eof());

	value = stof(p[3]);
	valueprime = stof(p[9]);
	ofstream plikprim;
	plikprim.open("Results");
	if (p[2] == ">") {
		for (int j =0; j < length; j++) {
			if (w[j].first > value) {
				plikprim << p[5] << endl;
			}
			else {
				if (p[8] == ">") {
					if (w[j].second > valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "=") {
					if (w[j].second = valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "<") {
					if (w[j].second < valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
			}

		}
	}
	if (p[2] == "=") {
		for (int j = 0; j < length; j++) {
			if (w[j].first = value) {
				plikprim << p[5] << endl;
			}
			else {
				if (p[8] == ">") {
					if (w[j].second > valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "=") {
					if (w[j].second = valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "<") {
					if (w[j].second < valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
			}

		}
	}
	if (p[2] == "<") {
		for (int j = 0; j < length; j++) {
			if (w[j].first < value) {
				plikprim << p[5] << endl;
			}
			else {
				if (p[8] == ">") {
					if (w[j].second > valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "=") {
					if (w[j].second = valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
				if (p[8] == "<") {
					if (w[j].second < valueprime) {
						plikprim << p[11] << endl;
					}
					else {
						plikprim << p[10] << endl;
					}
				}
			}

		}
	}	
}
