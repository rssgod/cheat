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

CREATE TRIGGER After_Employee_Update
AFTER UPDATE ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO Employee_Audit (EmpId, Action)
    VALUES (
        OLD.Id,
        CONCAT('Salary changed from ', OLD.Salary, ' to ', NEW.Salary)
    );
END //

DELIMITER ;

-- Test the Trigger
UPDATE Employee SET Salary = 90000 WHERE Id = 2;

-- Check Audit Log
SELECT * FROM Employee_Audit;