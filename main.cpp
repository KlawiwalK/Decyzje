#include <iostream> 
#include <random>
#include <chrono>
#include <fstream>
#include <sstream> 
#include <vector>
using namespace std;
int main(){
	float one, two, ruleandno, resultandyes;
  int length;
  double* pint;
  length = 0;
  pint = nullptr;
  ifstream plik;
  plik.open("Values.txt");
  vector<pair<float, float>> w;
  do {
	  plik >> one;
	  plik >> two;
	  w.push_back({ one, two });
  } while (!plik.eof());
  length=w.size();
  cout << length;


  pint = nullptr;
  ifstream plikrule;
  plikrule.open("rules.txt");
  vector<pair<string, string>> s;
  do {
	  plik >> ruleandno;
	  plik >> resultandyes;
	  w.push_back({ ruleandno, resultandyes });
  } while (!plik.eof());


  ofstream plikprim;
  plikprim.open("Results.txt");
  for (int i = 0; i < length; i++) {
	  if (w[i].first > 190.0) {
		  plikprim << "basketball"<<endl;
	  }
	  else{
		  if (w[i].second > 50) {
			  plikprim << "basketball" << endl;
		  }
		  else {
			  plikprim << "athletics" << endl;
		  }
	  }
  }
}

