/* -------------------------------------------
Group Project
Name: Marina Fiamskaia
Student number: 025-698-051
GROUP: 3
Email: mfiamska@myseneca.ca
Section: DBS 311 NFF
Date: February 19, 2022
----------------------------------------------
Assignment: 1 Main.ccp
----------------------------------------------
*/
CREATE TABLE course (
    course_id CHAR(9) PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL,
    program_id CHAR(3),
    instructor_employee_id CHAR(8),
    term_status VARCHAR(10) NOT NULL
); 

CREATE TABLE program (
    program_id CHAR(3) PRIMARY KEY,
    program_name VARCHAR(120) NOT NULL,
    department_id CHAR(3) NOT NULL
); 

CREATE TABLE school (
    school_id CHAR(3) PRIMARY KEY,
    school_name VARCHAR(120) NOT NULL,
    street_number NUMBER(5) NOT NULL,
    street_name VARCHAR(120) NOT NULL,
    city VARCHAR(60) NOT NULL,
    postal_code CHAR(6) NOT NULL,
    country VARCHAR(60) NOT NULL,
    phone_number VARCHAR(13) NOT NULL,
    email VARCHAR(60) NOT NULL,
    contact_person_name VARCHAR(60),
    CONSTRAINT phone_number_chk CHECK (phone_number LIKE '___.___.____'),
    CONSTRAINT email_chk CHECK (email LIKE '%@%') 
);
    
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'IPC144NAA', 'Introduction to Programming Using C', 'CPP', 'EDU56475', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'IPC144NBB', 'Introduction to Programming Using C', 'CPP', NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'ACC120HAA', 'Accounting Basics I', 'ACC', 'EDU59872', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'ACC120HBB', 'Accounting Basics I', 'ACC', NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ('AER121MJJ', 'Aeronautics I', 'AVO', 'EDU91881', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'AER121MKK', 'Aeronautics I', 'AVO', NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'LGL151FRR', 'Introduction to the Legal System for Paralegals', 'PLE', 'EDU52185', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'LGL151FGG', 'Introduction to the Legal System for Paralegals', 'PLE', NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'COM101FCC', 'Communicating Across Contexts', NULL, 'EDU52185', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'COM101FII', 'Communicating Across Contexts', NULL, NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'CHM173HFF', 'Chemistry', 'BTA', 'EDU42321', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'CHM173HKK', 'Chemistry', 'BTA', NULL, 'suspended');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'JRN110BCC', 'Reporting - Journalism Principles', 'JRN', 'EDU75389', 'active');
INSERT INTO course(course_id, course_name, program_id, instructor_employee_id, term_status)
    VALUES ( 'JRN110BAA', 'Reporting - Journalism Principles', 'JRN', NULL, 'suspended');
    
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'CPP', 'Computer Programming', 'EDU');
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'ACC', 'Accounting', 'EDU');
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'AVO', 'Aviation Operations', 'EDU');
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'PLE', 'Paralegal', 'EDU');
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'BTA', 'Biotechnology – Advanced', 'EDU');
INSERT INTO program (program_id, program_name, department_id)
    VALUES ( 'JRN', 'Journalism', 'EDU');
    
    
INSERT INTO school (school_id, school_name, street_number, street_name, city, postal_code, country, phone_number, email, contact_person_name)
    VALUES ( 'NWH', 'Newnham Campus', 1750, 'Finch Avenue East', 'Toronto', 'M2J2X5', 'Canada', '416.493.4144', 'registration.inquiries@senecacollege.ca', NULL);
INSERT INTO school (school_id, school_name, street_number, street_name, city, postal_code, country, phone_number, email, contact_person_name)
    VALUES ( 'KNG', 'King Campus', 13990, 'Dufferin Street', 'King City', 'L7B1B3', 'Canada', '647.265.3839', 'registration.inquiries@senecacollege.ca', NULL );
INSERT INTO school (school_id, school_name, street_number, street_name, city, postal_code, country, phone_number, email, contact_person_name)
    VALUES ( 'MRH', 'Markham Campus', 8, 'The Seneca Way', 'Markham', 'L3R5Y1', 'Canada', '647.265.3847', 'registration.inquiries@senecacollege.ca', NULL  );

--these constraints should be added after all my tables are created
ALTER TABLE course
    ADD CONSTRAINT program_id_fk FOREIGN KEY (program_id) REFERENCES program (program_id);

--these constraints should be added only after the department table is created
ALTER TABLE program
    ADD CONSTRAINT department_fk FOREIGN KEY (department_id) REFERENCES department (department_id);