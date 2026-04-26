CREATE DATABASE college;

USE college;

SET SQL_SAFE_UPDATES = 0;
SET autocommit = 0;

CREATE TABLE Teacher(
    Name VARCHAR(30),
    DeptNo INT,
    Date_of_joining DATE,
    DeptName VARCHAR(15),
    Location VARCHAR(30),
    Salary INT,
    Job_ID CHAR(10)
);

INSERT INTO Teacher VALUES
('Amit Sharma', 101, '2015-06-15', 'Mathematics', 'Pune', 55000, 'PROF01'),
('Neha Patil', 102, '2018-07-20', 'Commerce', 'Mumbai', 48000, 'PROF02'),
('Rahul Deshmukh', 103, '2012-01-10', 'Physics', 'Nagpur', 62000, 'PROF03'),
('Sneha Kulkarni', 101, '2019-03-25', 'Mathematics', 'Pune', 50000, 'PROF04'),
('Vikas Joshi', 104, '2016-11-05', 'Commerce', 'Nashik', 53000, 'PROF05'),
('Priya Mehta', 102, '2020-08-12', 'English', 'Mumbai', 47000, 'PROF06'),
('Rohan Singh', 105, '2014-09-18', 'History', 'Aurangabad', 60000, 'PROF07'),
('Anjali Verma', 103, '2017-02-14', 'Physics', 'Nagpur', 52000, 'PROF08'),
('Kiran Rao', 101, '2013-12-01', 'Mathematics', 'Nashik', 58000, 'PROF09'),
('Pooja Nair', 105, '2021-04-22', 'Commerce', 'Aurangabad', 45000, 'PROF10');
COMMIT;
SELECT * FROM Teacher;

UPDATE Teacher
SET Salary = Salary + (Salary * 0.25)
WHERE DeptName = 'Mathematics';

SELECT * FROM Teacher;

ROLLBACK;
SELECT * FROM Teacher;

UPDATE Teacher
SET Salary = Salary + (Salary * 0.15)
WHERE DeptName = 'Commerce';

SELECT * FROM Teacher;

COMMIT;

SELECT * FROM Teacher;

ALTER TABLE Teacher
MODIFY Date_of_joining DATE NOT NULL;

DESC Teacher;

ALTER TABLE Teacher
MODIFY Job_ID VARCHAR(10);

DESC Teacher;

ALTER TABLE Teacher
ADD HIREDATE DATE;

UPDATE Teacher
SET HIREDATE = Date_of_joining;

ALTER TABLE Teacher
MODIFY HIREDATE DATE NOT NULL;
DESC Teacher;

ALTER TABLE Teacher
MODIFY Job_ID VARCHAR(40);
DESC Teacher;

DELETE FROM Teacher
WHERE DeptName = 'Commerce';

SELECT * FROM Teacher;