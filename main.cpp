#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <map>
#include "Function.h"
using namespace std;
int main(int argc, char* argv[]) {     
	map<string, vector<double>> values;
	map<string, Rule> rules;
	double value;
	int e, mapl;
	string Values, Rules, Results, wynik;
	value = 0;
	vector<string> line;
	argc = 7;
	for (int i = 0; i < argc; i++) {
		if (argv[i] == "-p"){
			Rules = string(argv[i + 1]);
		}
		if (argv[i] == "-i") {
			Values = string(argv[i + 1]);
		}
		if (argv[i] == "-o") {
			Results = string(argv[i + 1]);
		}
	}
	cout << "Test działania";
	values=Openvalues( e, mapl, line);
	cout << "test 1";
	if (mapl == 0) {
		ofstream plik;
		plik.open("Results.txt");
		plik << "Wrong data";
		return 0;
	}

	rules=Setrule();
	cout << "test2";

	Variables(values,rules,e, line);
	cout << "test3";

	return 0;
}

