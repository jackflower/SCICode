// Zestaw 4
//
// W pliku "dane.txt" zapisano w osobnych liniach nazwy dni tygodnia.
// Nazwy dni tygodnia zapisano w języku angielskim.
// Każdy dzień tygodnia zaczyna się z wielkiej litery.
// Napisz program, który z pliku "dane.txt"
// wczyta wszystkie dane w nim zawarte i zapisze do pliku
// "wynik.txt" tylko te dni tygodnia, których nazwa to : Tuesday.
//
// Dla pliku dane.txt z zawartością zgodną z tym w tym repozytorium
// prawidłowym wyniekiem jest plik zawierający 100 słów "Tuesday"

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream plik_in;//zmienna plikowa - plik do odczytu
	std::fstream plik_out;//zmienna plikowa - plik do zapisu
	plik_in.open("dane.txt", std::ios::in);//otwarcie pliku do odczytu
	plik_out.open("wynik.txt", std::ios::out);//otwarcie pliku do zapisu

	std::string napis;//do tej zmiennej zapisujemy dzień tygodnia z pliku

	while (!plik_in.eof())//dopóki nie osiągnięto końca pliku
	{
		plik_in >> napis;//pobieramy z nego dane (dni tygodnia)

		if (napis == "Tuesday")//sprawdzamy warunej zadania
			plik_out << napis << std::endl;//zapisujemy "Tuesday" do pliku
	}

	plik_in.close();//zamykamy plik
	plik_out.close();//zamykamy plik


	getchar();
	return 0;
}
