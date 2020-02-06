// Zestaw 5
//
// W pliku "dane.txt" zapisano w osobnych liniach liczby.
// Liczby reprezentują lata.
// Napisz program, który z pliku "dane.txt"
// wczyta wszystkie dane w nim zawarte i zapisze do pliku
// "wynik.txt" tylko te lata, które są większe od roku 2000.
//
// Dla pliku dane.txt z zawartością zgodną z tym w tym repozytorium
// prawidłowym wynikiem jest plik "wynik.txt" zawierający 232 daty spełniające warunek


#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream plik_in;//zmienna plikowa - plik do odczytu
	std::fstream plik_out;//zmienna plikowa - plik do zapisu
	plik_in.open("dane.txt", std::ios::in);//otwarcie pliku do odczytu
	plik_out.open("wynik.txt", std::ios::out);//otwarcie pliku do zapisu
											  
	//do tej zmiennej będziemy przypisywać datę (rok/liczbę) z pliku,
	//która musi być typu int, aby można było sprawdzać warunek
	//zdefiniowany w zadaniu ( "większe od roku 2000" )
	int data;

	while (!plik_in.eof())//dopóki nie osiągnięto końca pliku
	{
		//zerujemy zmienną aby wykluczyć czytanie z pliku pustych wierszy
		//plik "dane.txt" kończy się znakiem końca linii - pusta linia
		data = 0;

		plik_in >> data; // pobieramy z pliku dane - daty
		if (data > 2000) //sprawdzamy warunek zadania
			//zapisujemy daty do pliku w osobnych liniach
			plik_out << data << std::endl; 
	}

	plik_in.close();//zamykamy plik
	plik_out.close();//zamykamy plik

	getchar();
	return 0;
}
