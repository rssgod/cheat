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

CREATE PROCEDURE UpdateSalary(IN emp_id INT, IN new_salary INT)
BEGIN
    -- Exception Handling
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        SELECT 'An error occurred during the update.' AS ErrorMessage;
    END;

    -- Business Logic
    IF (SELECT COUNT(*) FROM Employee WHERE Id = emp_id) = 0 THEN
        SELECT 'Employee ID not found' AS WarningMessage;
    ELSE
        UPDATE Employee 
        SET Salary = new_salary 
        WHERE Id = emp_id;

        SELECT 'Salary updated successfully' AS SuccessMessage;
    END IF;
END //

DELIMITER ;

-- Execution
CALL UpdateSalary(1, 85000);