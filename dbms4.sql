CREATE DATABASE company;
USE company;
SET SQL_SAFE_UPDATES = 0;


CREATE TABLE Sales (
    Sales_No INT,
    Salesname VARCHAR(20),
    Branch VARCHAR(20),
    Salesamount INT,
    DOB DATE
);
DESC Sales;

INSERT INTO Sales VALUES 
(1, 'Amit', 'Pune', 50000, '1999-12-21'),
(2, 'Sneha', 'Mumbai', 45000, '1998-05-14'),
(3, 'Rahul', 'Pune', 60000, '1997-12-10'),
(4, 'Priya', 'Delhi', 55000, '1996-03-25'),
(5, 'Kiran', 'Mumbai', 70000, '1995-12-05');

SELECT * FROM Sales;

SELECT Branch, SUM(Salesamount) AS Total_Sales
FROM Sales
GROUP BY Branch;

SELECT Branch, AVG(Salesamount) AS Average_Sales
FROM Sales
GROUP BY Branch;

SELECT Salesname,
       DATE_FORMAT(DOB, '%d-%b-%y') AS DOB
FROM Sales
WHERE MONTH(DOB) = 12;

SELECT Salesname, DOB
FROM Sales
ORDER BY MONTHNAME(DOB);

SELECT UPPER(Salesname) AS Salesman_Name
FROM Sales;