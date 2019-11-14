//  __________________________________
// | SCILibrary.h -  definition       |
// | SCI - September 2015             |
// | SCI - November 2019 - Update     |
// |__________________________________|


//doskonała strona stąd można czerpać
//wiedzę - mój ogromny szacunek
//https://eduinf.waw.pl/
	
	
#ifndef H_SCI_LIBRARY
#define H_SCI_LIBRARY

#include <iostream>
#include <string>

using namespace std;

///
///Funkcja zamienia liczbę z systemu dziesiętnego na system dwójkowy
///
///@param decimal - liczba w systemie dziesiętnym
///
std::string DecToBin(int decimal);

///
///Funkcja zamienia liczbę z systemu dwójkowego na system dziesiętny
///
///@param &binary - referencja na łańcuch reprezentujący liczbę dwójkową
///
int BinToDec(std::string & binary);

///
///Funkcja zamienia liczbę z systemu ósemkowego na system dziesiętny
///
///@param &octal - referencja na łańcuch reprezentujący liczbę ósemkową
///
int OctalToDecimal(std::string & octal);

///
///Funkcja zamienia liczbę z dowolnego systemu na system dziesiętny
///
///@param &number_in_any_system - referencja na łańcuch reprezentujący liczbę zapisaną w rozpatrywanym systemie
///
///@param system - system liczbowy
///
int AnyToDec(std::string & number_in_any_system, int system = 2);

///
///Funkcja sprawdza, czy w tablicy znajduje się szukana wartość
///
///@param tab[] - tablica typu int zawierająca uporządkowane dane (warunek konieczny!)
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - wartość, której szukamy
///
bool BinarySearch(int tab[], int tab_size, int value_searched);

///
///Funkcja sprawdza, czy w tablicy znajduje się szukana wartość
///
///@param tab[] - tablica typu int
///
///@param tab_size - rozmiar tablicy
///
///@param value_searched - wartość, której szukamy
///
bool LineSearch(int tab[], int tab_size, int value_searched);

///
///Funkcja losuje liczbę z przedziału obustronnie domkniętego
///
///@param min - dolna wartość zakresu
///
///@param max - górna wartość zakresu
///
int Rand(int min, int max);

///
///Funkcja zwraca flagę, czy rok jest przestępny
///
///@param year - rok
///
bool checkYear(int year);

///
///Funkcja konwerstuje typ int na std::string
///
///@param value - liczba typu int
///
std::string IntToString(int value);

///
///Funkcja zamienia wartości z a na b i b na a
///
///@param & a - referencja na a
///
///@param & b - referencja na b
///
void Swap(int & a, int & b);

///
///Funkcja zwraca ilość cyfr podanej liczby
///
///@param liczba - liczba dla której wyliczamy z ilu składa się czyfr
///
short CounterDigit(int liczba);

///
///Funkcja sortuje zbiór (tablicę) metodą bąbelkową
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSort(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicę) metodą bąbelkową
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void BubbleSortEasy(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicę) metodą przez wstawianie A
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortA(int tab[], int size);

///
///Funkcja sortuje zbiór (tablicę) metodą przez wstawianie B
///
///@param - tab[] - zbiór (tablica)
///
///@param size - rozmiar tablicy
///
void InsertSortB(int tab[], int size);

///
///Funkcja zwraca flagę, czy łańcch jest palindromem
///
///@param & word - stała refrencja na obiekt klasy std::string
///
bool Palindrome(const std::string & word);

///
///Funkcja zwraca flagę, czy łańcuch jest palindromem
///
///@param & word - stała refrencja na obiekt klasy std::string
///
bool Palindrom(const std::string & napis);

///
///Funkcja zwraca sumę cyfr liczy całkowitej
///
///@param value - liczba
///
int SumDigit(int value);

///
///Funkcja zwraca największy wspólny dzielnik dwóch liczb
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWD(int a, int b);

///
///Funkcja zwraca największy wspólny dzielnik dwóch liczb - wersją zoptymalizowana
///
///@param a - pierwsza liczba
///
///@param b - druga liczba
///
int NWDZOptimized(int a, int b);

///
///Funkcja sprawdza, czy liczba jest liczbą pierwszą
///
///@param candidate - liczba do sprawdzenia
///
bool PrimeNumber(int candidate);

///
///Funkcja sprawdza, czy liczba jest liczbą pierwszą - inne wersja
///
///@param candidate - liczba do sprawdzenia
///
bool Pierwsza(int candidate);

///
///Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
///
///@param tab[] - wskaźnik na tablicę
///
///@param n - rozmiar tablicy
///
void sitoEratostenesa(bool tab[], unsigned int n);

///
///Wyliczenie relacji dwóch liczb
///
enum EComparisons
{
	A_WIEKSZA_B = 0,
	A_MNIEJSZA_B = 1,
	A_ROWNA_B = 2
};

///
///Funkcja zwraca wynik porównania dwóch łańcuchów
///
///@param &a - stała referencja na pierwszy łańcuch do porównania
///
///@param &b - stała referencja na drugi łańcuch do porównania
///
EComparisons Compare(const std::string & a, const std::string & b);

///
///Funckja zwraca pozycję, od której wzorzec znajduje się w tekście lub -1, gdy nie ma wzorca
///
///@param &text - stała referencja na obiekt klasy std::string - tekst
///
///@param &v - stała referencja na obiekt klasy std::string - wzorzec
///
int bruteforce(const std::string & text, const std::string & pattern);

///
///Funkcję odwraca kolejność elementów tablicy - iteracyjnie
///
///@param *tab - wskaźnik na tablicę
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocIteration(int *tab, int left, int right);

///
///Funkcję odwraca kolejność elementów tablicy - rekuracyjnie
///
///@param *tab - wskaźnik na tablicę
///
///@param left - lewy skrajny element tablicy
///
///@param right - prawy skrajny element tablicy
///
void odwrocRecursion(int *tab, int left, int right);

///
///Funkcja rekurencyjna przeszukujaca tablicę celem znalezienia szukanej wartości
///
///@param tab[] - tablica
///
///@param left - lewa wartość przedziału przeszukiwania
///
///@param right - prawa wartość przedziału przeszukiwania
///
///@param x - x wartość szukana
///
void szukajRekurencyjnie(int tab[], int left, int right, int x);

///
///Funkcja rejurencyjna oblicząjąca silnię
///
///@param x - parametr
///
unsigned long int silnia(int x);

///
///Funkcja iteracyjna oblicząjąca kolejny element ciągu Fibonacciego
///
///@param x - parametr
///
unsigned long int FibonacciIteration(int x);

///
///Funkcja rekurencyjna oblicząjąca kolejny element ciągu Fibonacciego
///
///@param x - parametr
///
unsigned long int FibonacciRecursion(int x);

///
///Funkcja rejurencyjna MacCarthy'ego
///
///@param x - parametr
///
unsigned long int MacCarthy(int x);

///
///Funkcja niebezpieczna
///
///@param n
///
///@param p
///
int Danger(int n, int p);

///
///Funkcja sprawdza, czy w tablicy znajduje się szukana wartość
///
///@param *tab - wskaźnik na uporządkowaną tablicę typu int (warunek konieczny)
///
///@param x - wartość szukana
///
///@param left - lewa wartość przedziału zbioru
///
///@param right - prawa wartość przedziału zbioru
///
bool BinarySearchRecursion(int *tab, int x, int left, int right);

///
///Funkcja Ackermanna
///
///@param n
///
///@param p
///
int Ackermann(int n, int p);

///
///Funkcja oblicza wartość wielomianu - schemat Hornera - iteracyjnie
///
///@param wsp[] - tablica współczynników
///
///@param st - stopień wielomianu
///
///@param x - wartość x, dla którego liczymy wartość wielomianu
///
int Horner_Iteration(int wsp[], int st, int x);

///
///Funkcja oblicza wartość wielomianu - schemat Hornera - rekurencyjnie
///
///@param wsp[] - tablica współczynników
///
///@param st - stopień wielomianu
///
///@param x - wartość x, dla którego liczymy wartość wielomianu
///
int Horner_Recursion(int wsp[], int st, int x);

///
///Funkcja zwraca element najczęściej występujący w tablicy (zbiorze) - dominant
///
///@param tab[] - tablica (wektor)
///
///@param size - rozmiar tablicy
///
int dominant(int tab[], int size);

///
///Funkcja zwraca wskaźnik, pod którym znajduje się
///dominant - element najczęściej występujący w tablicy (zbiorze)
///oraz ilość jego wystąpienia
///
///@param tab[] - tablica (wektor)
///
///@param size - rozmiar tablicy
///
int *Dominant(int tab[], int size);

///
///Rekurencyjna funkcja sortowania - quicksort
///
///@param *tablica - wskaźnik na tablicę
///
///@param lewy - indeks dla wartości skrajnej z lewej strony
///
///@param prawy - indeks dla wartości skrajnej z lewej strony
///
void quicksort(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSort
///
///@param *tab - wskaźnik na tablicę
///
///@param lewy - indeks dla wartości skrajnej z lewej strony
///
///@param prawy - indeks dla wartości skrajnej z lewej strony
///
void QuickSort(int *tab, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - QuickSortAlpha
///
///@param *tab - wskaźnik na tablicę
///
///@param lewy - indeks dla wartości skrajnej z lewej strony
///
///@param prawy - indeks dla wartości skrajnej z lewej strony
///
void QuickSortAlpha(int *tablica, int lewy, int prawy);

///
///Rekurencyjna funkcja sortowania - Qsort
///
///@param *tab - wskaźnik na tablicę
///
///@param lewy - indeks dla wartości skrajnej z lewej strony
///
///@param prawy - indeks dla wartości skrajnej z lewej strony
///
void Qsort(int *tab, int left, int right);

///
///Funkcja zwraca medianę zbioru
///
///@param *tab - wskaźnik na tablicę
///
///@param lewy - indeks dla wartości skrajnej z lewej strony
///
///@param prawy - indeks dla wartości skrajnej z lewej strony
///
int Mediana(int *tab, int left, int right);

///
///Funkcja realizuje problem dodawanie bardzo dużych liczb
///Prezentując jedno z wielu rozwiązań, realizowane na przykładzie
///dodatnich liczb całkowitych - przechowywanych w obiektach std::string
///
///Funkcja zwraca łańcuch znaków reprezentujący sumę liczba
///
///@param & number_1 - pierwszy składnik - reprezentowany jako referencja na obiekt klasy std::string
///
///@param & number_2 - drugi składnik - reprezentowany jako referencja na obiekt klasy std::string
///
std::string BigSum(std::string & number_1, std::string & number_2);

///
///Funkcja - wydawanie reszty
///
///@param reszta - reszta do wydania
///
void WydawanieReszty(int reszta);

///
///Funkcja zwraca jednocześnie minimum i maximum tablicy
///
///@param Tab[] - tablica
///
///@param size - rozmiar tablicy
///
void MiniMax(int Tab[], int size);

///
///Szyfrowanie - Funkcja zwraca zaszyfrowany obiekt std::string według klucza - Cezar
///
///@param slowo - obiekt std::string zawierający treść jawną
///
///@param klucz - klucz
///
std::string Szyfrowanie(std::string slowo, int klucz);

///
///Deszyfrowanie - Funkcja zwraca rozszyfrowany obiekt std::string według klucza - Cezar
///
///@param slowo - obiekt std::string zawierający treść zaszyfrowaną
///
///@param klucz - klucz
///
std::string Deszyfrowanie(std::string slowo, int klucz);

///
///Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, są zakodowane
///takim samym kluczem (znak po znaku - ten sam klucz)
///
///@param slowo - napis jawny
///
///@param szyfr - napis zaszyfrowany
///
bool TestujSzyfr(std::string slowo, std::string szyfr);

///
///Funkcja sprawdza, czy indeks tablicy dwuwymiarowej jest poprawny
///
///@param i - wiersz
///
///@param j - kolumna
///
///@param size_i - ilość wierszy
///
///@param size_j - ilość kolumn
///
bool correct_index(int i, int j, int size_i, int size_j);

//Kierunki względem punktu tablicy (geografia - róża wiatrów)
//opakowanie do zadania "Szachownica z monetami"
struct Directions
{
	//zgodnie z ruchem wskazówek zegara
	int NORTH = 0;
	int NORTH_EAST = 0;
	int EAST = 0;
	int SOUTH_EAST = 0;
	int SOUTH = 0;
	int SOUTH_WEST = 0;
	int WEST = 0;
	int NORTH_WEST = 0;
};

//Rekurencja - alpha
void test(int n);

//Rekurencja - beta
void Odliczanie(int i);

//Rekurencja - gamma
long long suma(int n);

//Rekurencja - delta
void zamien(int n);


bool czy_anagram_One(char *a, char *b);
void sortuj(string &napis);
bool czy_anagramy_Two(string napis1, string napis2);


#endif//H_SCI_LIBRARY


/*
//Ucinanie miejsc po przecinku (zastosować uniform)
//double n = 12.325252;   //twoja liczba
//int c, u;
//c = (int)n;                       //część całkowita
//u = n * 100;                     //część ułamkowa
//u %= 100;
//cout << c << "." << u;
*/

/*
void decimal_to_ternary(int liczba)
{
int reszta = liczba % 3;
if (liczba > 1) decimal_to_ternary(liczba / 3);
std::cout << reszta;
return;
}
*/

/*
Liczby rzymskie...
#include <iostream>
#include <string.h>

using namespace std;
const int N = 13;

int main()
{
string rom[N] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int dec[N] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
int x;
string lr = "";

cout << "Podaj dowolna liczbe: " << endl;
cin >> x;

for (int i = 0; i < N; i++)
while (dec[i] <= x)
{
lr += rom[i];
x -= dec[i];
}

cout << "W notacji rzymskiej to: " << lr << endl;
return 0;
}

*/
