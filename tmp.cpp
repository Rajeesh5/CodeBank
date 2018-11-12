#include<iostream>
#include<list>

using namespace std;


class Student
{
	string name;
	int rollNum;
	list<Teacher> lstOfTechers;
public:
	Student(const string &nm):name(nm){}
	void setAssociatedTeachers(list<Teacher> lstOfTeacher) {
		this->lstOfTechers = lstOfTeacher;
	}

};

class Teacher
{
	string name;
	int TechId;
	list<Student> lstOfStudent;
public:
	Teacher(const string &nm):name(nm){}
};


class Department {

	string  name;
	list<Teacher> teacherWithInDept;
public:
	
	Department(const string &nm):name(nm){}
	void setAssociatedTeachers(list<Teacher> lstOfTeacher) {
		this->teacherWithInDept = lstOfTeacher;
	}

};

class University
{
	string name;
	list<Department> listofDepts;
public:
	University(const string nm):name(nm){}

	void createDepartments() {
		Department dept1("CS");
		Department dept2("Electronics");
		Department dept3("Machanics");

		listofDepts.push_back(dept1);
		listofDepts.push_back(dept2);
		listofDepts.push_back(dept3);
	}

};

int main()
{
	Student student1("Rajeev");	//Assume appropriate constructor is available.
	list<Teacher> teachersList;

	Teacher teacher1("Vinaa");
	Teacher teacher2("Partha");

	teachersList.push_back(teacher1);
	teachersList.push_back(teacher2);

	student1.setAssociatedTeachers(teachersList);

	//We can reverse the relation ship as well. multiple student can associated 
	//with same teacher also.

	Department dept1("CS");
	dept1.setAssociatedTeachers(teachersList);    
	
	University uni1("BIT");
	uni1.createDepartments();
}
