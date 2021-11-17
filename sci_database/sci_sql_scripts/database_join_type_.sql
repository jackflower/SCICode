-- Przykładowe zapytanie do bazy
-- Osoby bez adresu
SELECT
	osoby.imie,
    miejscowosci.miejscowosc
FROM osoby
	LEFT JOIN miejscowosci ON
    miejscowosci.miejscowosc = osoby.id_miejscowosc
WHERE ISNULL (osoby.id_miejscowosc)

-- Osoby miejscowosci
SELECT
	osoby.imie,
	miejscowosci.miejscowosc
FROM osoby
	LEFT JOIN miejscowosci ON
	miejscowosci.id_miejscowosc = osoby.id_miejscowosc
	
-- Osoby z adresem
SELECT
	osoby.imie,
	miejscowosci.miejscowosc
FROM osoby
	JOIN miejscowosci ON
	miejscowosci.id_miejscowosc = osoby.id_miejscowosc	