# Zestaw 5
#
# W pliku "dane.txt" zapisano w osobnych liniach liczby.
# Liczby reprezentują lata.
# Napisz program, który z pliku "dane.txt"
# wczyta wszystkie dane w nim zawarte i zapisze do pliku
# "wynik.txt" tylko te lata, które są większe od roku 2000.
#
# Dla pliku dane.txt z zawartością zgodną z tym w tym repozytorium
# prawidłowym wynikiem jest plik "wynik.txt" zawierający 232 daty spełniające warunek


# obiekt plik_in - odwołuje się do pliku "dane.txt" - tryb "r" read (odczyt)
plik_in = open("dane.txt", "r").read() # odczyt zawartości obiektu plik_in
# daty zapisane w osobnych liniach zatem - split - separator
# daty - to znacznik końca linii "\n"
lines = plik_in.split("\n")

# zmienna plik_out - odwołuje się do pliku "wynik.txt" - tryb "r" write (zapis)
plik_out = open("wynik.txt", "w")

# iterujemy po pliku - czytamy go linia po linii
for data in lines:
    # odczytana data nie może być pustą linią ponieważ
    # nie będzie jej można zamienić na liczbę całkowitą
    if(data):   
        # zamieniamy odczytaną wartość na liczbę by można ją było porównać
        data_liczba = int(data)
        if(data_liczba > 2000):# sprawdzamy warunek zadania
            plik_out.write(str(data_liczba)) # zapisujemy do pliku daty zamienione na string
            plik_out.write("\n") # zapisujemy do pliku znak końca linii

plik_out.close() # musimy zamknąć obiekt aby dane zostały zapisane
