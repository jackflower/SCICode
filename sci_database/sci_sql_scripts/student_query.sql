-- Wiek osoby
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
	FROM student;
	
-- Wiek osoby o wskazanym imieniu
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.name = "Anna"

-- Osoby o wskazanym imieniu oraz dacie urodzenia posortowane według wieku
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.name = "Jacek" AND YEAR(student.date_of_birth) > 1942 ORDER BY wiek

-- Osoby o wskazanym miesiącu urodzenia posortowane według wieku
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE MONTH(student.date_of_birth) = 7 ORDER BY wiek

-- Osoby o wskazanej dacie urodzenia posortowane według wieku
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.date_of_birth = "1992-02-07" ORDER BY wiek

-- template
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    MIN(TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE())) AS wiek
	FROM student;

-- template
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    MAX(TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE())) AS wiek
	FROM student;	

-- template - dzień urodzenia
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek,
    DAYNAME(student.date_of_birth)
	FROM student;

-- template - wskazana data oraz dzień urodzenia
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek,
    -- DAYNAME(student.date_of_birth),
    DAYNAME("1962-07-26")
	FROM student;
