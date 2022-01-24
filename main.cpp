#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
#include "Function.h"
using namespace std;
int main() {
	float value, valueprime, one, two;
	int length, lengthprim, lengthresult1, lengthresult2;
	string znak, znakprim, rule, result1, result2, onen, twot, wynik1, wynik2, wynik3;
	length = 0;
	vector<pair<float, float>> w;
	vector<string> p;

	vector<pair<float, float>> firstresult;
	vector<pair<float, float>> secondresult;
	Openvalues( onen, twot, length, one, two);

	Setrules(rule,znak, znakprim, value, valueprime, wynik1,  wynik2, wynik3);
	

	vector<vector<pair<float, float>>>wektorow = Variables(znak, znakprim, length,value,  valueprime, wynik1, wynik2,  wynik3);

	Dividing(wektorow[0],wektorow[1], wynik1,  wynik3);
	return 0;
}

