#### ![sci_logo](https://github.com/jackflower/SCICode/blob/master/graphics/sci_logo.png) Technikum Informatyczne SCI - zestaw testowy



### Celem tego sprawdzianu jest ocena umiejętności posługiwania się narzędziem XAMP, a w szczególności:

1. Administrowanie systemem **phpMyAdmin**
2. Zarządzanie systemem bazy danych _**mySQL**_
   1. Tworzenie obiektów bazy danych takich jak:
      - bazy danych
      - tabele
      - zapytania (widoki, kwerendy)
      - proste zapytania w języku SQL
      - Praca na danych typu data


### Przygotowanie środowiska i jego konfiguracja

Posługując się narzędziem XAMP utwórz na koncie _**localhost**_ bazę danych i nadaj jej nazwę według poniższej specyfikacji:

Nazwa bazy danych to konkatenacja: **sci_basic_numer_w_dzienniku**, gdzie numer w dzienniku to Twój numer w dzienniku Przykładowa, poprawna nazwa dla bazy danych to **sci_basic_04** (dla osoby z numerem w dzienniku 4). Pamiętaj, aby dla bazy danych poprawnie określić kodowanie na (_**utf8_polish_ci**_).

### Przygotowanie obiektów bazy danych (tabela)

W bazie utwórz tabelę o nazwie _**person**_, której struktura została przedstawiona na poniższym zrzucie ekranowym.



![sci_logo](https://github.com/jackflower/SCICode/blob/master/graphics/person_graphics.png)




Zaimportuj do tej tabeli dane znajdujące się w pliku _**person_test.txt**_. Prawidłowy import danych powinien dodać do tabeli _**3121**_ rekordów. 



###### Wykonaj poniższe polecenia:



##### Zadanie 1

Utwórz zapytanie, które zwróci wszystkie osoby z tabeli _**person**_ o imieniu "Waldemar". Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_1**.

##### Zadanie 2

Utwórz zapytanie, które zwróci wszystkie osoby z tabeli _**person**_ o imieniu "_**Anna**_" oraz "_**Marek**_", posortowane malejąco według imienia osoby. Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_2**.

##### Zadanie 3

Utwórz zapytanie, w którym umieścisz pola: imię osoby oraz imię jej matki, które zwróci wszystkie osoby z tabeli _**person**_ o imieniu "_**Magdalena**_", których matka ma na imię "_**Krystyna**_". Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_3**.

##### Zadanie 4

Utwórz zapytanie, które zwróci wszystkie osoby z tabeli _**person**_ o imieniu "_**Tomasz**_", których ojciec <u>nie ma</u> na imię "_**Henryk**_", a matka ma na imię "_**Barbara**_". Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_4**.

##### Zadanie 5

Utwórz zapytanie, które zwróci wszystkie osoby z tabeli _**person**_  urodzone po 1 lipca 1974 roku. Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_5**.

##### Zadanie 6

Utwórz zapytanie, które zwróci z tabeli _**person**_ tylko te osoby, które urodziły się w _**styczniu**_. Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_6**.

##### Zadanie 7

Utwórz zapytanie, które zwróci z tabeli _**person**_ imiona tych osoby, które urodziły się w _**lipcu**_, w latach od 1981 do 1997 roku. Wynik tego zapytania umieść w bazie w widoku pod nazwą **osoby_zadanie_7**.

##### Podsumowanie

Do oceny oddajesz _**skrypt - eksport bazy danych w formacie SQL**_, pod nazwą Twojej bazy danych. Plik (skrypt) zostanie skopiowany przez nauczyciela po zgłoszeniu gotowości przez ucznia.
