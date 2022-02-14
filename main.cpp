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
    if (argc == 7) {
        for (int i = 1;i < argc;i++) {
            if (string(argv[i]) == "-i") {
                if (argv[i + 1] != ("")) {
                    Values = argv[i + 1];
                    i++;
                }
                else {
                    std::cout << "Brak parametru -i" << endl;
                    return 0;
                }
            }
            else if (string(argv[i]) == "-o") {
                if (argv[i + 1] != "") {
                    Results = argv[i + 1];
                    i++;
                }
                else {
                    cout << "Brak parametru -o" << endl;
                    return 0;
                }
            }
            else if (string(argv[i]) == "-t") {
                if (argv[i + 1] != "") {
                    Rules = argv[i + 1];
                    i++;
                }
                else {
                    cout << "Brak parametru -t" << endl;
                    return 0;
                }
            }
        }
    }
    else {
        cout << "Podano bledna ilosc parametrow" << endl;
        return 0;
    }
    values = Openvalues(e, mapl, Values, line);

    if (mapl == 0) {
        ofstream plik;
        plik.open("Results.txt");
        plik << "Wrong data";
        return 0;
    }
    rules = Setrule(Rules);

    Variables(Results, values, rules, e, line);

    return 0;
}
