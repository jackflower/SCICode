-- SCI 2021-11-17
-- Widok jako źródło zapytania

-- Description - klauzula GROUP BY
SELECT
	student_age.name,
	student_age.wiek
    FROM student_age
    GROUP BY student_age.name

-- Description - klauzula HAVING
SELECT
	student_age.name,
	student_age.wiek
    FROM student_age
    GROUP BY student_age.name
	HAVING student_age.wiek >= 32


-- Funkcje  a g r e g u j ą c e


-- Description - Agregaty i grupowanie - example
SELECT
    MIN(student_age.wiek) AS "Najmłodszy",
	MAX(student_age.wiek)  AS "Najstarszy",
    AVG(student_age.wiek) AS "Średni"
    FROM student_age
    GROUP BY student_age.name
	
	
-- Description - Agregaty i grupowanie - example
SELECT
    MIN(student_age.wiek) AS "Najmłodszy",
	MAX(student_age.wiek)  AS "Najstarszy",
    AVG(student_age.wiek) AS "Średni",
	COUNT(*) AS "Liczba"
    FROM student_age
    GROUP BY student_age.name


-- Description - Agregaty i grupowanie - example
SELECT
    MIN(student_age.wiek) AS "Najmłodszy",
	MAX(student_age.wiek)  AS "Najstarszy",
    AVG(student_age.wiek) AS "Średni",
    student_age.name
    FROM student_age
    GROUP BY student_age.name
	
	
-- Description - Agregaty i grupowanie - example
SELECT
    MIN(student_age.wiek) AS "Najmłodszy",
	MAX(student_age.wiek)  AS "Najstarszy",
    AVG(student_age.wiek) AS "Średni",
	COUNT(*) AS "Liczba",
    student_age.name
    FROM student_age
    GROUP BY student_age.name	
	

-- Description - Agregaty i grupowanie - example
SELECT
    student_age.name,
    COUNT(*) AS "Liczba osób o tym imieniu"
    FROM student_age
    GROUP BY student_age.name


-- Description - Klauzula HAVING
SELECT
    student_age.name,
    COUNT(*) AS "Liczba osób o tym imieniu"
    FROM student_age
    GROUP BY student_age.name
	HAVING student_age.name = "Anna"
	
-- Tworzenie syntetycznych danych - Big Data
--  Omówienia zadania domowego

