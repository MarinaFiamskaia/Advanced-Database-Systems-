/* -------------------------------------------
Group Project
Member 1:	Marina Fiamskaia	025-698-051   mfiamska@myseneca.ca
Member 2:	Anna Alexeeva       046-920-138   aanna@myseneca.ca
Member 3:	Denys Moroz         154-298-194   dmoroz1@myseneca.ca
Member 4:	Majid Asemi 		121-606-206   amajid10@myseneca.ca
GROUP: 3
Section: DBS 311 NFF
Date: April 2, 2022
----------------------------------------------
Assignment: 2 Procedures.sql
----------------------------------------------
*/
--Student Table (Anna’s)
--1.Sudent UPDATE
CREATE OR REPLACE 
PROCEDURE update_student (s_id in char, newStudentEmail in string, result out string) 
as  
BEGIN 
    UPDATE students 
    SET email=newStudentEmail 
    WHERE 
    student_id=s_id; 
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows updated'); 
END; 
 
--2.Sudent ADD
CREATE OR REPLACE 
PROCEDURE insert_student (s_id in char, newFirstname in string, newLastname in string, newStreetNumber in string, newStreetName in string, newCity in string, newPostalCode in string, newPhoneNumber in string, newEmail in string, newStudentRegistrationId in string, newDepartmentId in string, result out string) 
as  
BEGIN 
  
INSERT INTO students (student_id, first_name, last_name, street_number, street_name, city, postal_code, phone_number, email, student_registration_id, department_id) 
VALUES (s_id, newFirstname, newLastname, newStreetNumber, newStreetName,newCity, newPostalCode, newPhoneNumber,  newEmail, newStudentRegistrationId, newDepartmentId); 
  
result := SQL%rowcount; 
dbms_output.put_line('There were a total of  ' || result || ' rows inserted'); 
END insert_student; 
 
--3.delete student
CREATE OR REPLACE 
PROCEDURE delete_student (s_id in char, result out string) 
as  
BEGIN 
DELETE FROM students 
WHERE 
student_id = s_id; 
result := SQL%rowcount; 
dbms_output.put_line('There were a total of  ' || result || ' rows updated'); 
END; 

--4. View Student
create or replace PROCEDURE view_student (s_id in char, stud_id out string, studFirstname out string, studLastname out string, studStreetNumber out string, 
			studStreetName out string, studCity out string, studPostalCode out string, studPhoneNumber out string, studEmail out string, 
			studentRegistrationId out string, departmentId out string, result out string)
as 
BEGIN
	SELECT student_id, first_name, last_name, street_number, street_name, city, postal_code, phone_number,
		email, student_registration_id, department_id
	INTO stud_id, studFirstname, studLastname, studStreetNumber, studStreetName, studCity, 
		studPostalCode, studPhoneNumber,  studEmail, studentRegistrationId, departmentId
	FROM students
	WHERE student_id=s_id;
	result := SQL%rowcount;
	dbms_output.put_line('There were a total of  ' || result || ' rows viewed');
END view_student;

--Course Table (Denys’s)
--1. delete course 
create or replace PROCEDURE delete_course (c_id in CHAR, result OUT STRING)  
 
as   
 
BEGIN  
 
    DELETE FROM course  
 
    WHERE course_id=c_id;  
 
    result :=SQL%rowcount;  
 
    dbms_output.put_line('The were total of ' || result || ' course deleted');  
 
END delete_course;  
 
--2.add course 
create or replace PROCEDURE add_course (c_id in CHAR, newCourse in STRING, result out string)   
 
as    
 
BEGIN   
 
    INSERT INTO course (course_id, course_name, program_id, instructor_employee_id, term_status)   
 
    VALUES (c_id, newCourse, 'WEB');   
 
    result := SQL%rowcount;   
 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');  
 
END add_course;   
 
--3.update course 
create or replace PROCEDURE update_course (c_id in CHAR, newCID in STRING, newCourse in STRING, result OUT STRING)  
 
as  
 
BEGIN  
 
    UPDATE course 
 
    SET course_name=newCourse, course_id=newCID  
 
    WHERE   
 
    course_id=c_id;  
 
    result :=SQL%rowcount;  
 
    dbms_output.put_line('The were total of ' || result || ' course updated');  
 
END update_course;  
 
--4.view course 
create or replace PROCEDURE view_course (c_id in CHAR, cr_id out STRING, cr_name out STRING,  
 
                        cr_program out STRING, result out string)   
 
as    
 
BEGIN   
 
    SELECT course_id, course_name, program_id  
 
    INTO cr_id, cr_name, cr_program  
 
    FROM course 
 
    WHERE course_id=c_id;      
 
    result := SQL%rowcount;   
 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');  
 
END view_course; 
 
--Programs Table (Marina’s)
--1.Delete program --working in cpp
create or replace PROCEDURE delete_program (p_id in CHAR, result OUT STRING)
as 
BEGIN
    DELETE FROM program
    WHERE program_id=p_id;
    result :=SQL%rowcount;
    dbms_output.put_line('The were total of ' || result || ' program deleted');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The program is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END delete_program;

--2.Update select program --working in cpp 
create or replace PROCEDURE update_program (p_id in CHAR, newID in STRING, newName in STRING, result OUT STRING)
as
BEGIN
    UPDATE program
    SET program_name=newName, program_id=newID
    WHERE 
    program_id=p_id;
    result :=SQL%rowcount;
    dbms_output.put_line('The were total of ' || result || ' program updated');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The program is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END update_program;
    

--3.ADD new program
create or replace PROCEDURE add_program (p_id in STRING, newName in STRING, result out string) 
as  
BEGIN 
    INSERT INTO program (program_id, program_name, department_id) 
    VALUES (p_id, newName, 'EDU'); 
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END add_program; 

--4. View Selected program --working in cpp
create or replace PROCEDURE view_program (p_id in STRING, pr_id out STRING, pr_name out STRING,
                        pr_department out STRING, result out string) 
as  
BEGIN 
    SELECT program_id, program_name, department_id
    INTO pr_id, pr_name, pr_department
    FROM program
    WHERE program_id=p_id;    
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END view_program; 

--Department Table (Majid's)
-- 1. Delete Department 
create or replace PROCEDURE delete_department (d_id in CHAR, result OUT STRING) 
as  
BEGIN 
    DELETE FROM department 
    WHERE department_id=d_id; 
    result :=SQL%rowcount; 
    dbms_output.put_line('The were total of ' || result || ' department deleted'); 
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The department is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END delete_department; 

 
--2. Update select Department  
create or replace PROCEDURE update_department (d_id in CHAR, newID in STRING, newName in STRING, newPhone in STRING,newEmail in STRING,newContactPerson in STRING, newHeadPerson in STRING, result OUT STRING) 
as 
BEGIN 
    UPDATE department 
    SET department_name = newName, phone_number = newPhone, email = newEmail, contact_person = newContactPerson, head_person = newHeadPerson, department_id = newID      
    WHERE department_id=d_id;
    result:=SQL%rowcount; 
    dbms_output.put_line('The were total of ' || result || ' department updated'); 
 EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The department is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END update_department; 

     
--3. ADD new Department 
create or replace PROCEDURE add_department (d_id in CHAR , newName in STRING, newPhone in STRING, newEmail in STRING, newContactPerson in STRING, newHeadPerson in STRING, newSchoolId in string, result OUT STRING) 
as  
BEGIN 
    INSERT INTO department (department_id, department_name, phone_number, email, contact_person, head_person, school_id) 
    VALUES (d_id, newName, newPhone, newEmail, newContactPerson, newHeadPerson, newSchoolId); 
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted'); 
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END add_department;

--4. View Selected Department  
create or replace PROCEDURE view_department (d_id in CHAR, dep_id out STRING, dep_name out STRING , dep_phone out STRING,  dep_email out STRING , dep_person out STRING , dep_head out STRING, dep_school out STRING, result out string)  
as   
BEGIN  
    SELECT department_id, department_name, phone_number, email, contact_person, head_person, school_id 
    INTO dep_id, dep_name, dep_phone, dep_email, dep_person, dep_head, dep_school 
    FROM department 
    WHERE department_id=d_id;     
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows viewed'); 
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END view_department; 


--SCHOOL Table (Marina’s)
--1.Delete SCHOOL  --working in cpp
create or replace PROCEDURE delete_school (s_id in CHAR, result OUT STRING)
as 
BEGIN
    DELETE FROM school
    WHERE school_id=s_id;
    result :=SQL%rowcount;
    dbms_output.put_line('The were total of ' || result || ' school deleted');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The school is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END delete_school;

--2.Update select SCHOOL --working in cpp
create or replace PROCEDURE update_school (s_id in CHAR, newName in STRING, 
                              newPhoneNumber in STRING, newEmail in STRING, 
                              newContactPerson in STRING, result OUT STRING)
as
BEGIN
    UPDATE school
    SET school_name=newName, phone_number=newPhoneNumber, email=newEmail, contact_person_name=newContactPerson
    WHERE school_id=s_id;
    result :=SQL%rowcount;
    dbms_output.put_line('The were total of ' || result || ' school updated');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        dbms_output.put_line('The school is not found');
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END update_school;

--3.ADD new SCHOOL -working in cpp
create or replace PROCEDURE add_school (s_id in STRING, newName in STRING, newStreetNumber in INTEGER, 
                      newStreetName in STRING, newCity in STRING, newPostalCode in STRING, 
                      newCountry in STRING, newPhone in STRING, newEmail in STRING,
                      newContactPerson in STRING, result out string)
as  
BEGIN 
    INSERT INTO school (school_id, school_name, street_number, street_name, city, postal_code, country, phone_number, email, contact_person_name) 
    VALUES (s_id, newName, newStreetNumber, newStreetName, newCity, newPostalCode, newCountry, newPhone, newEmail, newContactPerson); 
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END add_school; 

--4. View selected school --working in cpp
create or replace PROCEDURE view_school (s_id in STRING, sch_id out STRING, newName out STRING, newStreetNumber out INTEGER, 
                      newStreetName out STRING, newCity out STRING, newPostalCode out STRING, 
                      newCountry out STRING, newPhone out STRING, newEmail out STRING,
                      newContactPerson out STRING, result out string) 
as  
BEGIN 
    SELECT school_id, school_name, street_number, street_name, city, postal_code, country, phone_number, email, contact_person_name
    INTO sch_id, newName, newStreetNumber, newStreetName, newCity, newPostalCode, newCountry, newPhone, newEmail, newContactPerson
    FROM school
    WHERE school_id=s_id;    
    result := SQL%rowcount; 
    dbms_output.put_line('There were a total of  ' || result || ' rows inserted');
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('ERROR occured');
END view_school; 


    
