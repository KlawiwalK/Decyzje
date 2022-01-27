#pragma once
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
using namespace std;


vector<pair<float, float>> Openvalues(int& length);
/*Funkcja pobiera zawartość pliku "wartości", a następnie zczytuje je do wektora par.
Pierwsze dwa elementy są usuwane, albowiem zawierają one wartość typu string, która opisuje zmienną.
Pozostałe elementy są zczytywane do końca pliku, a następnie przekazywane dalej w formie wektora.*/

void Setrule(string& znak, string& znakprim, string& test, float& value, float& valueprime, string& wynik1, string& wynik2, string& wynik3);
/*Drzewko zasad jest drzewem binarnym, co oznacza, iż w przypadku spełnienia, bądź niespełnienia warunku 0,
może zostać wykonany warunek 1. Setrule rozdziela poszczególne elementy drzewka zasad na pojedyncze elementy,
a następnie przekazuje je dalej w formie ustalonych zmiennych.*/

void Variables(vector<pair<float, float>> w, string znak, string test, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3);
/* Funkcja sprawdza, który warunek 0 musi zostać spełniony, żeby można było przejść do warunku 1, a następnie 
sprawdza, które warunki zostały spełnione, w zależności od podanych paramertów oraz znaków mniejszości, równości lub
większości.*/
