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

map<string, vector<double>> Openvalues(int& e, int& mapl, string& Values, vector<string>& line);
/**/

map<string, Rule> Setrule(string &Rules);
/**/

string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i);

void Variables(string &Results, map<string, vector<double>> values, map<string, Rule>& rules, int e, vector<string>& line);
/**/


