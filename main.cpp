#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include "FileModel.h"
using namespace std;
int main() {
	float value, valueprime;
	int length, lengthresult1, truth;
	string znak, test, znakprim, rule, result1, result2, wynik1, wynik2, wynik3;
	length = 0;
	value = 0;
	valueprime = 0;
	vector<pair<float, float>> w;
	vector<string> p;

	vector<pair<float, float>> firstresult;
	vector<pair<float, float>> secondresult;
	vector<pair<float, float>> thirdresult;
	w=Openvalues(length);

	Setrule(znak, znakprim, test, value, valueprime, wynik1,  wynik2, wynik3);
	

	Variables(w, znak, test, znakprim, length, value, valueprime, wynik1, wynik2, wynik3);

	return 0;
}

