//  __________________________________
// | SCILibrary.cpp -  implementation |
// | SCI - September 2015             |
// | SCI - November 2019 - Update     |
// |__________________________________|

#include "SCILibrary.h"
#include <sstream>

//Funkcja zamienia liczbę z systemu dziesiętnego na system dwójkowy
std::string DecToBin(int decimal)
{
	//zmienne pomocnicze lokalne
	int liczba = decimal; //liczba, którą zamieniamy - inicjujemy ją parametrem
	std::string binary = ""; //liczba binarna postaci ciągu zer i jedynek,
	//którą ta funkcja wygenruje - inicjujemy pustym łańcuchem

	//kosmetyka...
	if (liczba == 0)
		return "0"; //bo inaczej nie wejdziemy do pętli while(...)

	//algorytm...

	while (liczba) //dopóki liczba jest różna od zera
	{
		if (liczba % 2 == 0) //jeśli wyrażenie modulo zwraca 0
			binary = "0" + binary; //do łańcucha (tablica char) wstawiamy "0" - cyfrę zero
		else
			binary = "1" + binary; //w przeciwnym wypadku  wstawiamy "1" - cyfrę zero
		liczba /= 2; //dzielimy liczbę na dwa (system dwójkowy)
	}
							
	return binary;
}

//Funkcja zamienia liczbę z systemu dwójkowego na system dziesiętny
int BinToDec(std::string & binary)
{
	//zmienne pomocnicze...
	int x; //odczytany element łańcucha zamieniony na zero lub jedenkę
	int power = 1; //wykładnik potęgowania
	int dlugosc = binary.length(); //wyliczamy długość std::string binary
	int system = 2; //operujemy na systemie dwójkowym
	int result = 0; //wyliczona liczba dziesiętna, którą zwraca ta fukcja

	//zaczynamy od końca łańcucha (tablicy)...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		if (binary[i] == '1') x = 1;
		if (binary[i] == '0') x = 0;
		result += x * power; //do wyniku dodajemy otrzymaną wartość,
        //którą mnożymy przez podstawę systemu do odpowiedniej potęgi
		power *= system; //ustawiamy power (wykładnik) na odpowiednią potegę systemu (2)
	}
	return result;
}

//Funkcja zamienia liczbę z systemu ósemkowego na system dziesiętny
int OctalToDecimal(std::string & octal)
{
	//zmienne pomocnicze...
	int x; //odczytany element łańcucha zamieniony na liczby <0..7> - tyle ich jest w systemie ósemkowym
	int power = 1; //wykładnik potęgowania
	int dlugosc = octal.length(); //wyliczamy długość std::string octal
	int system = 8; //operujemy na systemie ósemkowym
	int result = 0; //wyliczona liczba dziesiętna, którą zwraca ta fukcja

	//zaczynamy od końca łańcucha (tablicy)...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		if (octal[i] == '0') x = 0;
		if (octal[i] == '1') x = 1;
		if (octal[i] == '2') x = 2;
		if (octal[i] == '4') x = 4;
		if (octal[i] == '3') x = 3;
		if (octal[i] == '5') x = 5;
		if (octal[i] == '6') x = 6;
		if (octal[i] == '7') x = 7;
		result += x * power; //do wyniku dodajemy otrzymaną wartość,
		//którą mnożymy przez podstawę systemu
		//do odpowiedniej potęgi
		power *= system; //ustawiamy power (wykładnik) na odpowiednią potegę systemu (2)
	}
	return result;
}


//Funkcja zamienia liczbę z dowolnego systemu na system dziesiętny
int AnyToDec(std::string & number_in_any_system, int system)
{
	int x; //odczytany element łańcucha
	int wynik = 0; //wartość, którą zwraca ta funkcja
	int power = 1; //potęga
	int dlugosc = number_in_any_system.length();//wyliczamy długość std::string binary

	//zaczynamy od końca tablicy...
	for (int i = dlugosc - 1; i >= 0; i--)
	{
		//jeżeli odczytany element łańcucha jest cyfrą...
		if (number_in_any_system[i] >= '0' && number_in_any_system[i] <= '9')
			//odejmujemy kod zera - zamieniamy kod cyfry na cyfrę
			x = number_in_any_system[i] - '0';
		else
			//jeżeli jest to litera (musi byc duża)
			x = number_in_any_system[i] - 55;//to odejmujemy 55 np. A(65) - 55 = 10

		//do wyniku dodajemy otrzymaną wartość
		//pomnożoną przez podstawę systemu do odpowiedniej potęgi
		wynik += x * power; 
		power *= system; // ustawiamy power(wykładnik) na odpowiednią potegę systemu
	}

	return wynik;
}

//Binary Search - implementacja
bool BinarySearch(int tab[], int tab_size, int value_searched)
{
	//zakładamy, że przeszukujemy tablicę w pełnym zakresie
	//czyli całą tablicę od indeksu 0 do ostatniego elementu
	int l = 0; //początek tablicy
	int r = tab_size; //koniec tablicy
	int sr= (l + r)/2; //indeks - wyliczany środek (miejsce) indeks
	bool result = false; //flaga określa, czy w tablicy znajduje się szukana wartość
	//na początku zakładamy, że nie...

	std::cout << "Elementy tablicy:" << std::endl;

	for (int i = 0; i < tab_size; i++)
		std::cout << tab[i] << "  ";

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Szukamy w talicy wartosci: " << value_searched  << std::endl;

	while (l <= r)
	{
		sr = (l + r) / 2;//wyliczamy środek
		if (tab[sr] == value_searched)//jeśli szukana jest w tablicy...
		{
			//można o tym poinformować...
			std::cout << std::endl;
			std::cout << "znaleziono wartosc: "
				<< value_searched
				<< " pod indeksem: "
				<< sr
				<< std::endl
				<< std::endl;
			result = true;
		}
		if (tab[sr] > value_searched)
			r = sr - 1;
		else
			l = sr + 1;
	}

	if(!result)
		std::cout << "Nie znaleziono..." << std::endl;

	return result;
}

//Funkcja sprawdza, czy w tablicy znajduje się szukana wartość
bool LineSearch(int tab[], int tab_size, int value_searched)
{
	for (int i = 0; i < tab_size; i++)
		if (tab[i] == value_searched)
			return true;
	return false;
}

//Funkcja losuje liczbę z przedziału obustronnie domkniętego
int Rand(int min, int max)
{
	// P a m i ę t a j !!! - ziarno
	// Zawsze ustawiaj tylko jeden raz
	// np: w main() - zaraz na początku kodu
	// poprawne wywołanie funkcji:
	// srand((unsigned)time(NULL));

	int pseudolosowa = ((rand() % (max - min + 1))) + (min);
	return pseudolosowa;//nasza cywilizacja potrafi za pomocą
	//komputerów generować tylko liczby
	//p s e u d o l o s o w e
}

//Funkcja zwraca flagę, czy rok jest przestępny
bool checkYear(int year)
{
	//operatory logiczne - poczytać...
	//&& operator AND	- koniunkcja
	//|| operator OR	- alternatywa

	//rok jest przestępny wtedy i tylko wtedy gdy:
	//dzieli się przez 4 i nie dzieli się przez 100,
	//za wyjątkiem lat podzielnych przez 400
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

//Funkcja konwerstuje typ int na std::string
std::string IntToString(int value)
{
	std::stringstream ssBufor; //stringstream...bufor
	std::string sWynik; //zwykły string - to zwraca funkcja
	ssBufor << value; //wysyłamy liczbę int do bufora
	ssBufor >> sWynik; //przepisujemy z bufora do zwykłego stringa,
	//z którym możemy już sobie "poradzić"...
	return sWynik;
}

//Funkcja zamienia wartości z a na b i b na a
void Swap(int & a, int & b)
{
	int pom = a; //zapamiętano a
	a = b; //do a przekazuję b
	b = pom; //do b przekazuję zapamiętane a
}

//Funkcja zwraca ilość cyfr podanej liczby
short CounterDigit(int liczba)
{
	short counter_digit = 0;// licznik cyfr
	if (liczba == 0) counter_digit = 1;
	while (liczba != 0)
	{
		counter_digit++;
		liczba /= 10;//jest to system dziesiętny
	}
	return counter_digit;
}


//Funkcja sortuje zbiór (tablicę) metodą bąbelkową
void BubbleSort(int tab[], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++) //pętla wewnętrzna
			if (tab[j] > tab[j + 1])
			{
				//zamiana miejscami jeśli warunek jest spełniony
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
}

//Funkcja sortuje zbiór (tablicę) metodą bąbelkową
void BubbleSortEasy(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
				Swap(tab[j], tab[j + 1]);//zamiana miejscami jeśli warunek jest spełniony
		}
	}
}

//Funkcja sortuje zbiór (tablicę) metodą przez wstawianie A
void InsertSortA(int tab[], int size)
{
	int pom, j;
	for (int i = 1; i < size; i++)//zaczyna itrerację od drugiego elementu
	{
		//wstawienie elementu w odpowiednie miejsce
		pom = tab[i]; //ten element będzie wstawiony w odpowiednie miejsce
		j = i - 1; //element następny względem i

		//przesuwanie elementów większych od pom
		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j]; //przesuwanie elementów
			--j;
		}
		tab[j + 1] = pom; //wstawienie pom w odpowiednie miejsce
	}
}

//Funkcja sortuje zbiór (tablicę) metodą przez wstawianie B
void InsertSortB(int tab[], int size)
{
	int temp, j;

	for (int i = 1; i < size; i++)
	{
		temp = tab[i];//element przesuwany
		for (j = i - 1; j >= 0 && tab[j] > temp; j--)
			tab[j + 1] = tab[j];
		tab[j + 1] = temp;
	}
}

//Funkcja zwraca flagę, czy łańcch jest palindromem
bool Palindrome(const std::string & word)
{
	unsigned length = word.length();
	std::string napis_forward = word; //słowo czytane od lewej do prawej
	std::string napis_backwards; //słowo czytane od prawej do lewej
	//skracamy ilość iteracji poprzez wykorzystnie zasady,
	//że wystarczy sprawdzić połowę słowa...
	int polowa = length / 2;

	for (int i = length - 1; i >= 0; i--)
		napis_backwards = napis_backwards + napis_forward[i];
	return (napis_backwards == napis_forward);
}

//Funkcja zwraca flagę, czy łańcuch jest palindromem
bool Palindrom(const std::string & napis)
{
	int napis_length = napis.length(); //długość napiasu
	//ustawiam liczniki "i" i "j" na pierwszy i ostatni znak wyrazu tab

	int i = 0;
	int j = napis_length - 1; //pamiętajmy, że indeksujemy tablicę od 0

	while (i < j) //pętla wykonuje się do momentu spotkania liczników
	{
		if (napis[i] != napis[j]) //gdy znaki nie będą się zgadzać, to wyraz nie jest palindromem
			return false;
		++i; //przejscie do następnej litery idąc w prawą stronę
		--j; //przejscie do poprzedniej litry idąc w lewą stronę
	}
	return true; //wyraz jest palindromem
}

//Funkcja zwraca sumę cyfr liczy całkowitej
int SumDigit(int value)
{
	int suma_cyfr = 0;//zakładamy, że suma równa się zero

	while (value != 0)
	{
		suma_cyfr += value % 10; //akumulujemy sumę cyfr
		value /= 10; //dzielimy liczbę przez 10 (system dziesiętny)
	}
	return suma_cyfr;
}

//Funkcja zwraca największy wspólny dzielnik dwóch liczb
int NWD(int a, int b)
{
	// wybieramy większą z dwóch liczb
	// i zamieniamy ją na różnicę większej i mniejszej,
	// powtarzając tę czynność do momentu uzyskania dwóch takich samych wartości.
	while (a != b)//powtarzamy dopóki a jest różne od b
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a; // a lub b - obie zmienne przechowują wynik

	//Przykład:
	//1989 – 867 = 1122
	//1122 – 867 = 255
	//867 – 255 = 612
	//612 – 255 = 357
	//357 – 255 = 102
	//255 - 102 = 153
	//153 - 102 = 51
	//102 -51 =51
}

//Funkcja zwraca największy wspólny dzielnik dwóch liczb - wersją zoptymalizowana
int NWDZOptimized(int a, int b)
{
	int pom;
	while (b != 0)
	{
		pom = b;
		b = a % b;
		a = pom;
	}
	return a;
}

//Funkcja sprawdza, czy liczba jest liczbą pierwszą
bool PrimeNumber(int candidate)
{
	//Aby określić, czy dana liczba jest pierwsza
	//należy zbadać jej dzielniki.
	//Dla zadanej liczby n sprawdzamy kolejne liczby naturalne należące do przedziału:
	//[2...pier(n)] (od 2 do pierwistka kwadratowego z n) - tak wynika z analizy
	//matematycznej (sito Erastotenesa)...
	
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

	for (int i = 2; i*i <= candidate; i++)
		//dzielimy (modulo) liczbę (candidate) przez i...
		if (candidate % i == 0)	//jeśli został wyliczony jakiś dzielnik
			return false; //to dana liczba nie jest pierwsza
	return true;
}

//Funkcja sprawdza, czy liczba jest liczbą pierwszą - inne wersja
bool Pierwsza(int candidate)
{
	if (candidate < 2)
		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

	for (int p = 2; p < candidate; p++)
		if (candidate % p == 0)//jeśli został wyliczony jakiś dzielnik - liczba nie jest pierwsza
			return false;
	return true;
}

//Funkcja generuje liczby pierwsze z podanego zakresu: zbioru (tablicy)
void sitoEratostenesa(bool tab[], unsigned int n)
{
	//szukamy kolejnych kandydatów na liczby pierwsze
	//wystarczy sprawdzić do pierwiastka z n
	// i <= sqrt(n) - podnosząc do kwadratu mamy
	// zatem nasza nierówność ma postać: i * i <= n
	for (int i = 2; i*i <= n; i++)
	{              
		//sprawdzamy czy liczba jest pierwsza (ma wartosc 0/false/) - dlatego negacja
		if (!tab[i])
			for (int j = i*i; j <= n; j += i) //to wykreślamy jej wielokrotnosci
				tab[j] = true; //ustawiając wartosć na 1
	}

	cout << "Kolejne liczby pierwsze z przedziału [2.." << n << "]: ";

	for (int i = 2; i <= n; i++)
		if (!tab[i])
			cout << i << " ";
}

//Funkcja zwraca wynik porównania dwóch łańcuchów
EComparisons Compare(const std::string & a, const std::string & b)
{
	//wyliczamy długości napisów
	unsigned a_length = a.length();	//długość a
	unsigned b_length = b.length(); //długość b

	if (a_length < b_length) return EComparisons::A_MNIEJSZA_B;
	else if (a_length > b_length) return EComparisons::A_WIEKSZA_B;

	//gdy długości są równe, porównujemy element po elemencie
	else
	{
		for (unsigned i = 0; i < a.length(); i++)//bez znaczenia czy a, czy b (taka sama długość)
		{
			if (a[i] < b[i]) return EComparisons::A_MNIEJSZA_B;		//a < b
			else if (a[i] > b[i]) return EComparisons::A_WIEKSZA_B;	//a > b
		}
	}
	//gdy napisy mają taką samą długość i takie same elementy...
	return EComparisons::A_ROWNA_B;
}

//Funckja zwraca pozycję, od której wzorzec znajduje się w tekście lub -1, gdy nie ma wzorca
int bruteforce(const std::string & text, const std::string & pattern)
{
	int position = 0; //indeks określający początek wzorca
	int dl_t = text.length(); //długość tekstu
	int dl_w = pattern.length(); //długość wzorca
	bool ok = false; //flaga określająca, czy znaleziono
	int result = 0; //wartość, którą zwraca funkcja
	//-1 gdy nie ma wzorca,
	//wartość reprezentująca początek wzorca w tekście

	for (int i = 0; i <= dl_t - dl_w; i++)
	{
		//jeśli napotkamy pierwszą literę z wzorca w tekscie
		if (text[i] == pattern[0])
		{
			ok = true; //ustawiamy flagę na true
			position = 1; //zapamiętujemy pozycję
			//szukamy, czy zgadzają się pozostałe znaki
			for (int j = i + 1; j < dl_w; j++)
				if (text[j] != pattern[++position]) //jeśli się nie zgadza
				{
					ok = false; //ustawiamy flagę na fałsz...
					break; //przerywamy pętlę...
				}
			//jeśli wszystkie litery się zgadzają...
			if (ok)
			{
				result = i + 1;
				//cout << "Wzorzec znaleziono. Poczatek na " << i + 1 << " pozycji" << std::endl;
				//cout << text << endl;

				//cout.fill(' ');
				//cout.width(i + dl_w);
				//cout << pattern << endl;
				break;
			}
		}
	}
	//if (!ok)
	//	cout << "Wzorca nie znaleziono!" << std::endl;

	if (!ok)
		return -1;
	else
		return result;
}

//Funkcję odwraca kolejność elementów tablicy - iteracyjnie
void odwrocIteration(int *tab, int left, int right)
{
	while (left < right)
	{
		swap(tab[left], tab[right]); //zamiana elementów skrajnych
		left++; //przesuwamy się do środka od lewej strony
		right--; //przesuwamy się do środka od prawej strony
	}
}

//Funkcję odwraca kolejność elementów tablicy - rekuracyjnie
void odwrocRecursion(int *tab, int left, int right)
{
	if (left < right)
	{
		Swap(tab[left], tab[right]);//zamiana elementów skrajnych
		odwrocRecursion(tab, left + 1, right - 1);//odwracany resztę
	}
}

//Funkcja rekurencyjna przeszukujaca tablicę celem znalezienia szukanej wartości
void szukajRekurencyjnie(int tab[], int left, int right, int x)
{
	if (left > right)
		std::cout << "Element " << x << " nie został znaleziony\n";
	else
		if (tab[left] == x)
			std::cout << "Element szukany " << x << " został znaleziony\n";
		else
			szukajRekurencyjnie(tab, left + 1, right, x);
}

//Funkcja rejurencyjna oblicząjąca silnię
unsigned long int silnia(int x)
{
	if (x == 0)
		return 1;
	else
		return x * silnia(x - 1);
}

//Funkcja iteracyjna oblicząjąca kolejny element ciągu Fibonacciego
unsigned long int FibonacciIteration(int x)
{
	int a, b, temp;
	if (x == 0) return 0;
	
		a = 0; b = 1;

		for (int i = 0; i < (x - 1); i++)
		{
			//Swap(a, b);
			temp = a;
			a = b;
			b = temp;
			b += a;
		}
		return b;
}

//Funkcja rejurencyjna oblicząjąca kolejny element ciągu Fibonacciego
unsigned long int FibonacciRecursion(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	return FibonacciRecursion(x - 1) + FibonacciRecursion(x - 2);
}

//Funkcja rejurencyjna MacCarthy'ego
unsigned long int MacCarthy(int x)
{
	if (x > 100)
		return (x - 10);
	else
	{
		//std::cout << "wywolanie" << std::endl;
		return MacCarthy(MacCarthy(x + 11));
	}
}

//Funkcja niebezpieczna
int Danger(int n, int p)
{
	if (n == 0)
		return 1;
	else
		return Danger(n - 1, Danger(n - p, p));
}

//Funkcja sprawdza, czy w tablicy znajduje się szukana wartość
bool BinarySearchRecursion(int *tab, int x, int left, int right)
{
	if (left > right)
		return false;//nie znaleziono...
	else
	{
		int mid = (left + right) / 2;//wyznaczamy "środek" zbioru...
		if (tab[mid] == x)
			return mid;//znaleziono
		else
			if (x < tab[mid])
				return BinarySearchRecursion(tab, x, left, mid - 1);
			else
				return BinarySearchRecursion(tab, x, mid + 1, right);
	}
}

//Funkcja Ackermanna
int Ackermann(int n, int p)
{
	if (n == 0)
		return 1;
	if ((p == 0) && (n >= 1))
		if (n == 1)
			return 2;
		else
			return n + 2;
	if ((p >= 1) && (n >= 1))
		return Ackermann(Ackermann(n - 1, p), p - 1);
}

//Funkcja oblicza wartość wielomianu - schemat Hornera
int Horner_Iteration(int wsp[], int st, int x)
{
	int wynik = wsp[0];//dlaczego tutaj musimy zainicjować wartość?

	for (int i = 1; i <= st; i++)
	{
		wynik = wynik * x + wsp[i];
		//std::cout << "x ";//tutaj dowód, ile razy mnożymy (Hofner ma rację)
	}

	return wynik;
}

//Funkcja oblicza wartość wielomianu - schemat Hornera - rekurencyjnie
int Horner_Recursion(int wsp[], int st, int x)
{
	if (st == 0)
		return wsp[0];

	return x * Horner_Recursion(wsp, st - 1, x) + wsp[st];
}

//Funkcja zwraca element najczęściej występujący w tablicy (zbiorze) - dominant
int dominant(int tab[], int size)
{
	//zmienne
	int dominant; //dominant - element najczęściej występujący w tablicy
	int dominant_counter = 0; //licznik jego wystąpień (wyzerowany)

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0; //zerujemy lokalny licznik
		//iterujemy po elementach tablicy od początku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i]) //jeśli został znaleziony element
				local_counter++; //zwiększamy licznik wystąpień

		//sprawdzamy, czy licznik lokalny jest większy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter; //ten staje się globalnym
			dominant = tab[i]; //wyznaczamy dominant
		}
	}
	return dominant;
}

//Funkcja zwraca wskaźnik, pod którym znajduje się dominant
int *Dominant(int tab[], int size)
{
	//zmienne
	int dominant; //dominant - element najczęściej występujący w tablicy
	int dominant_counter = 0; //licznik jego wystąpień (wyzerowany)
	int tabPom[2]; //tablica pomocnicza
	//pod indeksem 0 - dominant
	//pod indeksem 1 - licznik wystąpień dominanta
	int *result; //zwracany wskaźnik z opakowaniem informacji

	//Wyszukujemy dominanta
	for (int i = 0; i < size; i++)
	{
		int local_counter = 0; //zerujemy lokalny licznik
		
		//iterujemy po elementach tablicy od początku
		for (int j = 0; j < size; j++)
			if (tab[j] == tab[i]) //jeśli został znaleziony element
				local_counter++; //zwiększamy licznik wystąpień

		//sprawdzamy, czy licznik lokalny jest większy od globalnego
		if (local_counter > dominant_counter)
		{
			dominant_counter = local_counter; //ten staje się globalnym
			dominant = tab[i]; //wyznaczamy dominant
		}

		//przepisujemy dane do tablicy pomocniczej
		tabPom[0] = dominant;
		tabPom[1] = dominant_counter;

		//Pamiętamy, że nazwa tablicy jest adresem jej początku...
		//ustawiamy wskaźnik na tablicę (czyli zwracamy jej adres)
		//spod którego (odwołując się indeksami), możemy odczytać
		//dane (dominanta oraz ilość jego wystąpienia w tablicy (zbiorze)
		result = tabPom;
	}
	return result;

	//usage (użycie, np. w funkcji main()
	//int *myWynik = new int[2];
	//myWynik = Dominant(Tabliczka, 5);
	//int wynik_dominant = myWynik[0];
	//int wynik_counter = myWynik[1];
	//int wartownik = 0;
}

//Rekurencyjna funkcja sortowania - quicksort
//http://miroslawzelent.pl/wyklady/sortowanie-szybkie-quicksort-dziel-zwyciezaj.pdf
void quicksort(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tablica[i]<v)
			i++;
		while (tablica[j]>v)
			j--;
		
		if(i <= j) 
		{
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++; j--;
		}
	} while	(i <= j);

	if (j>lewy) quicksort(tablica, lewy, j);
	if (i<prawy) quicksort(tablica, i, prawy);
}

//Rekurencyjna funkcja sortowania - QuickSort
void QuickSort(int *tab, int lewy, int prawy)
{
	int i, j, piwot;

	i = (lewy + prawy) / 2;

	piwot = tab[i];
	tab[i] = tab[prawy];

	for (j = i = lewy; i < prawy; i++)
		if (tab[i] < piwot)
		{
			Swap(tab[i], tab[j]);
			j++;
		}
	tab[prawy] = tab[j];
	tab[j] = piwot;
	if (lewy < j - 1)  QuickSort(tab, lewy, j - 1);
	if (j + 1 < prawy) QuickSort(tab, j + 1, prawy);
}

//Rekurencyjna funkcja sortowania - QuickSortAlpha
void QuickSortAlpha(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];//v - piwot
	//*pivot (ang. sworzeń, oś, dźwignia, sedno) u nas - element podziału...
	int p = lewy;
	int q = prawy;
	do
	{
		while (tablica[p]<v) p++; //wyszukujemy od Lewej strony tablicy element wiekszy od pivot'a               
		while (tablica[q]>v) q--; //wyszukujemy od prawej strony tablicy element mniejszy od pivot'a
		if (p <= q)
		{
			Swap(tablica[p], tablica[q]);
			//zamieniamy elementy tak aby większy od pivot'a przesunąć
			//na prawą stronę, a mniejszy od pivot'a przesunąć na lewą
			p++;
			q--;
		}
	} while (p <= q);

	if (q>lewy) QuickSortAlpha(tablica, lewy, q);
	if (p<prawy) QuickSortAlpha(tablica, p, prawy);
}

//Rekurencyjna funkcja sortowania - Qsort
void Qsort(int *tab, int left, int right)
{
	if (left < right)
	{
		int m = left;
		for (int i = left + 1; i <= right; i++)
			if (tab[i]<tab[left])
				Swap(tab[++m],tab[i]); //zamiana miejscami 
		
		Swap(tab[left], tab[m]);
		Qsort(tab, left, m - 1);
		Qsort(tab, m + 1, right);
	}
}

//Funkcja zwraca medianę zbioru
int Mediana(int *tab, int left, int right)
{
	//Mediana to element zbioru, od którego w tym zbiorze
	//jest tyle samo elementów większych
	//lub równych co mniejszych lub równych.

	//Analiza:
	//Sortujemy zbiór rosnąco.
	//Mediana to element na pozycji n/2 (dla n nieparzystego – mediana, dla n parzystego – mediana dolna).

	//
	//Pamiętamy, że nazwa tablicy jest adresem jej początku
	//Dlatego też, kosztem pamięci, w tej funkcji celowo utworzę
	//kopię tej tablicy, do której przepiszę jej elementy, aby po zakończeniu
	//funkcji, czyli wyliczeniu mediany, tablica wejściowa była nienaruszona.
	//
	//Pamiętaj, że takie rozwiązanie ma tę wadę, że funkcja na stosie musi
	//zarezerować tyle pamieci, aby pomieścić kopię tablicy...
	//
	//Kopiujemy elementy tablicy oryginalnej (parametr funkcji)
	//do tablicy pomocniczej używanej wewnątrz tej funkcji
	//
	int *temp_tab = tab;
	for (int i = left; i < right; i++)
		temp_tab[i] = tab[i];

	int mediana;

	//S o r t u j e m y  tablicę (zbiór)
	//Poniższy kod to sortowanie metodą bąbelkową. 
	//Można by było wykorzystać wywołanie jednej z gotowych funkcji sortujących,
	//których imoplementacje są w tej lokalizacji, ale umieszczenie
	//kodu sortowania wewnątrz tej funckji, uniezależnia jej działanie
	//i wykorzystanie poza tą lokalizacją.

	int temp;

	for (int i = left; i < right; i++)
		for (int j = left; j < right - i - 1; j++) //pętla wewnętrzna
			if (temp_tab[j] > temp_tab[j + 1])
			{
				//zamiana miejscami jeśli warunek jest spełniony
				temp = temp_tab[j];
				temp_tab[j] = temp_tab[j + 1];
				temp_tab[j + 1] = temp;
			}

	mediana = temp_tab[(right - left)/2];
	return mediana;
}

//Funkcja zwraca łańcuch znaków reprezentujący sumę liczba
std::string BigSum(std::string & number_1, std::string & number_2)
{
	//Przykład został omówiony na stronie: http://eduinf.waw.pl
	
	//Rejestr pamieci, w której maszyna przechwuje zmienne, w naszym
	//przypadku liczby, ma swoją pojemność. Na komputerze 32-bitowym
	//mamy tylko tyle pamięci, aby przechować w nim liczbę w postaci
	//binarnej.
	//
	//Rodzi się problem, jak zatem wykonywać obliczenia bazujące na bardzo
	//dużych liczbach, przez co rozumiemy np. liczbę 3 do potęgi 1000?
	//
	//Rozwiązanie poniżej przedstawione jest najprostszym z możliwych
	//rozwiązań, opierajace się na spodobie dodawania, któy poznaliśmy
	//w szkole podstawowej.
	//Jest to zresztą chyba jedyby sposób wykonywania operacji arytmetycznych
	//bez posługiwania się maszynami jakimi są kalkulatory, przez co rozumiemy
	//wszystkie maszyny wymyślone przez człowieka ułatwiające zarzadzanie
	//liczbami reprezentującycmi wielkości otaczającego nas świata.
		
	//Przykład:
	//                                       1	//przeniesienie
	//number_                 23432900765432345
	//number_2      + 4309561205471717171934675
	//                -------------------------
	//                                        0
	
	//
	//Uwagi, założenia, wnioski
	// - zakładamy, że łańcuch znaków składa się tylko z cyfr,
	// - przykład dotyczy dodawania liczb całkowitych dodatnich
	//   jakkolwiek można tak dostosować algorytm, aby dziedzinę
	//   liczb powiekszyć,
	// - dodawanie jest przemienne, co należy uwzględnić w algorytmie
	//   ponieważ wielkości (rzędy wielkości) składników sumy mogą być
	//   różne
	// - opracje bazujące na łańcuchach są wprost ptporcjonalne do ich
	//   długości, dlatego też wykonanie tej funkcji jest dość kosztowne
	//
	//Założnie:
	//
	//Posługujemy się rozwiązaniem, które jest standardem (tablica kodów ASCII)
	//
	//  Cyfra 	Kod ASCII
	//	0 		48
	//	1 		49
	//	2 		50
	//	3		51
	//	4		52
	//	5		53
	//	6		54
	//	7		55
	//	8		56
	//	9		57
	
	//postępujemy według nastęujacego algorytmu:
	
	std::string s1; //pierwszy składnik sumy
	std::string s2; //drugi składnik sumy
	std::string suma; //suma

	int przeniesienie; //przeniesienie
	int w; //zmienna przechowuje wynik dodawania w "słupku"
	int length_number_1; //długość łańcucha pierwszej liczby
	int length_number_2; //długość łańcucha drugiej liczby
	int n; //w tej zmiennej będzie przechowywany krótszy łańcuch

	//odczytujemy liczby do dodawania z parametrów funkcji
	s1 = number_1;
	s2 = number_2;

	//obliczamy długości każdego z łańcuchów
	length_number_1 = s1.length();
	length_number_2 = s2.length();

	//wyznaczamy długość krótszego łańcucha
	n = length_number_1;
	if (length_number_2 < length_number_1)
		n = length_number_2;

	przeniesienie = 0; //zerujemy przeniesienie
	suma = ""; //zerujemy łańcuch wynikowy

	//sumujemy kolejne od końca cyfry obu łańcuchów
	for (int k = 1; k <= n; k++)
	{
		w = (int)(s1[--length_number_1]) + (int)(s2[--length_number_2]) + przeniesienie - 96;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;//konkatenacja
	}

	//jeśli łańcuch s1 ma jeszcze cyfry, to dodajemy do nich przeniesienia i umieszczamy w łańcuchu wynikowym
	while (length_number_1)
	{
		w = s1[--length_number_1] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	// jeśli łańcuch s2 ma jeszcze cyfry, to dodajemy do nich
	//przeniesienia i umieszczamy w łańcuchu wynikowym
	while (length_number_2)
	{
		w = s2[--length_number_2] + przeniesienie - 48;
		przeniesienie = w / 10;
		suma = (char)((w % 10) + 48) + suma;
	}

	//jeśli pozostało przeniesienie, to dołączamy je do cyfr w łańcuchu wynikowym
	if (przeniesienie)
		suma = (char)(przeniesienie + 48) + suma;

	//jeśli w suma nie ma cyfr, to wpisujemy tam 0
	if (suma == "")
		suma = "0";

	//wyświetlamy wynik
	std::cout << suma << std::endl;

	return suma;
}

//Funkcja - wydawanie reszty
void WydawanieReszty(int reszta)
{
	int liczba_monet;
	int i, nominal[] = { 20000,10000,5000,2000,1000,500,200,100,50,20,10,5,2,1 };

	i = 0;
	while (reszta > 0)
	{
		if (reszta >= nominal[i])
		{
			liczba_monet = reszta / nominal[i];
			reszta = reszta - (nominal[i] * liczba_monet);
			cout << liczba_monet << " x " << nominal[i] << " gr." << endl;
		}
		i++;
	}
}

//Funkcja zwraca jednocześnie minimum i maximum tablicy
void MiniMax(int Tab[], int size)
{
	//P r e a m b u ł a:
	//
	//Nasze postępowanie opiera się na napisaniu takiego kodu,
	//który jest wydajny.
	//Analiza prędkości jego działania do ilości zużytej pamięci
	//oraz użycia czasu procesora - zawsze jest najtrudniejsze
	//
	//Zakładamy, że zbiór danych (tablica),
	//którą wcześniej doprowadzimy do stanu aby miała parzystą
	//ilość elementów - będzimy brali po dwa elementy (pary)
	//nie muszę dodawać, że to elementy następujące po sobie
	//(tablica to ciąły obszar pamieci).
	//Następnie wyznaczamy wstępnie - inicjujemy zmienne
	//wartość max i min - początkową wartość maksymalną i minimalną.
	//
	//W każdym kroku iteracji jednocześnie pilnujemy wyznaczania
	//wartości min i max
	//
	//Założenie wstępne - logiczne:
	// - tablica powinna mieć przynajmniej jeden element
	//   co wynika z logiki (jeśli poddajemy zbiór analizie
	//   to taki zbiór nie powienien być pusty
	//Dodanie dodatkowego (zapasowego) elementu do tablicy (na końcu)
	//to:
	//		-	koszt - dodatkowa pamieć (kwestia zawsze problematyczna)
	//		-	zysk - dopełnienie ilości elementów tablicy, aby była
	//			ona parzysta, nie wpływa na ilość iteracji ponieważ
	//			w każdym jej kroku analizujemy parę jej elementów
	//
	//Test:
	//Sprawdź jaką wartość będzie miała zmienna iteration_counter
	//zwiększając liczbę elementów tablicy - spróbuj to wyrazić wzorem

	int iteration_counter = 0;//diagnostyka

	if (size % 2)//jeśli tablica ma nieparzystą ilość elementów
		Tab[size] = Tab[size - 1];//dublujemy ostatni element

	//bierzemy dwa pierwsze elementy i wyznaczamy wstępnie min i max
	int min;//kandydat na maksimum
	int max;//kandydat na minimum

	if (Tab[0] > Tab[1])
	{
		min = Tab[1];
		max = Tab[0];
	}
	else
	{
		min = Tab[0];
		max = Tab[1];
	}

	//Skracamy iterację, bo rozpoczynamy od i = 2
	//(zauważ, że w przypadku tablicy, która ma mniej niż 3 elementy
	//pętla for w ogóle się nie wykona.
	//Dodatkowo zarządzamy licznikiem pętli co dwa elementy i +=2
	//zatem zmniejszamy ilością wywołań iteracyjnych.
	//Pamiętaj:
	//Iteracja to przede wszystkim czas,
	//a ten jest bezcenny. I na tym zazwyczaj "wykładają"
	//się  a l g o r y t m y.

	for (int i = 2; i < size; i += 2)
	{
		if (Tab[i] > Tab[i + 1])
		{
			if (Tab[i] > max) max = Tab[i];
			if (Tab[i + 1] < min) min = Tab[i + 1];
		}
		else
		{
			if (Tab[i] < min) min = Tab[i];
			if (Tab[i + 1] > max) max = Tab[i + 1];
		}
		iteration_counter++;
	}

	std::cout << "Rozmiar tablicy :  " << size << std::endl;
	std::cout << "Minimum         :  " << min << std::endl;
	std::cout << "Maksimum        :  " << max << std::endl;
	std::cout << "Iteracja        :  " << iteration_counter << std::endl;
}

//Szyfrowanie
std::string Szyfrowanie(std::string slowo, int klucz)
{
	//obliczamy długości słowa do iteracji (ilość liter w słowie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotności klucza w alfabecie ponieważ klucze to spore liczby
	//a my możemy w oparciu o założenia zadania poruszać się tylko
	//w obrębie alfabetu łacińskiego pośród wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//ilość dużych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi być dodatni
		for (int i = 0; i < dlugosc_slowa; i++)
			//sprawdzenie czy klucz wychodzi poza zakres
			if (slowo[i] + klucz <= 'Z')
				slowo[i] = slowo[i] + klucz;
			else
				slowo[i] = slowo[i] + klucz - IL_LITER;
	return slowo;
}

//Deszyfrowanie
std::string Deszyfrowanie(std::string slowo, int klucz)
{
	//obliczamy długości słowa do iteracji (ilość liter w słowie)
	int dlugosc_slowa = slowo.length();

	//wyliczenie krotności klucza w alfabecie ponieważ klucze to spore liczby
	//a my możemy w oparciu o założenia zadania poruszać się tylko
	//w obrębie alfabetu łacińskiego pośród wielkich liter: od 'A' do 'Z',
	//a tych jest 26;
	const unsigned int IL_LITER = 26;//ilość dużych liter: od 'A' do 'Z'
	klucz = klucz % IL_LITER;

	if (klucz >= 0)//klucz musi być dodatni
		for (int i = 0; i < dlugosc_slowa; i++)
			//sprawdzenie czy klucz wychodzi poza zakres
			if (slowo[i] - klucz >= 'A')
				slowo[i] = slowo[i] - klucz;
			else
				slowo[i] = slowo[i] - klucz + IL_LITER;
	return slowo;
}

//Funkcja sprawdza, czy dwa napisy (w jednej linii jawny i tajny, są zakodowane
//takim samym kluczem (znak po znaku - ten sam klucz)
bool TestujSzyfr(std::string slowo, std::string szyfr)
{
	int klucz;
	//obliczamy długości słowa do iteracji (ilość liter w słowie)
	//zakładając, że słowo jawne i zaszyforwane mają taką samą długość
	int dlugosc_slowa = slowo.length();
	int roznica;//różnica - zmienna sprawdza, czy różnica dwóch kluczy się zeruje

				//ustalamy klucz dla szyfru na podstawie pierwszsego znaku
	klucz = slowo[0] - szyfr[0];
	const unsigned int IL_LITER = 26;//ilość dużych liter: od 'A' do 'Z'
	if (klucz < 0) klucz = klucz + IL_LITER;

	//znaliza znak po znaku...
	for (int i = 0; i < dlugosc_slowa; i++)
	{
		//obliczamy różnicę klucza dla znaku ze słowa i z szyfru
		roznica = slowo[i] - szyfr[i];

		//sprawdzamy, czy kolejne znaki mają ten sam klucz
		if (roznica < 0) roznica = roznica + IL_LITER;

		//jest różnica - znaki słowa nie są zakodowane takim samym kluczem
		if (roznica != klucz)
		{
			return false;
			break;//przerywamy - nie na sensu dalej sprawdzać...
		}
	}
	return true;//napis jawny oraz tajny mają takim sam klucz - są poprawnie zakodowane
}

//Funkcja sprawdza, czy indeks tablicy dwuwymiarowej jest poprawny
bool correct_index(int i, int j, int size_i, int size_j)
{
	//sprawdzając, czy wskazany indeks znajduje się w tablicy
	//należy uwzględnić uwzględnić rozmiar tablicy
	return (i >= 0 && i < size_i && j >= 0 && j < size_j);
}

//Rekurencja - alpha
void test(int n)
{
	std::cout << n << '\n';

	if (n > 0)
		test(n - 1);

	std::cout << n << '\n';
}

//Rekurencja - beta
void Odliczanie(int i)
{
	std::cout << "Rakieta startuje za "	<< i << " sek.\n";
	if (i > 0)
		Odliczanie(i - 1);
	//std::cout << i << ". Start zgodny z planem\n";
}

//Rekurencja - gamma
long long suma(int n)
{
	if (n<1)
		return 0;

	return n + suma(n - 1);
}

//Rekurencja - delta
void zamien(int n)
{
	//jesli n == 0 to zawracamy
	if (n == 0)return;
	zamien(n / 2); //zagnieżdżamy rekurencję
	std::cout << n % 2; //przy powrocie 
}

bool czy_anagram_One(char *a, char *b)
{
	//wyznaczenie liczby liter w slowie a i w slowie b
	int dl1 = strlen(a), dl2 = strlen(b);
	//jesli dlugosci wyrazów nie sa równe, to nie moga
	//byc anagramy
	if (dl1 != dl2)return false;

	int licz[127] = {}; //zerujemy liczniki

	for (int i = 0; i<dl1; i++)
		licz[a[i]]++; //zliczamy litery pierwszego wyrazu

	for (int i = 0; i<dl1; i++)
		licz[b[i]]--; //odejmowanie wystapien liter

	for (int i = 0; i<127; i++)
		if (licz[i] != 0) //jesli ktorys licznik sie nie wyzerowal
			return false; //to oznacza, ze słowa nie sa anagramami

	return true; //jesli wszystkie liczniki sie wyzerowały, to mamy anagramy
}

//....
void sortuj(string &napis)
{

	for (int i = 0, zamiany = 1; i<napis.length() - 1 && zamiany != 0; i++)
	{
		zamiany = 0;
		for (int j = 0; j<napis.length() - 1; j++)
			if (napis[j]>napis[j + 1])
			{
				swap(napis[j], napis[j + 1]);
				zamiany++;
			}
	}

}

bool czy_anagramy_Two(string napis1, string napis2)
{
	if (napis1.length() != napis2.length()) return false;

	sortuj(napis1);
	sortuj(napis2);

	if (napis1 == napis2) return true;
	else
		return false;

}
