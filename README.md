# Decyzje
Krótki projekt na PPK na zaliczenie semestru.
Dzień dobry. Projekt będzie się składał z kilku ważnych plików. Function.cpp, Function.h i main.cpp są odpowiedzialne za uruchomienie kodu.
Values jest plikiem tekstowym, gdzie należy umieścić pary wartości, które zostaną porównane do wartości w pliku zasad. Pierwsze dwa wyrazy powinny zostać zarezerwowane dla nazwania wartości.
Rules jest plikiem tekstowym, gdzie znajduje się drzewo binarne z zasadami porównywania. Posiada ono następującą zależność:
0 (Pierwsza wartość porównywana z pliku wartości txt) (Znak porównania - ">", "<", "=") (Wartość do której zostanie porównana) (Wynik jeżeli nie) (Wynik jeżeli tak)
1 (Druga wartość porównywana z pliku wartości txt) (Znak porównania - ">", "<", "=") (Wartość do której zostanie porównana) (Wynik jeżeli nie) (Wynik jeżeli tak)
UWAGA! W równaniu zerowym jeden z wyników może zostać określony jako "1", co spowoduje skok do następnego warunku. W przypadku braku jedynki, porównanie zostanie zastosowane wyłącznie dla warunku 0, a w przypadku dwóch jedynek, skok zostanie wykonany za każdym razem.
Results jest plikiem, gdzie pojawią się wyniki porównania.
