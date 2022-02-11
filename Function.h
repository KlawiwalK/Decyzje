#pragma once
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
#include <map>
using namespace std;
struct Rule {
    bool greater;
    double compare;
    string value;
    string positive;
    string negative;
};

map<string, vector<double>> Openvalues(int& e, int& mapl,  vector<string>& line);
/**/

map<string, Rule> Setrule();
/**/

string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i);

void Variables(map<string, vector<double>> values, map<string, Rule>& rules, int e, vector<string>& line);
/**/



