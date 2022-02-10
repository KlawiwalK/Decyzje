#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <map>
#include "FileModel.h"
using namespace std;
int main(int argc, char* argv[]) {     
	// -i -o -p
	if (argc != 3) {
		return 0; // Jeśli nie podadzą dwóch plików, cała funkcja się kończy, zanim się zacznie
	}
	map<string, vector<double>> values;
	map<string, Rule> rules;
	double value;
	int e, mapl; //mapl sprawdza, czy plik Values nie jest pusty
	string Values, Rules, Results, filename1, filename2, filename3, testow, test, wynik;
	value = 0;
	vector<string> line;
	Values = argv[0];
	Rules = argv[1];
	Results = argv[2];
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

