#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include "Function.h"
using namespace std;
int main() {
	float value, valueprime, one, two;
	int length, lengthprim, lengthresult1, lengthresult2;
	string znak, znakprim, rule, result1, result2, wynik1, wynik2, wynik3;
	length = 0;
	value = 0;
	valueprime = 0;
	vector<pair<float, float>> w;
	vector<string> p;

	vector<pair<float, float>> firstresult;
	vector<pair<float, float>> secondresult;
	w=Openvalues(length);

	Setrule(znak, znakprim, value, valueprime, wynik1,  wynik2, wynik3);
	

	Variables(w,znak, znakprim, length,value,  valueprime, wynik1, wynik2,  wynik3);

	return 0;
}

