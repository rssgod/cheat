CREATE DATABASE client;
USE client;
SET SQL_SAFE_UPDATES = 0;

CREATE TABLE Client_master(
    Client_NO INT,
    Name VARCHAR(20),
    Address VARCHAR(30),
    City VARCHAR(20),
    State VARCHAR(20),
    bal_due INT 
);

INSERT INTO Client_master 
VALUES
(1, 'Ramesh',  'MG Road',   'Mumbai',    'Maharashtra', 5000),
(2, 'Suresh',  'Ring Rd',   'Surat',     'Gujarat',     3000),
(3, 'Amit',    'Sector 5',  'Delhi',     'Delhi',       7000),
(4, 'Neha',    'FC Road',   'Pune',      'Maharashtra', 0),
(5, 'Priya',   'Park St',   'Kolkata',   'West Bengal', 2500),
(6, 'Rahul',   'BTM Rd',    'Bangalore', 'Karnataka',   1000),
(7, 'Ankit',   'Civil Ln',  'Jaipur',    'Rajasthan',   4500),
(8, 'Sneha',   'Lake Rd',   'Bhopal',    'Madhya Pradesh',2000),
(9, 'Vikas',   'Main Rd',   'Indore',    'Madhya Pradesh',6000),
(10,'Pooja',   'Hill Rd',   'Shimla',    'Himachal',    0);

SELECT * FROM Client_master;

SELECT Name
FROM Client_master
WHERE bal_due > 5000;

UPDATE Client_master
SET bal_due = 5100
WHERE Client_NO = 1;

ALTER TABLE Client_master
RENAME TO Client12;

SELECT Client_NO, Name, Address, City, State, bal_due AS BALANCE
FROM Client12;

ALTER TABLE Client12
RENAME TO Customer_info;

ALTER TABLE Customer_info
MODIFY bal_due FLOAT;

SELECT Client_NO, Name, bal_due AS Balance
FROM Customer_info;

SELECT * 
FROM Customer_info
WHERE City = 'Pune';

ALTER TABLE Customer_info
ADD Pincode INT;

TRUNCATE TABLE Customer_info;

SELECT * FROM Customer_info;
