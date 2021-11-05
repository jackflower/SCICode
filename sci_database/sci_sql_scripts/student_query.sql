CREATE TABLE
	demografia.kasowanie
		( id_student INT NOT NULL AUTO_INCREMENT,
		  name VARCHAR(20) CHARACTER SET utf8 COLLATE utf8_polish_ci NOT NULL,
		  date_of_birth DATE NOT NULL,
	PRIMARY KEY (id_student))
	
	ENGINE = InnoDB;
	
	
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
	FROM student;
	
	
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.name = "Jacek"


SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.name = "Jacek" AND YEAR(student.date_of_birth) > 1942 ORDER BY wiek

SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE MONTH(student.date_of_birth) = 7 ORDER BY wiek

SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek
FROM student
WHERE student.date_of_birth = "1992-02-07" ORDER BY wiek


SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    MIN(TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE())) AS wiek
	FROM student;
	
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    MAX(TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE())) AS wiek
	FROM student;	

SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek,
    DAYNAME(student.date_of_birth)
	FROM student;
	
SELECT
	student.name,
	student.date_of_birth,
    CURDATE(),
    TIMESTAMPDIFF(YEAR,student.date_of_birth,CURDATE()) AS wiek,
    -- DAYNAME(student.date_of_birth)
    DAYNAME("1962-07-26")
	FROM student;

