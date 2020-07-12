#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;

class Student{
	string name;
	int ID;
	int age;
	int yearGraduate;
	string mayjor;
	public:
		Student(string name,int ID,int age, int yearGraduate, string mayjor){
			this->name = name;
			this->ID = ID;
			this->age = age;
			this->yearGraduate = yearGraduate;
			this->mayjor = mayjor; 
		}
		void changeName(string name){
			this->name = name;
		}
		void changeAge(int age){
			this->age = age;
		}
		void changeYear(int year){
			this->yearGraduate = year;
		}
		void changeMajor(string mayjor){
			this->mayjor = mayjor;
		}
		void str(){
			cout << "Student's name: "<<this->name<<"\n";
			cout << "Student's ID: "<<this->ID<<"\n";
			cout << "Student's age: "<<this->age<<"\n";
			cout << "Student's year of graduation: "<<this->yearGraduate<<"\n"; 
			cout << "Student's mayjor: "<<this->mayjor<<"\n";
			cout << "\n";
		}
		void increaseID(int &IDs){
			IDs++;
		}
		string getName(){
			return this->name;
		}
		int getID(){
			return this->ID;
		}
};

