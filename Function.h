#pragma once
#include <iostream> 
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
using namespace std;

/**Funkcja pobiera zawartość pliku "wartości", a następnie zczytuje je do wektora par.
Pierwsze dwa elementy są usuwane, albowiem zawierają one wartość typu string, która opisuje zmienną.
Pozostałe elementy są zczytywane do końca pliku, a następnie przekazywane dalej w formie wektora.
@param length określa długość zwracanego wektora.
@return vector<pair<float, float> w **/

vector<pair<float, float>> Openvalues(int& length);

/**Drzewko zasad jest drzewem binarnym, co oznacza, iż w przypadku spełnienia, bądź niespełnienia warunku 0,
może zostać wykonany warunek 1. Setrule rozdziela poszczególne elementy drzewka zasad na pojedyncze elementy,
a następnie przekazuje je dalej w formie ustalonych zmiennych.
@param znak określa rodzaj znaku dla warunku "0" (Mniejszości, większości lub równości).
@param znakprim określa rodzaj znaku dla warunku "1" (Mniejszości, większości lub równości).
@param test jest rezultatem niespełnienia warunku "0".
@param value jest wartością, do której porównane zostaną parametry na pierwszym miejscu z wektora w.
@param valueprime jest wartością, do której porównane zostaną parametry na drugim miejscu z wektora w.
@param wynik1 jest rezultatem spełnienia warunku "0".
@param wynik2 jest rezultatem spełnienia warunku "1".
@param wynik3 jest rezultatem niespełnienia warunku "1".
@return 0 **/

void Setrule(string& znak, string& znakprim, string& test, float& value, float& valueprime, string& wynik1, string& wynik2, string& wynik3);


/** Funkcja sprawdza, który warunek 0 musi zostać spełniony, żeby można było przejść do warunku 1, a następnie 
sprawdza, które warunki zostały spełnione, w zależności od podanych paramertów oraz znaków mniejszości, równości lub
większości.
@param vector<pair<float, float>> w jest wektorem zawierającym wartości z pliku "Values".
@param znak określa rodzaj znaku dla warunku "0" (Mniejszości, większości lub równości).
@param znakprim określa rodzaj znaku dla warunku "1" (Mniejszości, większości lub równości).
@param length określa długość zwracanego wektora.
@param test jest rezultatem niespełnienia warunku "0".
@param value jest wartością, do której porównane zostaną parametry na pierwszym miejscu z wektora w.
@param valueprime jest wartością, do której porównane zostaną parametry na drugim miejscu z wektora w.
@param wynik1 jest rezultatem spełnienia warunku "0".
@param wynik2 jest rezultatem spełnienia warunku "1".
@param wynik3 jest rezultatem niespełnienia warunku "1".
@return 0 **/

void Variables(vector<pair<float, float>> w, string znak, string test, string znakprim, int length, float value, float valueprime, string wynik1, string wynik2, string wynik3);


