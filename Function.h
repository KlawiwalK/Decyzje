#pragma once
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
using namespace std;


vector<pair<float, float>> Openvalues(int length);

void Setrule(string znak, string znakprim, float value, float valueprime, string wynik1, string wynik2, string wynik3);

void Variables(vector<pair<float, float>> w, string znak, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3);


