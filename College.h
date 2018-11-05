/*
 * College.h
 *
 *  Created on: 15/10/2018
 */

#ifndef COLLEGE_H_
#define COLLEGE_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "People.h"

using namespace std;

//PROTOTYPES
class Department;
class Course;
class Uc;
class People;
class Employee;
class Student;
class Teacher;
class Staff;

/**
 * @brief College Class
 */
class College{
	string colName;
    string admin; //For logging in as admin
	vector<Department *> vecDep;
    vector<vector<People*>> people; //1º vec. for teachers, 2º for students, 3º for staff
public:
    /**
     * @brief College Constructor
     * @param name Name of the College
     */
    College(string name);
    College(){}
	//~College(); //class destructor

    vector<vector<People*>> getPeople();
    void addPeople(int i, People* person);

    /**
     * @brief Gets the name of a given College
     * @return String of the name of the College
     */
	string getName();
	/**
	 * @brief Changes the name of a given College
	 * hello
	 * @param name New name of the College
	 */
	void setName(string name);
    void setAdmin(string admin);

    void showInfo();
    vector<Course * > getCourses();

	void showDepartments();
    vector<Department*> getDepartments();
	void addDepartment();
	void removeDepartment();
};


class Department {
   string depName, depAddress;
   Teacher* depDirector;
   int depCode, depPhone;
   vector<Course> vecCourse;
public:
   Department(string name, int code, string address, int phone, Teacher* director); //class constructor
   //~Department();

   void showCourses();
   void showInfo();
   int editInfo();
   void Set(int n);
   string getName();
   void setName(string name);
   string getAddress();
   void setAddress(string address);
   Teacher* getDirector();
   void setDirector(Teacher* director);
   int getCode();
   void setCode(int code);
   int getPhone();
   void setPhone(int phone);
   vector<Course> getCourses();

   void addCourse();
   void removeCourse();
};


class Course{
	string csType, csPtName, csEngName;
	int csCode;
	vector<Uc *> vecUC;
public:
	Course(string type, string engName, string ptName, int code);
	//~Course();

	void showInfo();
	void showSyllabus();
	string getType();
	void setType(string type);
	string getName(); //Returns name in Portuguese
	void setPtName(string ptName);
	string getEngName();
	void setEngName(string engName);
	int getCode();
	void setCode(int code);
	vector<Uc*> getUCs();

	void addUC();
	void removeUC();
	void sortUc();
};


class Uc{
    string ucName;
    vector<Teacher*> ucTeacher; //sendo que o que se encontra na posicao 0 � o regente
    vector<Student*> ucStudent;
    int ucYear, ucECTS, ucWorkload;
public:
	Uc(string name, vector<Teacher*> teacher, vector<Student*> student, int year, int ects, int workload);
	Uc(string name, int year, int ects, int workload);
	//~Uc();

	void showInfo();
	void showStudents();
	void showTeachers();
	string getName();
	void setName(string name);
    int getYear();
    void setYear(int year);
    int getECTS();
    void setECTS(int ects);
	int getWorkload();
	void setWorkload(int workload);
	vector<Teacher*> getTeachers();
	vector<Student*> getStudents();

	//void addTeacher();
	void removeTeacher();
	//void addStudent();
	void removeStudent();

	bool operator<(Uc uc2);

};


//EXCEPTIONS//
//////////////////////
class NoCodeFound{
	int code;
public:
	NoCodeFound(int code){
		this->code = code;
	}
	 //~NoCodeFound() {}
	string errorMessage(){
		return "The code you indicated -" + to_string(code) + "- was not found!";
	};
};

class NoNameFound{
	string name;
public:
	NoNameFound(string name){
		this->name = name;
	}
	 //~NoNameFound() {}
	string errorMessage(){
		return "The name you indicated -" + name + "- was not found!";
	};
};


//TEMPLATES//
//////////////////////
template <class T>
bool remove(vector<T> &vector, string name)
{
	for(unsigned int i = 0; i <= vector.size(); i++)
		{
			if(vector.at(i)->getName() == name)
			{
				vector.erase(vector.begin() + i);
				return true;
			}
		}

	return false;
}

#endif /*COLLEGE_H_*/