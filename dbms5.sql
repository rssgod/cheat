CREATE DATABASE CollegeDB;
USE CollegeDB;

CREATE TABLE Department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50),
    location VARCHAR(50)
);

CREATE TABLE Student (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    age INT,
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
);

INSERT INTO Department VALUES
(1, 'Computer Science', 'Block A'),
(2, 'Mechanical', 'Block B'),
(3, 'Electrical', 'Block C');
SELECT * FROM Department;

INSERT INTO Student VALUES
(101, 'Amit', 20, 1),
(102, 'Neha', 21, 1),
(103, 'Rahul', 22, 2),
(104, 'Sneha', 20, null);
SELECT * FROM Student;

CREATE VIEW StudentDeptView AS
SELECT s.student_id, s.student_name, d.dept_name
FROM Student s
JOIN Department d ON s.dept_id = d.dept_id;

SELECT * FROM StudentDeptView;

UPDATE Student
SET student_name = 'Amit Sharma'
WHERE student_id = 101;

SELECT * FROM StudentDeptView;

DROP VIEW StudentDeptView;

SELECT s.student_name, d.dept_name
FROM Student s
INNER JOIN Department d
ON s.dept_id = d.dept_id;

SELECT s.student_name, d.dept_name
FROM Student s
LEFT JOIN Department d
ON s.dept_id = d.dept_id;

SELECT s.student_name, d.dept_name
FROM Student s
RIGHT JOIN Department d
ON s.dept_id = d.dept_id;

SELECT student_name
FROM Student
WHERE dept_id IN (
    SELECT dept_id
    FROM Department
    WHERE location = 'Block A'
);

SELECT student_name
FROM Student s
WHERE EXISTS (
    SELECT 1
    FROM Department d
    WHERE s.dept_id = d.dept_id
);
