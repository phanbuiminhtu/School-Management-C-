#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;

class Teacher{
	string name;
	int ID;
	int age;
	string position;
	int numberYearEmployeed;
	public:
		Teacher(string name, int ID, int age, string position, int numberYearEmployeed){
			this->name = name;
			this->ID = ID;
			this->age = age;
			this->position = position;
			this->numberYearEmployeed = numberYearEmployeed;
		}
		void changeName(string name){
			this->name = name;
		}
		void changeAge(int age){
			this->age = age;
		}
		void changePosition(string position){
			this->position = position;
		}
		void changeYear(int year){
			this->numberYearEmployeed = year;
		}
		void str(){
			cout << "Teacher's name: "<<this->name<<"\n";
			cout << "Teacher's ID: "<<this->ID<<"\n";
			cout << "Teacher's age: "<<this->age<<"\n";
			cout << "Teacher's position: "<<this->position<<"\n";
			cout << "Teacher's year in office: "<<this->numberYearEmployeed<<"\n";
			cout <<"\n";
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