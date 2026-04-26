CREATE DATABASE CompanyDB;
USE CompanyDB;

-- Create Department Table
CREATE TABLE Departments (
    DeptId INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

-- Create Employee Table
CREATE TABLE Employee (
    Id INT PRIMARY KEY,
    Name VARCHAR(45),
    Salary INT,
    Gender VARCHAR(12),
    DepartmentId INT,
    FOREIGN KEY (DepartmentId) REFERENCES Departments(DeptId)
);

-- Create Audit Table (For Trigger Assignment)
CREATE TABLE Employee_Audit (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    EmpId INT,
    Action VARCHAR(50),
    ChangedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Insert Initial Data
INSERT INTO Departments VALUES 
(1, 'IT'), 
(2, 'HR'), 
(3, 'Sales');

INSERT INTO Employee VALUES
(1, 'Steffan', 82000, 'Male', 3),
(2, 'Amelie', 52000, 'Female', 2),
(3, 'Antonio', 25000, 'Male', 1),
(4, 'Marco', 47000, 'Male', 2),
(5, 'Eliana', 46000, 'Female', 3);

DELIMITER //

CREATE PROCEDURE DisplayTopEmployees()
BEGIN
    -- 1. Declare Variables
    DECLARE done INT DEFAULT FALSE;
    DECLARE emp_name VARCHAR(45);
    DECLARE emp_salary INT;

    -- 2. Declare Cursor
    DECLARE emp_cursor CURSOR FOR
        SELECT Name, Salary 
        FROM Employee 
        ORDER BY Salary DESC 
        LIMIT 3;

    -- 3. Handler
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    -- 4. Open Cursor
    OPEN emp_cursor;

    read_loop: LOOP
        -- Fetch data
        FETCH emp_cursor INTO emp_name, emp_salary;

        IF done THEN
            LEAVE read_loop;
        END IF;

        -- Display result
        SELECT CONCAT('Employee: ', emp_name, ' | Salary: ', emp_salary) AS EmployeeInfo;
    END LOOP;

    -- 5. Close Cursor
    CLOSE emp_cursor;
END //

DELIMITER ;

-- Execution
CALL DisplayTopEmployees();