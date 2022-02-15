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
/**Funkcja otwiera plik z wartościami podany przez użytkownika, a następnie sprawdza, czy podany plik nie jest pusty. 
W przypadku pustego pliku, funkcja zwraca zmienną "mapl" równą zero, informującą o pustym pliku, a także wypisuje krótką informację o tym, jak należy użyć programu. 
W przeciwnym wypadku funkcja pobiera pierwszą linię pliku, a pozostałe wartości zapisuje do mapy "values".**/

map<string, Rule> Setrule(string& Rules);
/**Funckja korzysta ze struktury, której wartości zapisuje do mapy. Służy ona do odczytania drzewa binarnego i analizy danych w nim zawartych.**/

string Applyrule(map<string, Rule>& rules, map<string, vector<double>>& values, string ruleNumber, const int i);
/**Funckja porównuje ze sobą wartości z pliku wartości oraz z drzewa binarnego, a następnie zwraca wartość zależną od otrzymanego wyniku.
Działa ona razem z funkcją Variables.**/

void Variables(string& Results, map<string, vector<double>> values, map<string, Rule>& rules, int e, vector<string>& line);
/**Funckja Variables wykonuje funkcję Applyrule dla wszystkich grup z pliku wartości, a następnie w zależności od wyniku funckji Applyrule, 
zapisuje odpowiednią wartość do pliku.**/
