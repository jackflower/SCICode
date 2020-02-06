# Zestaw 4
#
# W pliku "dane.txt" zapisano w osobnych liniach nazwy dni tygodnia.
# Nazwy dni tygodnia zapisano w języku angielskim.
# Każdy dzień tygodnia zaczyna się z wielkiej litery.
# Napisz program, który z pliku "dane.txt"
# wczyta wszystkie dane w nim zawarte i zapisze do pliku
# "wynik.txt" tylko te dni tygodnia, których nazwa to : Tuesday.
#
# Dla pliku dane.txt z zawartością zgodną z tym w tym repozytorium
# prawidłowym wyniekiem jest plik zawierający 100 słów "Tuesday"


# obiekt plik_in - odwołuje się do pliku "dane.txt" - tryb "r" read (odczyt)
plik_in = open("dane.txt", "r").read()# odczyt zawartości obiektu plik_in
# dni tygodnia zapisane w osobnych liniach zatem - split - separator
# dni tygodnia - to znacznik końca linii "\n"
lines = plik_in.split("\n")

# zmienna plik_out - odwołuje się do pliku "wynik.txt" - tryb "r" write (zapis)
plik_out = open("wynik.txt", "w")

# iterujemy po pliku - czytamy go linia po linii
for week_day in lines:
    if(week_day == "Tuesday"):   # sprawdzamy warunej zadania
        plik_out.write(week_day) # zapisujemy do pliku "Tuesday"
        plik_out.write("\n")     # zapisujemy do pliku znak końca linii

plik_out.close() # musimy zamknąć obiekt aby dane zostały zapisane
