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
Assignment: 2 Main.ccp
----------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <occi.h>


using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;


//Takes user input for menu selections and verifyes it
int getIntwithinRange(int min, int max) {
	int selection{};
	char newline{};
	bool done = false;

	do {
		selection = 0;
		cin >> selection;
		if (!cin) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "ERROR: Invalid entry, try again!" << endl;
		}
		else {
			newline = cin.get();
			if (newline != '\n') {
				cout << "ERROR: Non digit character detected, try again" << endl;
				cin.ignore(1000, '\n');
			}else if (selection < min || selection > max) {
				cout << "ERROR: please select number between " << min << " and " << max << endl;
			}
			else {
				done = true;
			}
		}
	} while(!done);

	return selection;
}

//Marina's, Denys's and Majid's helper functions
string getCourseDepartmentProgramSchoolName() {
	string name{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 120;

	while (!done) {
		getline(cin, name, '\n');
		length = name.length();

		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << name << endl;
			done = true;
		}
	}
	return name;
}

string getDepartmentProgramSchoolId() {
	string toSearch;
	bool done = false;
	size_t check = 0;
	size_t length;

	while (!done) {
		getline(cin, toSearch, '\n');
		length = toSearch.length();

		if (length == 3) {
			if (isalpha(toSearch[0]))check++;
			if (isalpha(toSearch[1]))check++;
			if (isalpha(toSearch[2]))check++;

			if (check == 3) {
				done = true;
				std::cout << "Your input: " << toSearch << endl;
			}
		}
		if (!done) {
			std::cout << "Incorrect entry. Try again." << endl;
			std::cout << "Sample id: ABC" << endl;
			cin.clear();
		}
	}
	return toSearch;
}

string getDepartementSchoolPhoneNum() {
	string phoneNum{};
	bool done = false;
	size_t length = 0;
	size_t lengthCorrect = 12;
	char check1 = '.';

	while (!done) {
		getline(cin, phoneNum, '\n');
		length = phoneNum.length();

		if (length !=lengthCorrect) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else if (phoneNum[3] != check1 || phoneNum[7] != check1) {
			cout << "ERROR: Incorrect entry format, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << phoneNum << endl;
			done = true;
		}
	}
	return phoneNum;
}

string getDepartmentSchoolEmail() {
	string email{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 60;
	char check1 = '@';
	char check2 = '.';
	int valid = 0;

	int i = 0;

	while (!done) {
		getline(cin, email, '\n');
		length = email.length();

		valid = 0;

		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			for (i = 0; i < length + 1; i++) {
				if (email[i] == check1) {
					valid++;
				}
				if (email[i] == check2) {
					valid++;
				}
			}
			if (valid == 2) {
				std::cout << "Your input: " << email << endl;
				done = true;
			}
			else {
				cout << "ERROR: Incorrect entry, try again " << endl;
				cin.clear();
			}
		}
	}
	return email;
}

string getDepartmentSchoolContactPerson() {
	string contactPerson{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 60;

	while (!done) {
		getline(cin, contactPerson, '\n');
		length = contactPerson.length();

		if (length<0 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << contactPerson << endl;
			done = true;
		}
		
	}
	return contactPerson;
} //also department head pearson name

string getSchoolCityCountry(){
	string cityCountry{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 60;
	int i;
	int letter = 0;

	while (!done) {
		getline(cin, cityCountry, '\n');
		length = cityCountry.length();

		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			for (i = 0, letter =0; i < length; i++) {
				if(isalpha(cityCountry[i]))letter++;
			}
			if (letter < length) {
				cout << "ERROR: Entry contains non alphabetical character, try again " << endl;
				cin.clear();
			}
			else if (letter == length) {
				std::cout << "Your input: " << cityCountry << endl;
				done = true;
			}
		}
	}
	return cityCountry;
}

string getStudentSchoolPostalCode() {
	string postalCode;
	bool done = false;
	size_t check = 0;
	size_t length;

	while (!done) {
		getline(cin, postalCode, '\n');
		length = postalCode.length();

		if (length == 6) {
			if (isalpha(postalCode[0]))check++;
			if (isdigit(postalCode[1]))check++;
			if (isalpha(postalCode[2]))check++;
			if (isdigit(postalCode[3]))check++;
			if (isalpha(postalCode[4]))check++;
			if (isdigit(postalCode[5]))check++;

			if (check == 6) {
				done = true;
				std::cout << "Your input: " << postalCode << endl;
			}
		}
		if (!done) {
			std::cout << "Incorrect entry. Try again." << endl;
			std::cout << "Sample postal code: A1B2C3" << endl;
			cin.clear();
		}
	}
	return postalCode;
}

string getDepartmenHeadPerson() {
	string headPerson{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 60;


	while (!done) {
		getline(cin, headPerson, '\n');
		length = headPerson.length();

		if (length<0 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << headPerson << endl;
			done = true;
		}

	}
	return headPerson;
}

// Anna's helper functions
string getStudentNewFirstNameStreetNameCityName(){
	string newFirstname{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 30;

	while (!done) {
		getline(cin, newFirstname, '\n');
		length = newFirstname.length();
		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again. Max characters allowed 30 " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << newFirstname << endl;
			done = true;
		}
	}
	return newFirstname;
}

string getStudentNewLastName(){
	string newLastname{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 40;

	while (!done) {
		getline(cin, newLastname, '\n');
		length = newLastname.length();
		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again. Max characters allowed 40" << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << newLastname << endl;
			done = true;
		}
	}
	return newLastname;
}

string getStudentId() {
	string student_id;
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 8;

	while (!done) {
		getline(cin, student_id, '\n');
		length = student_id.length();

		if (length != lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << student_id << endl;
			done = true;
		}
	}
	return student_id;
}

string getStudentPhoneNumber() {
	string phone_number{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 10;

	while (!done) {
		getline(cin, phone_number, '\n');
		length = phone_number.length();

		if (length != lengthMax) {
			cout << "ERROR: Incorrect entry length, try again. Enter phone in the following format: 1112223333 " << endl;
			cin.clear();
		}

		else {
			std::cout << "Your input: " << phone_number << endl;
			done = true;
		}
	}
	return phone_number;
}

string getStudentNewStreetNumberNewRegistrationId()
{
	string newStreetNumber{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 6;

	while (!done) {
		getline(cin, newStreetNumber, '\n');
		length = newStreetNumber.length();

		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again. Max characters allowed are 6. " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << newStreetNumber << endl;
			done = true;
		}
	}
	return newStreetNumber;
}

string getStudentNewDepartmentId()
{
	string newDepartmentId{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 2;

	while (!done) {
		getline(cin, newDepartmentId, '\n');
		length = newDepartmentId.length();

		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			std::cout << "Your input: " << newDepartmentId << endl;
			done = true;
		}
	}
	return newDepartmentId;
}

string getStudentEmail() { //max char 50
	string email{};
	bool done = false;
	size_t length = 0;
	size_t lengthMax = 50;
	char check1 = '@';
	char check2 = '.';
	int valid = 0;
	int i = 0;

	while (!done) {
		getline(cin, email, '\n');
		length = email.length();
		valid = 0;
		if (length < 1 || length > lengthMax) {
			cout << "ERROR: Incorrect entry length, try again " << endl;
			cin.clear();
		}
		else {
			for (i = 0; i < length + 1; i++) {
				if (email[i] == check1) {
					valid++;
				}
				if (email[i] == check2) {
					valid++;
				}
			}
			if (valid == 2) {
				std::cout << "Your input: " << email << endl;
				done = true;
			}
			else {
				cout << "ERROR: Incorrect entry, try again " << endl;
				cin.clear();
			}
		}
	}
	return email;
}


//Anna's CRUD 
void studentCRUDSelection(Statement* stmt, Connection* conn, ResultSet* rs) {
	int operationSelected = 0;
	bool done = false;
	string searchStudentID{};
	string result{};
	string newStudentId{};
	string newPhoneNumber{};
	string newStudentEmail{};
	string newFirstname{};
	string newLastname{};
	string newStreetNumber{};
	string newStreetName{};
	string newCity{};
	string newPostalCode{};
	string newStudentRegistrationId{};
	string newDepartmentId{};

	do {
		cout << "*****************************" << endl;
		cout << "     Student CRUD Menu     " << endl;
		cout << "*****************************" << endl;
		cout << "1. View All Students" << endl;
		cout << "2. View Selected Student " << endl;
		cout << "3. Add new Students" << endl;
		cout << "4. Update existing Students" << endl;
		cout << "5. Delete existing Students" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the operation you would like to perform: " << endl;

		operationSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (operationSelected) {
		case 1:
			//view All Students
			stmt = conn->createStatement();
			rs = stmt->executeQuery("SELECT student_id, first_name, last_name, street_number, street_name, city, postal_code, phone_number, email, student_registration_id, department_id FROM students");
			cout << "----------   ----------  ---------    -------------  -------------    -------------    -----------    ------------    ------------------     ---------------  -------------" << endl;
			cout << "Student ID   First Name  Last Name    Street Number  Street Name      City             Postal Code    Phone Number    Email                  Registration ID  Department ID " << endl;
			cout << "----------   ----------  ---------    -------------  -------------    -------------    -----------    ------------    ------------------     ---------------  -------------" << endl;
			if (rs->next())
			{
				do
				{
					cout << rs->getInt(1) << "     " << std::left << setw(10) << rs->getString(2) << "  " << std::left << std::setw(10) << rs->getString(3) << "   " << std::left << setw(10) << rs->getInt(4) << "     " << std::setw(13) << rs->getString(5) << "    " << std::left << setw(13) << rs->getString(6) << "    " << std::left << setw(10) << rs->getString(7) << "     " << std::left << setw(12) << rs->getString(8) << "    " << std::left << setw(22) << rs->getString(9) << "  " << std::left << setw(14) << rs->getInt(10) << "    " << std::left << setw(13) << rs->getInt(11) << endl;

				} while (rs->next());
				cout << "\n";
			}
			else
			{
				cout << "There is no student information to be displayed." <<
					"\n";
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 2:
			//View Select student
			cout << "View Select student" << endl;
			break;
		case 3:
			//Add new Students
			cout << "Please enter new student id: " << endl;
			newStudentId = getStudentId();
			cout << "Enter new first name: " << endl;
			newFirstname = getStudentNewFirstNameStreetNameCityName();
			cout << "Enter new last name: " << endl;
			newLastname = getStudentNewLastName();
			cout << "Enter new street number: " << endl;
			newStreetNumber = getStudentNewStreetNumberNewRegistrationId();
			cout << "Enter new street name name: " << endl;
			newStreetName = getStudentNewFirstNameStreetNameCityName();
			cout << "Enter new city: " << endl;
			newCity = getStudentNewFirstNameStreetNameCityName();
			cout << "Enter new postal code: " << endl;
			newPostalCode = getStudentSchoolPostalCode();
			cout << "Enter new phone number: " << endl;
			newPhoneNumber = getStudentPhoneNumber();
			cout << "Enter new email: " << endl;
			newStudentEmail = getStudentEmail();
			cout << "Enter new student registration id: " << endl;
			newStudentRegistrationId = getStudentNewStreetNumberNewRegistrationId();
			cout << "Enter new department id: " << endl;
			newDepartmentId = getStudentNewDepartmentId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN insert_student(:1, :2, :3, :4, :5, :6, :7, :8, :9, :10, :11, :12); END;");
			stmt->setString(1, newStudentId);
			stmt->setString(2, newFirstname);
			stmt->setString(3, newLastname);
			stmt->setString(4, newStreetNumber);
			stmt->setString(5, newStreetName);
			stmt->setString(6, newCity);
			stmt->setString(7, newPostalCode);
			stmt->setString(8, newPhoneNumber);
			stmt->setString(9, newStudentEmail);
			stmt->setString(10, newStudentRegistrationId);
			stmt->setString(11, newDepartmentId);
			stmt->registerOutParam(12, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(12);
			cout << "INSERTED " << result << " student" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 4:
			//Update existing Students
			cout << "Please enter the student id you would like to update: " << endl;
			searchStudentID = getStudentId();
			cout << "Enter new student email maximum 60 characters formated xxx@xxx.xxx: " << endl;
			newStudentEmail = getStudentEmail();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN update_student(:1, :2, :3); END;");
			stmt->setString(1, searchStudentID);
			stmt->setString(2, newStudentEmail);
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(3);
			cout << "result" << result << endl;
			cout << "UPDATED " << result << " student" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 5:
			//Delete existing Students
			cout << "Please enter the student id you would like to delete: " << endl;
			searchStudentID = getStudentId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN delete_student(:1, :2); END;");
			stmt->setString(1, searchStudentID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(2);
			cout << "DELETE " << result << " student" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 6:
			cout << "  You have selected to exit the Students table " << endl;
			done = true;
			break;
		}
	} while (!done);
}

//Denys your CRUD goes here
void courseCRUDSelection(Statement* stmt, Connection* conn, ResultSet* rs) {
	int operationSelected = 0;
	bool done = false;
	string searchCourseID{};
	string result{};
	string newCourseID{};
	string newCourseName{};
	string course_id{};
	string course_name{};
	string program_id{};
	string instructor_employee_id{};
	string term_status{};

	do {
		cout << "*****************************" << endl;
		cout << "     Course CRUD Menu     " << endl;
		cout << "*****************************" << endl;
		cout << "1. View All Course" << endl;
		cout << "2. View Selected Course " << endl;
		cout << "3. Add new Course" << endl;
		cout << "4. Update existing Course" << endl;
		cout << "5. Delete existing Course" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the operation you would like to perform: " << endl;

		operationSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (operationSelected) {
		case 1:
			//view All Course
			stmt = conn->createStatement();
			rs = stmt->executeQuery("SELECT course_id, course_name, program_id, instructor_employee_id, term_status FROM course ORDER BY course_id");

			std::cout << "The complete list of course as follows: " << endl;
			std::cout << "Course ID  Course Name Program ID Instructor Employee ID                       Term Status" << endl;

			while (rs->next()) {
				course_id = rs->getString(1);
				course_name = rs->getString(2);
				program_id = rs->getString(3);
				instructor_employee_id = rs->getString(4);
				term_status = rs->getString(5);
				std::cout.width(8);
				std::cout << course_id;
				std::cout << "    ";
				std::cout.width(40);
				std::cout.setf(ios::left);
				std::cout << course_name;
				std::cout << "      ";
				std::cout.width(4);
				std::cout << program_id;
				std::cout << "  ";
				std::cout.width(4);
				std::cout << instructor_employee_id;
				std::cout << "        ";
				std::cout.width(5);
				std::cout << term_status;
				std:cout << "    ";
				//std::cout.width(4);
				std::cout << endl;
				std::cout.unsetf(ios::left);
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 2:
			//View Select Course
			std::cout << "Enter course_id to search: ";
			searchCourseID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN view_course(:1, :2, :3, :4, :5, :6, :7); END;");
			stmt->setString(1, searchCourseID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(course_id));
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(course_name));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(program_id));
			stmt->registerOutParam(5, Type::OCCISTRING, sizeof(instructor_employee_id));
			stmt->registerOutParam(6, Type::OCCISTRING, sizeof(term_status));
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			course_id = stmt->getString(2);
			course_name = stmt->getString(3);
			program_id = stmt->getString(4);
			instructor_employee_id = stmt->getString(5);
			term_status = stmt->getString(6);
			result = stmt->getString(7);
			if (!result.empty()) {
				std::cout << "The number of courses that match the search id are: " << result << endl;
				cout << "Course id: " << course_id << endl;
				cout << "Course name: " << course_name << endl;
				cout << "Program id: " << program_id << endl;
				cout << "Instructor Employee id: " << instructor_employee_id << endl;
				cout << "Term status: " << term_status << endl;
			}
			else {
				std::cout << "No Matches Found" << endl;
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 3:
			//Add new Course
			cout << "Please enter the new course id you would like to add: " << endl;
			newCourseID = getDepartmentProgramSchoolId();
			cout << "Enter new course name maximum 120 characters: " << endl;
			newCourseName = getCourseDepartmentProgramSchoolName();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN add_course(:1, :2, :3); END;");
			stmt->setString(1, newCourseID);
			stmt->setString(2, newCourseName);
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(3);
			cout << "ADDED " << result << " course" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 4:
			//Update existing Course
			cout << "Please enter the course id you would like to update: " << endl;
			searchCourseID = getDepartmentProgramSchoolId();
			cout << "Enter new 3 letter course ID: " << endl;
			newCourseID = getDepartmentProgramSchoolId();
			cout << "Enter new course name maximum 100 characters: " << endl;
			newCourseName = getCourseDepartmentProgramSchoolName();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN update_course(:1, :2, :3, :4); END;");
			stmt->setString(1, searchCourseID);
			stmt->setString(2, newCourseID);
			stmt->setString(3, newCourseName);
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(4);
			cout << "UPDATED " << result << " courses" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 5:
			//Delete existing Course
			cout << "Please enter the course id you would like to delete: " << endl;
			searchCourseID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN delete_course(:1, :2); END;");
			stmt->setString(1, searchCourseID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(2);
			cout << "DELETED " << result << " course" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 6:
			cout << "  You have selected to exit the Students table " << endl;
			done = true;
			break;
		}
	} while (!done);
}

//Marina's CRUD 
void programsCRUDSelection(Statement *stmt, Connection* conn, ResultSet *rs) {
	int operationSelected = 0;
	bool done = false;
	string searchProgramID{};
	string result{};
	string newProgramID{};
	string newProgramName{};
	string program_id{};
	string program_name{};
	string department_id{};

	do {
		cout << "*****************************" << endl;
		cout << "     Programms CRUD Menu     " << endl;
		cout << "*****************************" << endl;
		cout << "1. View All Programs" << endl;
		cout << "2. View Select Program" << endl;
		cout << "3. Add new Program" << endl;
		cout << "4. Update existing Program" << endl;
		cout << "5. Delete existing Program" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the operation you would like to perform: " << endl;

		operationSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (operationSelected) {
		case 1:
			//view All programs
			stmt = conn->createStatement();
			rs = stmt->executeQuery("SELECT program_id, program_name, department_id FROM program ORDER BY program_id");

			std::cout << "The complete list of programs as follows: " << endl;
			std::cout << "Program ID  Program Name                        Department ID" << endl;

			while(rs->next()){
				program_id = rs->getString(1);
				program_name = rs->getString(2);
				department_id = rs->getString(3);
				std::cout.width(8);
				std::cout << program_id;
				std::cout << "    ";
				std::cout.width(40);
				std::cout.setf(ios::left);
				std::cout << program_name;
				std::cout << " ";
				std::cout.width(4);
				std::cout << department_id;
				std::cout << endl;
				std::cout.unsetf(ios::left);
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 2:
			//View Select program
			std::cout << "Enter program_id to search: ";
			searchProgramID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN view_program(:1, :2, :3, :4, :5); END;");
			stmt->setString(1, searchProgramID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(program_id));
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(program_name));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(department_id));
			stmt->registerOutParam(5, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			program_id = stmt->getString(2);
			program_name = stmt->getString(3);
			department_id = stmt->getString(4);
			result = stmt->getString(5);
			if (!result.empty()){
				std::cout << "The number of programs that match the search id are: " << result << endl;
				cout << "Program id: " << program_id << endl;
				cout << "Prorgam name: " << program_name << endl;
				cout << "Department id: " << department_id << endl;
			}
			else {
				std::cout << "No Matches Found" << endl;
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 3:
			//Add new program
			cout << "Please enter the new program id you would like to add: " << endl;
			newProgramID = getDepartmentProgramSchoolId();
			cout << "Enter new program name maximum 120 characters: " << endl;
			newProgramName = getCourseDepartmentProgramSchoolName();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN add_program(:1, :2, :3); END;");
			stmt->setString(1, newProgramID);
			stmt->setString(2, newProgramName);
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(3);
			cout << "ADDED " << result << " program" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 4:
			//Update existing program
			cout << "Please enter the program id you would like to update: " << endl;
			searchProgramID = getDepartmentProgramSchoolId();
			cout << "Enter new 3 letter program ID: " << endl;
			newProgramID = getDepartmentProgramSchoolId();
			cout << "Enter new program name maximum 120 characters: " << endl;
			newProgramName = getCourseDepartmentProgramSchoolName();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN update_program(:1, :2, :3, :4); END;");
			stmt->setString(1, searchProgramID);
			stmt->setString(2, newProgramID);
			stmt->setString(3, newProgramName);
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(4);
			cout << "UPDATED " << result << " programs" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 5:
			//Delete existing program
			cout << "Please enter the program id you would like to delete: " << endl;
			searchProgramID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN delete_program(:1, :2); END;");
			stmt->setString(1, searchProgramID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(2);
			cout << "DELETED " << result << " program" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 6:
			//EXIT
			cout << "  You have selected to exit the Program table " << endl;
			cout << endl;
			done = true;
			break;
		}
	} while (!done);
}

//Majid your CRUD goes here
void departmentCRUDSelection(Statement* stmt, Connection* conn, ResultSet* rs) {
	int operationSelected = 0;
	bool done = false;
	string searchDepartmentID{};
	string result{};
	string department_id{};
	string department_name{};
	string phone_number{};
	string email{};
	string contact_person{};
	string department_head_name{};
	string school_id{};
	string newDepartmentName{};
	string newPhoneNum{};
	string newEmail{};
	string newContactPerson{};
	string newHeadPerson{};

	do {
		cout << "*****************************" << endl;
		cout << "     Department CRUD Menu     " << endl;
		cout << "*****************************" << endl;
		cout << "1. View All Departments" << endl;
		cout << "2. View Selected Department" << endl;
		cout << "3. Add new Department" << endl;
		cout << "4. Update existing Department" << endl;
		cout << "5. Delete existing Department" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the operation you would like to perform: " << endl;

		operationSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (operationSelected) {
		case 1:
			//view All department
			stmt = conn->createStatement();
			rs = stmt->executeQuery("SELECT * FROM department ORDER BY department_id");

			std::cout << "The complete list of departments as follows: " << endl;
			std::cout << "*************  ******************************  **************  ******************************  ***************  ***************  *************" << endl;
			std::cout << "Department ID  Department Name                 Phone Number    Email                           Contact Person   Head Person      School ID    " << endl;
			std::cout << "*************  ******************************  **************  ******************************  ***************  ***************  *************" << endl;

			while (rs->next()) {
				department_id = rs->getString(1);
				department_name = rs->getString(2);
				phone_number = rs->getString(3);
				email = rs->getString(4);
				contact_person = rs->getString(5);
				department_head_name = rs->getString(6);
				school_id = rs->getString(7);
				std::cout.width(13);
				std::cout << department_id;
				std::cout << "  ";
				std::cout.width(30);
				std::cout.setf(ios::left);
				std::cout << department_name;
				std::cout << "  ";
				std::cout.width(14);
				std::cout << phone_number;
				std::cout << "  ";
				std::cout.setf(ios::left);
				std::cout.width(30);
				std::cout << email;
				std::cout << "  ";
				std::cout.unsetf(ios::left);
				std::cout.width(15);
				std::cout << contact_person;
				std::cout << "  ";
				std::cout.unsetf(ios::left);
				std::cout.width(15);
				std::cout << department_head_name;
				std::cout << "  ";
				std::cout.unsetf(ios::left);
				std::cout.width(13);
				std::cout << school_id;
				std::cout << endl;
				std::cout.unsetf(ios::left);
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 2:
			//View Select Department
			std::cout << "Enter department_id to search: ";
			searchDepartmentID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN view_department(:1, :2, :3, :4, :5, :6, :7, :8, :9); END;");
			stmt->setString(1, searchDepartmentID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(department_id));
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(department_name));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(phone_number));
			stmt->registerOutParam(5, Type::OCCISTRING, sizeof(email));
			stmt->registerOutParam(6, Type::OCCISTRING, sizeof(contact_person));
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(department_head_name));
			stmt->registerOutParam(8, Type::OCCISTRING, sizeof(school_id));
			stmt->registerOutParam(9, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			department_id = stmt->getString(2);
			department_name = stmt->getString(3);
			phone_number = stmt->getString(4);
			email = stmt->getString(5);
			contact_person = stmt->getString(6);
			department_head_name = stmt->getString(7);
			school_id = stmt->getString(8);
			result = stmt->getString(9);
			if (!result.empty()) {
				std::cout << "The number of departments that match the search id are: " << result << endl;
				cout << "Department ID: " << department_id << endl;
				cout << "Department Name: " << department_name << endl;
				cout << "Phone Number: " << phone_number << endl;
				cout << "Email: " << email << endl;
				cout << "Contact Person: " << contact_person << endl;
				cout << "Head Person: " << department_head_name << endl;
				cout << "School ID: " << school_id << endl;
			}
			else {
				std::cout << "No Matches Found" << endl;
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 3:
			//Add new department
			cout << "Please enter the new department id you would like to add: " << endl;
			department_id = getDepartmentProgramSchoolId();
			cout << "Enter new department name maximum 120 characters: " << endl;
			newDepartmentName = getCourseDepartmentProgramSchoolName();
			cout << "Enter new department phone number, maximum 12 characters formated xxx.xxx.xxxx: " << endl;
			newPhoneNum = getDepartementSchoolPhoneNum();
			cout << "Enter new department email maximum 60 characters formated xxx@xxx.xxx: " << endl;
			newEmail = getDepartmentSchoolEmail();
			cout << "Enter new department contact person maximum 60 characters: " << endl;
			newContactPerson = getDepartmentSchoolContactPerson();
			cout << "Enter new department head person maximum 60 characters: " << endl;
			newHeadPerson = getDepartmentSchoolContactPerson();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN add_department(:1, :2, :3, :4, :5, :6, :7); END;");
			stmt->setString(1, department_id);
			stmt->setString(2, newDepartmentName);
			stmt->setString(3, newPhoneNum);
			stmt->setString(4, newEmail);
			stmt->setString(5, newContactPerson);
			stmt->setString(6, newHeadPerson);
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(7);
			cout << "ADDED " << result << " Department" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 4:
			//Update existing department
			cout << "Please enter the department id you would like to update: " << endl;
			searchDepartmentID = getDepartmentProgramSchoolId();
			cout << "Enter new department name maximum 120 characters: " << endl;
			newDepartmentName = getCourseDepartmentProgramSchoolName();
			cout << "Enter new department phone number maximum 12 characters formated xxx.xxx.xxxx: " << endl;
			newPhoneNum = getDepartementSchoolPhoneNum();
			cout << "Enter new department email maximum 60 characters formated xxx@xxx.xxx: " << endl;
			newEmail = getDepartmentSchoolEmail();
			cout << "Enter new department contact person maximum 60 characters: " << endl;
			newContactPerson = getDepartmentSchoolContactPerson();
			cout << "Enter new department head person maximum 60 characters: " << endl;
			newHeadPerson = getDepartmenHeadPerson();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN update_department(:1, :2, :3, :4, :5, :6, :7); END;");
			stmt->setString(1, searchDepartmentID);
			stmt->setString(2, newDepartmentName);
			stmt->setString(3, newPhoneNum);
			stmt->setString(4, newEmail);
			stmt->setString(5, newContactPerson);
			stmt->setString(6, newHeadPerson);
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(7);
			cout << "UPDATED " << result << " deprtment" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 5:
			//Delete existing department
			cout << "Please enter the department id you would like to delete: " << endl;
			searchDepartmentID = getDepartmentProgramSchoolId();
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN delete_department(:1, :2); END;");
			stmt->setString(1, searchDepartmentID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(2);
			cout << "DELETED " << result << " Department" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 6:
			cout << "  You have selected to exit the Department table " << endl;
			done = true;
			break;
		}
	} while (!done);

}

//Marina's CRUD 
void schoolCRUDSelection(Statement *stmt, Connection* conn, ResultSet *rs) {
	int operationSelected = 0;
	bool done = false;
	string searchSchoolID{};
	string result{};
	string newSchoolName{};
	string newPhoneNum{};
	string newEmail{};
	string newContactPerson{};
	string school_id{};
	string school_name{};
	int street_number{};
	string street_name{};
	string city{};
	string postal_code{};
	string country{};
	string phone_number{};
	string email{};
	string contact_person_name{};
	string street_numberString{};

	do {
		cout << "*****************************" << endl;
		cout << "     School CRUD Menu     " << endl;
		cout << "*****************************" << endl;
		cout << "1. View All Schools" << endl;
		cout << "2. View Select School" << endl;
		cout << "3. Add new School" << endl;
		cout << "4. Update existing School" << endl;
		cout << "5. Delete existing School" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the operation you would like to perform: " << endl;

		operationSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (operationSelected) {
		case 1:
			//view All school
			stmt = conn->createStatement();
			rs = stmt->executeQuery("SELECT * FROM school ORDER BY school_id");

			std::cout << "The complete list of schools as follows: " << endl;
			std::cout << "School ID  School Name             Street Number Street Name         City       Postal Code  Country   Phone Number  Email                                Contact Person " << endl;

			while (rs->next()) {
				school_id = rs->getString(1);
				school_name = rs->getString(2);
				street_number = rs->getInt(3);
				street_name = rs->getString(4);
				city = rs->getString(5);
				postal_code = rs->getString(6);
				country = rs->getString(7);
				phone_number = rs->getString(8);
				email = rs->getString(9);
				contact_person_name = rs->getString(10);
				std::cout.width(8);
				std::cout << school_id;
				std::cout << "   ";
				std::cout.width(25);
				std::cout.setf(ios::left);
				std::cout << school_name;
				std::cout << " ";
				std::cout.unsetf(ios::left);
				std::cout.setf(ios::right);
				std::cout.width(10);
				std::cout << street_number;
				std::cout << "  ";
				std::cout.unsetf(ios::right);
				std::cout.setf(ios::left);
				std::cout.width(20);
				std::cout << street_name;
				std::cout.width(10);
				std::cout << city;
				std::cout << " ";
				std::cout.unsetf(ios::left);
				std::cout.width(8);
				std::cout << postal_code;
				std::cout << "  ";
				std::cout.width(10);
				std::cout << country;
				std::cout << " ";
				std::cout.width(14);
				std::cout << phone_number;
				std::cout << "  ";
				std::cout.setf(ios::left);
				std::cout.width(30);
				std::cout << email;
				std::cout << " ";
				std::cout.unsetf(ios::left);
				std::cout.width(10);
				std::cout << contact_person_name;
				std::cout << " ";

				std::cout << endl;
				std::cout.unsetf(ios::right);
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 2:
			//View Select School
			std::cout << "Enter school_id to search: ";
			searchSchoolID = getDepartmentProgramSchoolId();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN view_school(:1, :2, :3, :4, :5, :6, :7, :8, :9, :10, :11, :12); END;");
			stmt->setString(1, searchSchoolID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(school_id));
			stmt->registerOutParam(3, Type::OCCISTRING, sizeof(school_name));
			stmt->registerOutParam(4, Type::OCCISTRING, sizeof(street_numberString));
			stmt->registerOutParam(5, Type::OCCISTRING, sizeof(street_name));
			stmt->registerOutParam(6, Type::OCCISTRING, sizeof(city));
			stmt->registerOutParam(7, Type::OCCISTRING, sizeof(postal_code));
			stmt->registerOutParam(8, Type::OCCISTRING, sizeof(country));
			stmt->registerOutParam(9, Type::OCCISTRING, sizeof(phone_number));
			stmt->registerOutParam(10, Type::OCCISTRING, sizeof(email));
			stmt->registerOutParam(11, Type::OCCISTRING, sizeof(contact_person_name));
			stmt->registerOutParam(12, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			school_id = stmt->getString(2);
			school_name = stmt->getString(3);
			street_numberString = stmt->getString(4);
			street_name = stmt->getString(5);
			city = stmt->getString(6);
			postal_code = stmt->getString(7);
			country = stmt->getString(8);
			phone_number = stmt->getString(9);
			email = stmt->getString(10);
			contact_person_name = stmt->getString(11);
			result = stmt->getString(12);
			if (!result.empty()) {
				std::cout << "The number of schools that match the search id are: " << result << endl;
				cout << "School id: " << school_id << endl;
				cout << "School name: " << school_name << endl;
				cout << "Street number: " << street_numberString << endl;
				cout << "Street name: " << street_name << endl;
				cout << "City: " << city << endl;
				cout << "Postal Code: " << postal_code << endl;
				cout << "Country: " << country << endl;
				cout << "Phone Number: " << phone_number << endl;
				cout << "Email: " << email << endl;
				cout << "Contact Person: " << contact_person_name << endl;
			}
			else {
				std::cout << "No Matches Found" << endl;
			}
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 3:
			//Add new school
			cout << "Please enter the new school id you would like to add: " << endl;
			school_id = getDepartmentProgramSchoolId();
			cout << "Enter new school name maximum 120 characters: " << endl;
			newSchoolName = getCourseDepartmentProgramSchoolName();
			cout << "Enter new school street number, maximum number being 99 999: " << endl;
			street_number = getIntwithinRange(1,99999);
			cout << "Enter new school street name, maximum characters 120: " << endl;
			street_name = getCourseDepartmentProgramSchoolName();
			cout << "Enter new school city, maximum characters 60: " << endl;
			city = getSchoolCityCountry();
			cout << "Enter new school postal code, maximum characters 6: " << endl;
			postal_code = getStudentSchoolPostalCode();
			cout << "Enter new school country, maximum characters 60: " << endl;
			country = getSchoolCityCountry();
			cout << "Enter new school phone number, maximum 12 characters formated xxx.xxx.xxxx: " << endl;
			newPhoneNum = getDepartementSchoolPhoneNum();
			cout << "Enter new school email maximum 60 characters formated xxx@xxx.xxx: " << endl;
			newEmail = getDepartmentSchoolEmail();
			cout << "Enter new school contact person maximum 60 characters: " << endl;
			newContactPerson = getDepartmentSchoolContactPerson();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN add_school(:1, :2, :3, :4, :5, :6, :7, :8, :9, :10, :11); END;");
			stmt->setString(1, school_id);
			stmt->setString(2, newSchoolName);
			stmt->setInt(3, street_number);
			stmt->setString(4, street_name);
			stmt->setString(5, city);
			stmt->setString(6, postal_code);
			stmt->setString(7, country);
			stmt->setString(8, newPhoneNum);
			stmt->setString(9, newEmail);
			stmt->setString(10, newContactPerson);
			stmt->registerOutParam(11, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(11);
			cout << "ADDED " << result << " school" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 4:
			//Update existing school
			cout << "UPDATE school" << endl;
			cout << "Please enter the school id you would like to update: " << endl;
			searchSchoolID = getDepartmentProgramSchoolId();
			cout << "Enter new school name maximum 120 characters: " << endl;
			newSchoolName = getCourseDepartmentProgramSchoolName();
			cout << "Enter new school phone number maximum 12 characters formated xxx.xxx.xxxx: " << endl;
			newPhoneNum = getDepartementSchoolPhoneNum();
			cout << "Enter new school email maximum 60 characters formated xxx@xxx.xxx: " << endl;
			newEmail = getDepartmentSchoolEmail();
			cout << "Enter new school contact person maximum 60 characters: " << endl;
			newContactPerson = getDepartmentSchoolContactPerson();
			cout << endl;
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN update_school(:1, :2, :3, :4, :5, :6); END;");
			stmt->setString(1, searchSchoolID);
			stmt->setString(2, newSchoolName);
			stmt->setString(3, newPhoneNum);
			stmt->setString(4, newEmail);
			stmt->setString(5, newContactPerson);
			stmt->registerOutParam(6, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(6);
			cout << "UPDATED " << result << " school" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 5:
			//Delete existing school
			cout << "Please enter the school id you would like to delete: " << endl;
			searchSchoolID = getDepartmentProgramSchoolId();
			stmt = conn->createStatement();
			stmt->setSQL("BEGIN delete_school(:1, :2); END;");
			stmt->setString(1, searchSchoolID);
			stmt->registerOutParam(2, Type::OCCISTRING, sizeof(result));
			stmt->executeUpdate();
			result = stmt->getString(2);
			cout << "DELETED " << result << " school" << endl;
			conn->terminateStatement(stmt);
			cout << endl;
			break;
		case 6:
			//EXIT
			cout << "  You have selected to exit the School table " << endl;
			cout << endl;
			done = true;
			break;
		}
	} while (!done);
}

//Main Menu
void tableSelectionFunctionality(){
	int tableSelected = 0;
	bool done = false;

	Environment* env = nullptr;
	Connection* conn = nullptr;
	Statement* stmt = nullptr;
	ResultSet* rs = nullptr;

	// User Variables
	string strMarina;
	string usrMarina = "dbs311_221f12"; //this is your login assigned to you
	string passMarina = "11591122"; //this is your password assigned to you
	string srvMarina = "myoracle12c.senecacollege.ca:1521/oracle12c";

	// Anna Variables
	string strAnna;
	string usrAnna = "dbs311_221f03";
	string passAnna = "99112711";
	string srvAnna = "myoracle12c.senecacollege.ca:1521/oracle12c";

	// Denys Variables
	string strDenys;
	string usrDenys = "dbs311_221f23"; //this is your login assigned to you
	string passDenys = "45213146"; //this is your password assigned to you
	string srvDenys = "myoracle12c.senecacollege.ca:1521/oracle12c";

	// Majid Variables
	string strMajid;
	string usrMajid = "dbs311_221f05"; //this is your login assigned to you
	string passMajid = "31879141"; //this is your password assigned to you
	string srvMajid = "myoracle12c.senecacollege.ca:1521/oracle12c";

	do {
		cout << "*****************************" << endl;
		cout << "        Main Menu            " << endl;
		cout << "*****************************" << endl;
		cout << "1. Student" << endl;
		cout << "2. Course" << endl;
		cout << "3. Program" << endl;
		cout << "4. Department" << endl;
		cout << "5. School" << endl;
		cout << "6. Exit" << endl;
		cout << "*****************************" << endl;
		cout << "Please select the table you would like to work on: " << endl;

		tableSelected = getIntwithinRange(1, 6);
		cout << endl;

		switch (tableSelected) {
		case 1: {
			try {
				//load Anna's database connection
				env = Environment::createEnvironment(Environment::DEFAULT);
				conn = env->createConnection(usrAnna, passAnna, srvAnna);
				std::cout << "Connection is Successful! Group3 Anna Alexeeva  is Connected" << endl;
				cout << endl;

				//load CRUD menu for course
				studentCRUDSelection(stmt, conn, rs);

				//Terminating connection
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
			}
			catch (SQLException& sqlExcp) {
				std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
			break;
		case 2: {
			try {
				//load Denys's database connection
				env = Environment::createEnvironment(Environment::DEFAULT);
				conn = env->createConnection(usrDenys, passDenys, srvDenys);
				std::cout << "Connection is Successful! Group3 Denys's is Connected" << endl;
				cout << endl;

				//load CRUD menu for course
				courseCRUDSelection(stmt, conn, rs);

				//Terminating connection
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
			}
			catch (SQLException& sqlExcp) {
				std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
			break;
		case 3: {
			try {
				//load Marina's database connection
				env = Environment::createEnvironment(Environment::DEFAULT);
				conn = env->createConnection(usrMarina, passMarina, srvMarina);
				std::cout << "Connection is Successful! Group3 Marina Fiamskaia is Connected" << endl;
				cout << endl;

				//load CRUD menu for programs
				programsCRUDSelection(stmt, conn, rs);

				//Terminating connection
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
			}
			catch (SQLException& sqlExcp) {
				std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
			  break;
		case 4: {
			try {
				//load Majid's database connection
				env = Environment::createEnvironment(Environment::DEFAULT);
				conn = env->createConnection(usrMajid, passMajid, srvMajid);
				std::cout << "Connection is Successful! Group3 Majid is Connected" << endl;
				cout << endl;

				//load CRUD menu for course
				departmentCRUDSelection(stmt, conn, rs);

				//Terminating connection
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
			}
			catch (SQLException& sqlExcp) {
				std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
			break;
		case 5:
		{
			try {
				//load Marina's database connection
				env = Environment::createEnvironment(Environment::DEFAULT);
				conn = env->createConnection(usrMarina, passMarina, srvMarina);
				std::cout << "Connection is Successful! Group3 Marina Fiamskaia is Connected" << endl;
				cout << endl;

				//load CRUD menu for programs
				schoolCRUDSelection(stmt, conn, rs);

				//Terminating connection
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
			}
			catch (SQLException& sqlExcp) {
				std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}
		}
			break;
		case 6: {
			cout << "  You have selected to exit the program " << endl;
			cout << "         Goodbye!!!!!!!" << endl;
			done = true;
		}
			break;
		}
	} while (!done);
}


int main(void) {

	tableSelectionFunctionality();

	return 0;
}