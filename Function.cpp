#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include "Function.h"
#include <map>
using namespace std;
map<string, vector<double>> Openvalues(int& e, int& mapl, string& Values, vector<string>& line) {
	map<string, vector<double>> values;
	ifstream plik;
	string str, onen;
	plik.open(Values.c_str());
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
			plik.close();
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
			plik.close();
			return values;
		}
	}
}


map<string, Rule> Setrule(string& Rules) {
	ifstream plikdwa;
	string rule;
	plikdwa.open(Rules.c_str());
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
	plikdwa.close();
	return p;
}


string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i) {
	cout << ruleNumber << i << endl;
	if (rules.find(ruleNumber) != rules.end()) {
		Rule r = rules[ruleNumber];
		cout << endl << r.greater << " " << r.compare << " " << r.value << " " << r.positive << " " << r.negative;
		if (r.greater) {
			cout << endl << values[r.value][0] << " " << values[r.value][i];
			if (values[r.value][i] < r.compare) {
				return Applyrule(rules, values, r.positive, i);
			}
			else {
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
		return ruleNumber;
	}
}


void Variables(string& Results, map<string, vector<double>> values, map<string, Rule>& rules, int e, vector<string>& line) {
	map<string, vector<int>> results;
	ofstream plik;
	plik.open(Results.c_str());
	cout << e;
	for (int i = 0; i < e; i++) {
		results[Applyrule(rules, values, "0", i)].push_back(i);
	}
	for (auto res : results) {
		plik << res.first << endl;
		for (auto k : res.second) {
			for (auto name : line) {
				plik << values[name][k] << " ";
			}
			plik << endl;
		}
	}
	plik.close();
}
