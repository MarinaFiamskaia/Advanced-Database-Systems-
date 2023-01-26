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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>
#include <occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;



string getCourseId(){
	string toSearch;
	bool done = false;
	size_t check = 0;
	size_t length;

	while(!done){
		getline(cin, toSearch, '\n');
		length = toSearch.length();

		if(length==9){
			if(isalpha(toSearch[0]))check++;
			if(isalpha(toSearch[1]))check++;
			if(isalpha(toSearch[2]))check++;
			if(isdigit(toSearch[3]))check++;
			if(isdigit(toSearch[4]))check++;
			if(isdigit(toSearch[5]))check++;
			if(isalpha(toSearch[6]))check++;
			if(isalpha(toSearch[7]))check++;
			if(isalpha(toSearch[8]))check++;
			if(check == 9){
				done = true;
				std::cout << "Your input: " << toSearch << endl;
			}
		}
		if(!done){
			std::cout << "Incorrect entry. Try again." << endl;
			std::cout << "Sample course id: ABC123DEF" << endl;
		}
	}
	return toSearch;
}

string getProgramSchoolId(){
	string toSearch;
	bool done = false;
	size_t check = 0;
	size_t length;

	while(!done){
		getline(cin, toSearch, '\n');
		length = toSearch.length();

		if(length == 3){
			if(isalpha(toSearch[0]))check++;
			if(isalpha(toSearch[1]))check++;
			if(isalpha(toSearch[2]))check++;

			if(check == 3){
				done = true;
				std::cout << "Your input: " << toSearch << endl;
			}
		}
		if(!done){
			std::cout << "Incorrect entry. Try again." << endl;
			std::cout << "Sample id: ABC" << endl;
			cin.clear();
		}
	}
	return toSearch;
}


int main(void) {
	// OCCI  Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	Statement* stmt = nullptr;
	ResultSet* rs = nullptr;

	// User Variables
	string str;
	string usr = "dbs311_221f12"; //this is your login assigned to you
	string pass = "11591122"; //this is your password assigned to you
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try {
		//Establlishing connection
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		std::cout << "Connection is Successful! Marina Fiamskaia Group3 is Connected" << endl;

		//---------Course Table Data Retrieval------------------
		stmt = conn->createStatement();
		rs = stmt->executeQuery("SELECT course_id, course_name, program_id, instructor_employee_id, term_status FROM course ORDER BY course_id");

		std::cout << "The complete list of courses as follows: " << endl;
		std::cout << " Course ID Course Name                                     Program ID   Instructor ID     Term Status" << endl;

		while (rs->next()){
			string course_id = rs->getString(1);
			string course_name = rs->getString(2);
			string program_id = rs->getString(3);
			string instructor_employee_id = rs->getString(4);
			string term_status = rs->getString(5);
			std::cout.width(10);
			std::cout << course_id;
			std::cout << " ";
			std::cout.width(50);
			std::cout.setf(ios::left);
			std::cout << course_name;
			std::cout << " ";
			std::cout.unsetf(ios::left);
			std::cout.width(4);
			std::cout << program_id;
			std::cout << " ";
			std::cout.width(15);
			std::cout.setf(ios::right);
			std::cout << instructor_employee_id;
			std::cout << " ";
			std::cout.unsetf(ios::right);
			std::cout.width(15);
			std::cout << term_status;
			std::cout << " ";
			std::cout << endl;
			std::cout.unsetf(ios::right);
		}
		std::cout << endl;
		conn->terminateStatement(stmt);

		//---------Course Table using WHERE clause for the course_id
		std::cout << "Enter search course_id: ";
		string searchCourse_id = getCourseId();

		stmt = conn->createStatement("SELECT course_id, course_name, program_id, instructor_employee_id, term_status FROM course WHERE course_id= :1");
		stmt->setString(1, searchCourse_id);
		rs = stmt->executeQuery();

		if (rs->next()){
			std::cout << "The list of courses that match the search are: " << endl;
			std::cout << " Course ID Course Name                                     Program ID   Instructor ID     Term Status" << endl;

				string course_id = rs->getString(1);
				string course_name = rs->getString(2);
				string program_id = rs->getString(3);
				string instructor_employee_id = rs->getString(4);
				string term_status = rs->getString(5);
				std::cout.width(10);
				std::cout << course_id;
				std::cout << " ";
				std::cout.width(50);
				std::cout.setf(ios::left);
				std::cout << course_name;
				std::cout << " ";
				std::cout.unsetf(ios::left);
				std::cout.width(4);
				std::cout << program_id;
				std::cout << " ";
				std::cout.width(15);
				std::cout.setf(ios::right);
				std::cout << instructor_employee_id;
				std::cout << " ";
				std::cout.unsetf(ios::right);
				std::cout.width(15);
				std::cout << term_status;
				std::cout << " ";
				std::cout << endl;
				std::cout.unsetf(ios::right);

		}
		else{
			std::cout << "No Matches Found" << endl;
		}
		conn->terminateStatement(stmt);

		//---------Program Table Data Retrieval------------------
		stmt = conn->createStatement();
		rs = stmt->executeQuery("SELECT program_id, program_name, department_id FROM program ORDER BY program_id");

		std::cout << "The complete list of programs as follows: " << endl;
		std::cout << "Program ID  Program Name                        Department ID" << endl;

		while (rs->next()){
			string program_id = rs->getString(1);
			string program_name = rs->getString(2);
			string department_id = rs->getString(3);
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

		//---------Program Table using WHERE clause for the program_id
		std::cout << "Enter search program_id: ";
		string searchProgram_id = getProgramSchoolId();

		stmt = conn->createStatement("SELECT program_id, program_name, department_id FROM program WHERE program_id = :1");
		stmt->setString(1, searchProgram_id);
		rs = stmt->executeQuery();

		if (rs->next()){
			std::cout << "The list of programs that match the search are: " << endl;
			std::cout << "Program ID  Program Name                        Department ID" << endl;

			string program_id = rs->getString(1);
			string program_name = rs->getString(2);
			string department_id = rs->getString(3);
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
		else{
			std::cout << "No Matches Found" << endl;
		}
		conn->terminateStatement(stmt);

		//---------School Table Data Retrieval------------------
		stmt = conn->createStatement();
		rs = stmt->executeQuery("SELECT * FROM school ORDER BY school_id");
		std::cout << "statement executed" << endl;

		std::cout << "The complete list of schools as follows: " << endl;
		std::cout << "School ID  School Name             Street Number Street Name         City       Postal Code  Country   Phone Number  Email                                Contact Person " << endl;

		while(rs->next()){
			string school_id = rs->getString(1);
			string school_name = rs->getString(2);
			int street_number = rs->getInt(3);
			string street_name = rs->getString(4);
			string city = rs->getString(5);
			string postal_code = rs->getString(6);
			string country = rs->getString(7);
			string phone_number = rs->getString(8);
			string email = rs->getString(9);
			string contact_person_name = rs->getString(10);
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

		//---------School Table using WHERE clause for the school_id
		std::cout << "Enter search school_id: ";
		string searchSchool_id = getProgramSchoolId();

		stmt = conn->createStatement("SELECT * FROM school WHERE school_id = :1");
		stmt->setString(1, searchSchool_id);
		rs = stmt->executeQuery();

		if(rs->next()){
			std::cout << "The list of schools that match the search are: " << endl;
			std::cout << "School ID  School Name             Street Number Street Name         City       Postal Code  Country   Phone Number  Email                                Contact Person " << endl;

			string school_id = rs->getString(1);
			string school_name = rs->getString(2);
			int street_number = rs->getInt(3);
			string street_name = rs->getString(4);
			string city = rs->getString(5);
			string postal_code = rs->getString(6);
			string country = rs->getString(7);
			string phone_number = rs->getString(8);
			string email = rs->getString(9);
			string contact_person_name = rs->getString(10);
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
		else{
			std::cout << "No Matches Found" << endl;
		}
		conn->terminateStatement(stmt);

		//Terminating connection
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		std::cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}