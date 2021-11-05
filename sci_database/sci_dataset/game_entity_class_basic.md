## Podstawowe informacje o klasach w C++



### Klasy

​		O klasach, w odniesieniu do programowania obiektowego, napisano prawdopodobnie wszystko. Dokumentacja, książki, podręczniki, opracowania traktujące o programowaniu obiektowym, zawierają definicję klasy oraz ich przykłady. Różnice stanowi jedynie składnia języka programowania, który posiada typ definiowany jako typ klasowy.  Dopiero konieczność stosowania klas w sposób wymierny, jest praktycznym egzaminem jak rozumiemy to pojęcie.

​		Wyobraźmy sobie, że jako programista/projektant/architekt otrzymaliśmy zadanie przygotowania prototypu klasy reprezentującej jednostkę gry. Członkowie zespołu odpowiadający za warstwę graficzną, przygotowali szereg szkiców - grafikę koncepcyjną (ang. conceptart).



![sci_engine_021](..\graphics\sci_engine_021.png)





#### Dekompozycja funkcjonalna

​		Każdy z nas postrzega otaczającą nas rzeczywistość w sposób indywidualny. Poniższa analiza w ramach procesu **dekompozycji funkcjonalnej** jest tylko wizją, propozycją, jednym z wielu sposobów postrzegania i rozumowania świata. Produktem będzie kod źródłowy w języku C++ reprezentujący jednostkę gry.



![sci_engine_013](..\graphics\sci_engine_013.png)

> Dekompozycja funkcjonalna to metoda tworzenia modelu analitycznego polegająca na dekompozycji (rozłożeniu) funkcji systemu w taki sposób,  aby pojedyncze funkcje definiowały założone cele.



Bazując na założeniach projektowych oraz grafice prezentacyjnej (nasza wyobraźnia), możemy wyodrębnić atrybuty oraz funkcje, które klasa mogłaby realizować. Spróbujmy wymienić te najistotniejsze.

1. Obiekty taj klasy posiadają reprezentację graficzną
2. Obiekty tej klasy potrafią się przemieszczać
3. Obiekty tej klasy strzelają
4. Obiekty tej klasy aktualizują swój stan w czasie rzeczywistym

Na tym etapie dokonamy wstępnego podsumowania i zaproponujmy szkielet kodu źródłowego klasy. 

Będziemy potrzebowali dwóch plików: **Character.hpp** oraz **Character.cpp**. Nazwy plików wynikają z przyjętej zasady, według której nazwa klasy jest tożsama z nazwą pliku (plików). Przyjrzyjmy się, jak prawidłowo, zgodnie z założeniami projektu, zasadami pisania kodu, tworzenia dokumentacji, powinna wyglądać  zawartość tych plików. Prześledzimy proces ich tworzenia.

> Programowanie to pisanie kodu. Proces pisania kodu jest kluczowy. Bazując na materiałach, które możemy znaleźć w sieci Internet mamy możliwość kopiowania i wklejania kodu źródłowego. Unikaj tego. Pisz kod samodzielnie. Edytuj go, Poprawiaj.



#### Tworzymy kod

Plik ***Character.hpp***

```c++
class Character
{
};
```



Plik ***Character.cpp***

```c++
#include "Character.hpp"
```



W pliku nagłówkowym **Character.hpp** znajduje się definicja klasy o nazwie **Character**. Pomiędzy klamrami umieszczać będziemy ciało klasy. Zauważ, że po nawiasie klamrowym zamykającym ciało, znajduje się średnik. Pamiętaj, że język C++ to język, który jest wrażliwy na wielkość liter.

Plik **Character.cpp** będzie zawierać implementację klasy - kod realizujący jej funkcjonalność. W takiej postaci klasa na niewiele się przyda, ale jej kod jest poprawny.

Uzupełnimy teraz kod źródłowy definicji klasy **Character** w taki sposób, aby było to zgodne z założeniami projektowymi dotyczącymi stylu pisania kodu. Na początek dodamy dyrektywę ochrony pliku nagłówkowego przed wielokrotnym załączaniem do programu.

Plik ***Character.hpp***

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

class Character
{
};
#endif //HPP_CHARACTER
```



Nazwa _HPP_CHARACTER_ występująca po dyrektywie jest złączeniem informacji, że jest to plik nagłówkowy (_HPP_) i nazwa klasy (_CHARACTER_). Zgodnie z założeniami napisana jest dużymi literami. Umieszczono ją także jako komentarz na końcu dyrektywy, zwiększając czytelność kodu. Stosuj tę zasadę wobec całości kodu źródłowego, aby wypracować swój własny styl kodowania.



#### Modyfikatory

Dodamy do naszego kodu modyfikatory dostępu. Kolejność modyfikatorów jest zgodna z założeniami. Realizujemy założenia hermetyzacji (enkapsulacji) w odniesieniu do programowania obiektowego.

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

class Character
{

public:
protected:
private:

};
#endif //HPP_CHARACTER
```



#### Przestrzenie nazw

W naszym projekcie będziemy stosowali przestrzenie nazw (ang. namespace). Umieścimy klasę **Character** (jej kod źródłowy) w przestrzeni, której nadamy nazwę **logic**. Wszystkie nazwy, w odniesieniu do wszystkich elementów kodu źródłowego, zgodnie z założeniami powinny być proste, jednoznaczne. Poprzez samą nazwę informujemy o funkcjonalności, która jest realizowana. Przestrzenie nazw grupują kod źródłowy według umownych zasad, dzięki czemu łatwiej zarządzać kodem. Szczególnie w odniesieniu do dużych i bardzo dużych projektów.

Plik ***Character.hpp***

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

namespace logic
{
	class Character
	{

	public:
	protected:
	private:

	};
}//namespace logic
#endif //HPP_CHARACTER
```

Uwzględniamy tę przestrzeń także  w pliku implementacyjnym.

Plik ***Character.cpp***

```c++
#include "Character.hpp"
namespace logic
{

}//namespace logic
```



#### Konstruktor domyślny

Tworząc klasę zawsze umieszczaj w niej konstruktor. Gdybyś tego nie robił, kompilator automatycznie go utworzy. Stosuj zasadę, że to programista decyduje o kodzie źródłowym i jest **<u>odpowiedzialny</u>** za jego działanie.

Plik ***Character.hpp***

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

namespace logic
{
	class Character
	{

	public:
		Character(); // construktor
	protected:
	private:

	};
}//namespace logic
#endif //HPP_CHARACTER
```



Plik ***Character.cpp***

```c++
#include "Character.hpp"
namespace logic
{
	// construktor
	Character::Character()
	{
		// to do
	}

}//namespace logic

```



#### Destruktor

Plik ***Character.hpp***

Uzupełniamy klasę o destruktor. Obowiązuje taka sama zasada. Programista jest odpowiedzialny za niszczenie obiektu, tym samym musi zadbać o destruktor i jego działanie.

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

namespace logic
{
	class Character
	{

	public:
		Character(); // construktor
		~Character();// destruktor
	protected:
	private:

	};
}//namespace logic
#endif //HPP_CHARACTER
```



Plik ***Character.cpp***

```c++
#include "Character.hpp"
namespace logic
{
	// construktor
	Character::Character()
	{
		// to do
	}

	// destruktor
	Character::~Character()
	{
		// to do
	}

}//namespace logic
```



#### Operator zasięgu ::

Pewnie zastanawiasz się nad zapisem konstruktora i destruktora w pliku implementacyjnym **Character.cpp** klasy **Character**.

```c++
...
// construktor
Character::Character() // tutaj widzimy operator zakresu ::
{
	// to do
}
...
```

Powyższy zapis to odwołanie się operatorem zasięgu :: do klasy **Character**  do jej konstruktora **Character**. Możemy także powiedzieć, że na rzecz klasy **Character** został wywołany jej konstruktor. Podobnie jest w przypadku pozostałych metod, co będzie można zaobserwować w dalsze części tego opracowania.



#### Tworzymy dokumentację

​		Na etapie tworzenie klasy nie zapominajmy, że wymogi projektu związane z tworzeniem kodu, zobowiązują nas do tworzenia jego dokumentacji. Jak wcześniej ustaliliśmy, będziemy korzystali z oprogramowania **Doxygen** - generatora dokumentacji.

> Tworzenie kodu wraz ze stosowaniem znaczników generatora Doxygen to same korzyści. Dokumentacja tworzy się w tym samym czasie co tworzony kod. Czas poświęcony na pisanie dokumentacji opłaca się, bo wszystko robimy w tym samym czasie i tylko raz.

Plik ***Character.hpp***

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

namespace logic
{
	////////////////////////////////////////////////////////////
	/// \brief Class represents game object
	///
	////////////////////////////////////////////////////////////
	class Character
	{

	public:
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		////////////////////////////////////////////////////////////
		Character();

		////////////////////////////////////////////////////////////
		/// \brief Destruktor
		///
		////////////////////////////////////////////////////////////
		~Character();

	protected:

	private:

	};
}//namespace logic
#endif //HPP_CHARACTER

```



​		W dalszej części tego opracowania, dodając kolejne porcje kodu (funkcjonalności), uwzględniany będzie format zapisu komentarzy. Zapis będzie zgodny z formatem dla generatora _**Doxygen**_. Przyjęto zasadę, że użyty format będzie taki sam lub podobny do tego, który został użyty w kodzie źródłowym biblioteki SFML.  Wydaje się oczywiste, że powinniśmy przyjąć ten format, ponieważ od biblioteki zależy architektura naszego projektu. Zawsze możemy zajrzeć do repozytorium, w którym znajduje się kod źródłowy biblioteki SFML.

> Czytaj dokumentację bibliotek, z których korzystasz w swoich projektach. Dokumentacja powinna stanowić podstawę odnośnie podejmowanych decyzji. W dokumentacji powinniśmy znaleźć kompletną informację na temat interfejsu programowania aplikacji **API** (ang. Application Programming Interface) oraz przykłady stworzone i przetestowane przez ich Autorów, co powinno stanowić źródło sprawdzonej i rzetelnej wiedzy. Kod uwzględniany w dokumentacji to solidne założenia projektowe. Uwzględniający standard języka C++. Wykorzystujący sprawdzone wzorce projektowe (ang. design pattern). Uczmy się od najlepszych.



#### Kodowanie znaków

​		Aby być bardzo dokładnym i zachować wszystkie zasady, pamiętajmy o kodowaniu plików z kodem źródłowym. Musimy zdawać sobie sprawę, że nasz kod będzie opublikowany na zdalnym repozytorium. Dlatego  też, aby wszystko prawidłowo było wyświetlanie (polskie znaki), musimy zadbać o prawidłowe kodowanie plików.

W Środowisku MS Visual Studio należy w odniesieniu do każdego pliku źródłowego wybrać opcję

_**Zapisz ... jako**_, z listy rozwijalnej wybieramy opcję _**Zapisz z kodowaniem...**_.



![sci_engine_010](..\graphics\sci_engine_010.png)

Potwierdzamy operację.

![sci_engine_011](..\graphics\sci_engine_011.png)



Wybieramy kodowanie UTF-8

![sci_engine_012](..\graphics\sci_engine_012.png)





#### Tworzymy obiekty

> Klasa to zdefiniowany przez użytkownika (programistę) typ. Natomiast obiekt to egzemplarz tej klasy. W przedstawionym poniżej kodzie (plik **main.cpp**) zaprezentowano prawidłowe tworzenie obiektu klasy **Character**.

Mając klasę **Character** możemy tworzyć egzemplarze tej klasy - obiekty. W pliku **main.cpp** został utworzony obiekty tej klasy. Pamiętaj, że musimy za pomocą dyrektywy _#include_ dołączyć plik nagłówkowy **Character.hpp**, aby móc korzystać z takiego typu.

Typ klasowy został poprzedzony nazwą przestrzeni, w której znajduje się deklaracja klasy. Jak zostało to wcześniej zaznaczone, nie korzystamy z dyrektywy _using namespace logic;_

Warto wytłumaczyć dlaczego przyjęto taką zasadę? Otóż posługując się zapisem typu poprzedzonego nazwą przestrzeni, programista czytając kod, wie w  jakiej przestrzeni znajduje się deklaracja typu (w naszym przypadku typ klasowy **Character**). Przy dużych projektach, gdy funkcjonuje ogromna ilość nazw zmiennych, stałych, funkcji, metod i wszystkich innych składowych języka, jest to bardzo ważne.

```c++
#include "Character.hpp"

int main()
{
	logic::Character alfa;

	return 0;
}
```



Zapis w zamieszczonym powyżej kodzie oznacza, że w funkcji _main()_ tworzymy obiekt o identyfikatorze _alfa_, który jest  klasy **Character**, która to klasa znajduje się w przestrzeni _**logic**_ naszego projektu.



#### Rozbudowa funkcjonalności

​		W ramach omawiania procesu tworzenia klasy (dekompozycja funkcjonalna), dodamy do klasy **Character** funkcjonalność odpowiedzialną za prędkość poruszania się obiektu.

W pliku **Character.hpp**, w sekcji za modyfikatorem _**private:**_ dodamy pole _**m_velocity**_. W tym polu obiekty tej klasy będą przechowywać wartość prędkości danego obiektu. Wartość tego pola reprezentowana jest liczbą zmiennoprzecinkową typu _float_. Pamiętamy, że typ _float_ to typ predefiniowany, typ wbudowany.

> Zgodnie z ustaleniami dotyczącymi pisania kodu, nazwy składowych klas będziemy poprzedzali małą literą m (ang. members) .

```c++
...
	private:
		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		float m_velocity; // velocity
...
```

Umieszczenie tej składowej w sekcji prywatnej klasy gwarantuje, że składowa ta będzie dostępna (będzie można wartość tej zmiennej odczytywać i ewentualnie modyfikować) tylko wewnątrz tej klasy. Jest to zgodne z zasadą hermetyzacji (enkapsulacji) stosowanej wobec paradygmatu programowania obiektowego.

W jaki zatem sposób zarządzać tworzonymi obiektami tej klasy, w tym kontekście ich prędkością? Jak odczytywać wartość prędkości obiektu? Jak ją zmienić?

Zrealizujemy to budując **<u>publiczny interfejs</u>** dla tej klasy **API**, odpowiedzialny za zarządzanie prędkością. Utworzymy dwie metody, za pomocą których zrealizujemy to zadanie.

> Pamiętaj, że w programowaniu obiektowym funkcje będziemy nazywali _**metodami**_.



W pliku **Character.hpp** w sekcji _**public:**_ dodajemy deklarację metody odpowiedzialnej za pobieranie prędkości.

```c++
...
////////////////////////////////////////////////////////////
/// \brief Get the velocity of the object
///
/// \return velocity
///
////////////////////////////////////////////////////////////
const float getVelocity() const;
...
```

> Zapamiętaj, że dodając deklarację metody _**const float getVelocity() const;**_ w pliku nagłówkowym **Character.hpp**, należy umieść ją po wcześniej zadeklarowanych metodach (w naszym przypadku po destruktorze). Taką samą zasadę warto przyjąć w pliku implementacyjnym **Character.cpp**. Wypracowując styl kodowania oraz zachowując porządek w kodzie, łatwiej nim zarządzać. Stosując się do zasad związanych z dokumentowaniem kodu, łatwiej będzie, szczególnie mniej doświadczonym programistom C++, zrozumieć zasady tworzenie kodu oraz jego działanie. Czasami stosuje się zasadę, że deklaracje metod umieszcza się w kolejności alfabetycznej. Czasami metody deklarowane są w grupach – na podstawie funkcjonalności, które realizują. Liczy się konsekwencja stosowanych zasad.

Omówimy pokrótce tę metodę oraz zapis jej deklaracji.

- Metoda posiada nazwę: _**getVelocity()**_
- Nazwa metody zapisana jest zgodnie z zasadą _**camelCase**_ (system notacji ciągów tekstowych), którą będziemy stosowali
- Metoda nie posiada parametrów
- Metoda zwraca  wartość typu _**float**_
- Przed typem metody, która zwraca (_**float**_) znajduje się kwalifikator_**const**_, co oznacza, że wartość, którą zwróci jest stała - nie można jej modyfikować.
- Z kolei kwalifikator _**const**_ za jej deklaracją oznacza, że taka metoda w swoim ciele, nie może zmieniać wartość żadnej ze składowych tej klasy
- Podsumowując - kwalifikator _**const**_ to informacja dla kompilatora, aby to, co jest tym modyfikatorem oznaczone, nie mogło być modyfikowane

> Aby te wszystkie subtelności związane z użyciem kwalifikatora _**const**_ zapamiętać, używać oraz zrozumieć, najprościej zastosować zasadę polegającą na stosowaniu _**const**_ powszechnie. Jeśli zaistnieje uzasadniona konieczność wykluczenia _**const**_, to programista podejmie świadomie taką decyzję.
>
> Możesz czasami spotkać się z określeniem publicznych metod dostępowych jako _**get**_ i _**set**_ (_getter_, _setter_). Metody te tworzą interfejs, za pomocą którego możemy odczytywać lub nadawać wartości składowym klasy umieszczonymi w sekcji oznaczonej modyfikatorem _**private**_ i _**protected**_, co w dalszej części tego opracowania zostanie omówione. Stąd taka właśnie nazwa omawianej metody. Nazwy metod powinny być jak najkrótsze, jednoznaczne, intuicyjne.

W pliku **Character.cpp** utworzymy implementację tej metody.

```c++
...
const float Character::getVelocity() const
{
	return m_velocity;
}
...
```

Zauważ, że zapis jest podobny do zapisu deklaracji umieszczonego w pliku **Character.hpp**. Przed nazwą metody umieściliśmy nazwę klasy **Character**, następnie posługując się operatorem zasięgu **::** odwołujemy się do metody _**getVelocity()**_. Musimy także uwzględnić kwalifikator _**const**_, który znajdują się w deklaracji.

Ciało funkcji to słowo _**return**_, po którym podajemy, jaką składową metoda zwraca. Na tym etapie naszego opracowania należy zaznaczyć, że funkcja zwróci kopię składowej _**m_velocity**_, czyli wartość, którą w chwili wywołania tej metody ta składowa przechowuje. W ramach pracy nad tworzeniem gry, w dalszej części tego opracowania, zostaną omówione takie elementy języka C++ jak wskaźniki i referencje.

Poniżej przykład wywołania tej metody w funkcji _**main()**_.

```c++
#include "Character.hpp"

int main()
{
	logic::Character alfa;

	float wynik = alfa.getVelocity();

	return 0;
}
```

Należy zwrócić uwagę na bardzo ważny aspekt dotyczący nauki programowania. Chodzi o testowanie oprogramowania. Każdy, kto poważnie myśli o programowaniu musi także znać zasady związane z jego jego testowaniem. Zanim poznamy szczegóły dotyczące testowania, między innymi **pojęcie testów jednostkowych**, musimy poprawnie nauczyć korzystać z narzędzi, które oferuje środowisko, w którym powstaje nasz projekt. Poznanie tego środowiska to proces rozłożony w czasie. MS Visual Studio to rozbudowane narzędzie oferujące ogromną ilość funkcji. Poznanie ich wszystkich nie jest ani konieczne, ani możliwe w krótkim czasie. 

Skupmy się na możliwości jaką daje nam środowisko, w kontekście prawidłowego posługiwania się śledzeniem wartości zmiennych.

W trybie _**Debug**_ ustawimy punkt przerwania działania programu, aby sprawdzić, jaką wartość zwraca metoda _**getVelocity()**_.



![sci_engine_012](..\graphics\sci_engine_022.png)



> Testowanie programu wykorzystując wyświetlanie na konsoli wartości zmiennych prowadzi do złych nawyków. Dodatkowo programista musi cały czas nadzorować, co przesyła na konsolę. Nie wspominając już o testowaniu typów złożonych, co wymaga pisania dodatkowego kodu. Nasz kod zostaje naszpikowany coraz większą ilością komentarzy, niewykorzystanego kodu. Staje się nieczytelny. Wprowadza nieład i chaos.
>
> Pamiętaj - korzystaj z dobrodziejstw narzędzi wbudowanych w środowisko, w którym pracujesz. Unikniesz tego wszystkiego co prowadzi donikąd. Unikniesz zniechęcenia. Tego wszystkiego, co czyha na każdego programistę, który zaczyna przygodę z programowaniem.

Po uruchomieniu programu, punkt przerwania (ang. breakpoint) - _czerwona kropka widoczna na lewym marginesie_, zatrzyma wykonywanie programu na linii, w której ten punkt został umieszczony.

​		Zwróć uwagę na fakt, że wynik działania metody _**getVelocity()**_ zwracamy do zmiennej o identyfikatorze **wynik**. Wartość, która w tej zmiennej się znajduje, która reprezentuje prędkość - zawiera "dziwną, ujemną liczbę". Nazywamy to "śmieciami". Program zarezerwował w wolnym obszarze pamięci miejsce na przechowanie tej wartości, ale jej nie zainicjował.

> Zawsze inicjuj zmienne.

Dzieje się tak dlatego, że w klasie **Character** nigdzie nie nadajemy temu polu (_**m_velocity**_) wartości. To, co widzimy to wartość pamięci, która służy do przechowywania liczny _**float**_. Miejscem, w którym powinniśmy to zrobić jest konstruktor klasy **Character**. Mamy już deklarację konstruktora. Musimy teraz zaimplementować działanie konstruktora.



#### Konstruktor domyślny

​		Deklaracje funkcji i metod w języku C++ poprzedzamy typem (void, int, float, **logic::Character**, etc.). W języku C++ w odniesieniu do <u>konstruktora</u> oraz <u>destruktora</u> jest odstępstwo od reguły. Konstruktory mają taką samą nazwę jak nazwa klasy i nie mają żadnego typu. Dodatkowo destruktor  poprzedzony jest znakiem **~** tyldy.

> Wiemy, że jeśli programista nie zdefiniuje konstruktora - kompilator zapisze go automatycznie za nas. Pamiętamy jednak, że to programista bierze całkowitą odpowiedzialność za kod, który wytwarza. Zawsze powinniśmy pisać własne konstruktory i destruktor.

Nasza klasa posiada już deklarację konstruktora. Dokończmy jego implementację. Będzie ona zgodna ze standardem, która będzie bazowała na liście inicjalizacyjnej (liście inicjującej). Zawsze stosuj konstrukcję opartą na _**liście inicjalizacyjnej**_.

Konstruktory powinny być jak najprostsze. Ich zadanie to przygotowanie powstającego obiektu danej klasy, do "życia" w środowisku, w którym ten obiekt powstaje. Konstruktor to metoda, która wykonuje się automatycznie w chwili tworzenie obiektu.

```c++
logic::Character alfa; // tutaj tworzony jest obiekt alfa i wywoływany konstruktor klasy Character
```

Plik ***Character.cpp***

Tak prawidłowo powinien prawidłowo wyglądać konstruktor.

```c++
// construktor
Character::Character() : // constructor initialization list 
	m_velocity{ 12.46f }
{
}
```



Za Konstruktorem umieszczamy dwukropek, po którym wymieniamy elementy, które na tej liście chcemy umieścić. Nasza klasa posiada tylko jedną składową. Gdyby było ich więcej, wymienilibyśmy je oddzielając je przecinkami. Warto tutaj zaznaczyć, że kolejność umieszczania elementów na liście ma znaczenie. Wynika to z logiki, która wskazuje, że aby czegoś użyć, to coś musi być znane.

Za składową _**m_velocity**_ otwieramy nawias klamrowy (standard języka C++11 i nowsze), w którym wpisujemy wartość, zgodną z typem tej składowej (_**float**_). W naszym przypadku jest to liczba (_**literał**_) 12.46f. Zauważ, że za tą liczbą, dla której kropka jest separatorem części całkowitej i dziesiętnej występuje mała litera f - wskazująca, że inicjujemy zmienną wartością typu _**float**_. Na podstawie takiego konstruktora wszystkie tworzone obiekty posiadałyby prędkość 12.46. Na tym etapie nie omawiamy jeszcze jednostek, w jakich interpretujemy prędkość obiektu.

Sama postać zapisu elementów listy jest dowolna. Język C++ daje ogromną elastyczność jeśli chodzi o zapis jego kodu. Priorytetem powinna być zawsze jego czytelność. W kodzie prezentowanym w tym opracowaniu dwukropek będzie umieszczany w linii za konstruktorem, a elementy listy, oddzielone przecinkiem, jeden pod drugim.

 

#### Destruktor

​		Destruktor to metoda, która wykonuje się, gdy obiekt ginie. W ramach omawiania tworzenia naszej gry, poświęcimy temu znacznie więcej miejsca w dalszej części tego opracowania. Dla porządku kod destruktora poniżej. 

```c++
// destruktor
Character::~Character()
{
	m_velocity = 0.0f;
}
```



​		Ucz się świadomie pisać konstruktory i destruktory. Trudno wytłumaczyć, dlaczego panuje przekonanie, że to czasami nadmiarowy, niepotrzebny kod. Przekonanie, że kompilator sam za nas zdecyduje, napisze, odwali brudną robotę.

Nie ma kodu nadmiarowego. Porządek w kodzie to podstawa. Prawidłowo budowany kod to nauka zasad. Składni. Dokumentowania. Stosowania standardów. Przypomnijmy, że programowanie to pisanie kodu. Nie jest to bezmyślne wklejanie, mechaniczna odtwórczość gotowych rozwiązań. Poprawianie kodu, aby działał wielokrotnie przekracza czas gdybyśmy napisali go samodzielnie. Jedno z ciekawszych twierdzeń dotyczących programowania mówić, **że najszybciej i najbezpieczniej wykonuje się kod, który nie wykonuje się nigdy**.



​		Wspomnieliśmy, że publiczny interfejs klasy **Character** będzie zawierał dwie metody. Pierwszą z nich już utworzyliśmy (_**getVelocity()**_). Utworzymy teraz metodę, dzięki, której będziemy mogli nadawać prędkość.

W pliku **Character.hpp** w sekcji _**public:**_ dodajemy deklarację metody odpowiedzialnej za nadawanie prędkości.

```c++
...
////////////////////////////////////////////////////////////
/// \brief Set the velocity of the object
///
/// \param velocity - velocity
///
////////////////////////////////////////////////////////////
void setVelocity(float velocity);
...
```



Omówimy pokrótce tę metodę oraz zapis jej deklaracji.

- Metoda posiada nazwę: _**setVelocity(float velocity)**_
- Metoda jest typu _**void**_, czyli nie zwraca żadnej wartości (można powiedzieć, że zwraca nic)
- Posiada jeden parametr o identyfikatorze _**velocity**_ typu _**float**_

W pliku **Character.cpp** jest jej implementacja

```c++
...
// Set the velocity of the object
void Character::setVelocity(float velocity)
{
	m_velocity = velocity;
}
...
```



Skoro już mówimy o parametrach metod (funkcji), warto doprecyzować, jaka jest różnica pomiędzy <u>**parametrem**</u>, a <u>**argumentem**</u>? Wielokrotnie operuje się tymi pojęciami zamiennie, a różnica jest zasadnicza. Proszę zauważyć, że zapis dla generatora dokumentacji _Doxygen_ posługuje się zapisem _param_. Jeśli tak to zapamiętamy, to nie dość, że poznajemy zasady dokumentowania kodu, to na dodatek prawidłowo odróżnimy pojęcia _**parametr**_ i _**argument**_.

> Zapamiętaj, że parametr to nazwa występująca w deklaracji metody, argument natomiast to konkretna wartość, którą podaje się wywołując metodę, dla której wymagane jest podanie parametru.
>
> Dokumentacji języka C++ wyjaśnia, że zmienna używana do odbioru przekazanej wartości w metodzie, nazywana jest *parametrem formalnym* albo porostu parametrem. Wartość przekazana do funkcji to *parametr faktyczny* lub po prostu argument.



```c++
...
void Character::setVelocity(float velocity) // parametr typu float o identyfikatorze velocity
...

...
alfa.setVelocity(100.0f); // wywołanie metody z argumentem o wartości 100.0f na rzecz obiektu alfa
float my_velocity = 56.67f;
alfa.setVelocity(my_velocity); // tutaj argumentem jest wartość zmiennej (obiektu) my_velocity
...
```



#### Podsumowanie

Kompletna klasa **Character** na tym etapie projektowania powinna posiadać następujący kod:

Plik _**Character.hpp**_

```c++
#ifndef HPP_CHARACTER
#define HPP_CHARACTER

namespace logic
{
	////////////////////////////////////////////////////////////
	/// \brief Class represents game object
	///
	////////////////////////////////////////////////////////////
	class Character
	{

	public:
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		////////////////////////////////////////////////////////////
		Character();

		////////////////////////////////////////////////////////////
		/// \brief Destruktor
		///
		////////////////////////////////////////////////////////////
		~Character();

		////////////////////////////////////////////////////////////
		/// \brief Get the velocity of the object
		///
		/// \return velocity
		///
		////////////////////////////////////////////////////////////
		const float getVelocity() const;

		////////////////////////////////////////////////////////////
		/// \brief Set the velocity of the object
		///
		/// \param velocity - velocity
		///
		////////////////////////////////////////////////////////////
		void setVelocity(float velocity);

	protected:

	private:
		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		float m_velocity; // velocity

	};
}//namespace logic
#endif //HPP_CHARACTER

```



Plik _**Character.cpp**_

```c++
#include "Character.hpp"
namespace logic
{
	// construktor
	Character::Character() : // constructor initialization list 
		m_velocity{ 12.46f }
	{
	}

	// destruktor
	Character::~Character()
	{
		m_velocity = 0.0f;
	}

	const float Character::getVelocity() const
	{
		return m_velocity;
	}

	// Set the velocity of the object
	void Character::setVelocity(float velocity)
	{
		m_velocity = velocity;
	}

}//namespace logic

```

​		

Omówione powyżej aspekty związane z projektowaniem klas w języku C++ nie wyczerpują całości zagadnień związanych z paradygmatem programowania obiektowego. Celem przedstawionych powyżej informacji jest  usystematyzowanie pojęć. Przestrzeganie zasad ustalonych dla tego projektu uczy prawidłowego podejścia do pracy programisty. Uwzględniają one dobór języka programowania, styl kodowania, dokumentowanie kodu, oraz wszystkie inne aspekty związanych z wybraną technologią. Stosujemy podejście związane z architekturą opartą na programowaniu obiektowym. Wykorzystujemy dedykowaną dla osiągnięcia zamierzonego celu - stworzenie gry - bibliotekę. To wszystko łączy elementy procesu wytwarzania oprogramowania.

> ### "Wartość produktu można ocenić po jego produkcji"
>
> Albert Einstein

