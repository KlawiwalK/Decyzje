#pragma once
#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>


vector<pair<float, float>> Openvalues(string onen, string twot, int length, int one, int two);

vector<string> Setrules(string rule, string znak, string znakprim, float value, float valueprime, string wynik1, string wynik2, string wynik3);

vector<vector<pair<float, float>>> Variables(string znak, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3);

void Dividing(vector<pair<float, float>>firstresult, vector<pair<float, float>>secondresult, string wynik1, string wynik3);

