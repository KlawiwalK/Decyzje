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
/**Function opens the file and checks, if it is not empty.
In case of an empty file, function tells the user how 
to use the program and returns "Wrong data" into results file. 
If the file is not empty, function takes the first 
line of the program and saves the rest of the file 
to a map of values.**/
map<string, vector<double>> Openvalues(int& e, int& mapl, string& Values, vector<string>& line);

/**Funckion uses a structure, whici values saves as a map.
It reads the binary tree and allows to analyse the data in it.**/ 
map<string, Rule> Setrule(string& Rules);

/** Function compares values from the values file and the binary tree, and then
sends its result. Works together with function Variables.**/
string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i);


/** Function Variables uses the function Applyrule, and then saves the result to a file.**/
void Variables(string& Results, map<string, vector<double>> values, map<string, Rule>& rules, int e, vector<string>& line);
