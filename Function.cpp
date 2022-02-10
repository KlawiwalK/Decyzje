#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include "Function.h"
#include <map>
using namespace std;
map<string, vector<double>> Openvalues(int& e, int& mapl, vector<string>& line) {
	map<string, vector<double>> values;
	ifstream plik;
	double one;
	string str, onen;
	plik.open(Values);

	if (plik.is_open()) {
		mapl = 0;
		if (getline(plik, str)) {
			stringstream decoder;
			decoder << str;
			string s;
			while (decoder >> s) {
				line.push_back(s);
			}
			vector<double> w;
			e = 0;
			do {
				double tempdb;
				for (auto label : line) {
					plik >> tempdb;
					values[label].push_back(tempdb);
				}
				e++;
			} while (!plik.eof());
			mapl = values.size();
			return values;
		}
		else {
			cout << " In order to use this program properly, in file 'Values' you have to put at least two" << endl <<
				"different values, which will be compared. Each value should be labelled in the first line" << endl <<
				" the same way as in 'Rules' file. ";
			do {
				double tempdb;
				for (auto label : line) {
					plik >> tempdb;
					values[label].push_back(tempdb);
				}
				e++;
			} while (!plik.eof());
			mapl = 0;
			return values;
		}
	}
}


map<string, Rule> Setrule() {
	ifstream plikdwa;
	string rule;
	plikdwa.open("Rules.txt");
	map<string, Rule> p;
	bool greater;
	double compare;
	string key, value, positive, negative;
	char sign;

	while (plikdwa >> key >> value >> sign >> compare >> positive >> negative) {
		if (sign == '>')greater = true;
		else greater = false;
		p[key] = { greater, compare, value, positive, negative };
	}
	return p;
}


string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i) {
	cout << ruleNumber << i << endl;
	if (rules.find(ruleNumber) != rules.end()) {
		cout << "try";
		Rule r = rules[ruleNumber];
		cout << endl << r.greater << " " << r.compare << " " << r.value << " " << r.positive << " " << r.negative;
		if (r.greater) {
			cout << endl << values[r.value][0] << " " << values[r.value][i];
			if (values[r.value][i] < r.compare) {
				cout << "1";
				return Applyrule(rules, values, r.positive, i);
			}
			else {
				cout << "2";
				return Applyrule(rules, values, r.negative, i);
			}
		}
		else {

			if (values[r.value][i] > r.compare) {
				return Applyrule(rules, values, r.positive, i);
			}
			else {
				return Applyrule(rules, values, r.negative, i);
			}
		}
	}
	else {
		cout << "tryno";
		return ruleNumber;
	}
}


void Variables(map<string, vector<double>> values, map<string, Rule>& rules, int e,  vector<string>& line) {
	map<string, vector<int>> results;
	ofstream plik;
	plik.open("Results.txt");
	cout << e;
	for (int i = 0; i < e; i++) {
		results[Applyrule(rules, values, "0", i)].push_back(i);
	}
	cout << "testapp";
	for (auto res : results) {
		plik << res.first << endl;
		for (auto k : res.second) {
			for (auto name : line) {
				plik << values[name][k];
			}
			plik << endl;
		}
	}
}
