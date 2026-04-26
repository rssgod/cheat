CREATE DATABASE employee;
USE employee;

SET SQL_SAFE_UPDATES = 0;

CREATE TABLE EMPLOYEES(
    Employee_Id INT PRIMARY KEY,
    First_Name VARCHAR(50),
    Last_Name VARCHAR(50),
    Email VARCHAR(100),
    Phone_Number VARCHAR(20),
    Hire_Date DATE,
    Job_Id INT,
    Salary DECIMAL(10,2),
    Commission_Pct DECIMAL(4,2),
    Manager_Id INT,
    Department_Id INT
);

INSERT INTO EMPLOYEES VALUES
(101, 'John', 'Austin', 'john.austin@company.com', '1234567892', '2011-01-13', 3, 6000, 0.00, 100, 60),
(102, 'Neena', 'Kochhar', 'neena.kochhar@company.com', '1234567891', '2009-09-21', 2, 17000, 0.00, 100, 90),
(103, 'Alexander', 'Hunold', 'alexander.hunold@company.com', '1234567893', '2012-01-03', 3, 9000, 0.00, 102, 60),
(104, 'Bruce', 'Ernst', 'bruce.ernst@company.com', '1234567894', '2015-05-21', 3, 4800, 0.00, 103, 60),
(105, 'David', 'Austin', 'david.austin@company.com', '1234567895', '2013-06-25', 4, 4800, 0.10, 101, 80),
(106, 'Amit', 'Sharma', 'amit.sharma@company.com', '1234567896', '2016-03-15', 4, 7000, 0.15, 101, 70),
(107, 'Anita', 'Verma', 'anita.verma@company.com', '1234567897', '2017-07-10', 5, 6500, 0.00, 101, 70),
(108, 'Rohit', 'Mehta', 'rohit.mehta@company.com', '1234567898', '2018-08-18', 6, 7200, 0.05, 101, 80),
(109, 'Priya', 'Nair', 'priya.nair@company.com', '1234567899', '2019-09-22', 7, 8000, 0.00, 100, 60),
(110, 'Arjun', 'Patel', 'arjun.patel@company.com', '1234567800', '2020-11-05', 3, 9500, 0.00, 103, 60);

SELECT * FROM EMPLOYEES;

SELECT Employee_Id, First_Name, Last_Name, Salary
FROM EMPLOYEES;

SELECT Employee_Id, First_Name, Last_Name
FROM EMPLOYEES
WHERE Manager_Id = 100;

SELECT First_Name, Last_Name, Salary
FROM EMPLOYEES
WHERE Salary >= 4800;

SELECT *
FROM EMPLOYEES
WHERE Last_Name = 'AUSTIN';

SELECT First_Name, Last_Name, Department_Id
FROM EMPLOYEES
WHERE Department_Id IN (60, 70, 80);

SELECT DISTINCT Manager_Id
FROM EMPLOYEES;

SELECT First_Name, Last_Name, Hire_Date
FROM EMPLOYEES
WHERE Hire_Date > '2010-01-01';

SELECT First_Name, Last_Name
FROM EMPLOYEES
WHERE First_Name LIKE 'A%';

DELETE FROM EMPLOYEES
WHERE Employee_Id = 102;

SELECT * FROM EMPLOYEES;

UPDATE EMPLOYEES
SET Salary = 50000
WHERE First_Name = 'John';

SELECT * FROM EMPLOYEES;