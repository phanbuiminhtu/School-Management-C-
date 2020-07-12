#include <iostream>
#include <string>
#include <vector>
#include "Student.cpp"
#include "Teacher.cpp"

using std::cout;
using std::cin;
using std::string;
int ID = 1;
template <class T>
void findProfileByName(std::vector<T> vect, string name){
	for (int i = 0; i <= vect.size(); i++){
		if(vect[i].getName() == name){
			vect[i].str();
			break;
		}
		if(i == vect.size()){
			cout << "Profile not found.";
		}
	}
}
template <class T>
void findProfileByID(std::vector<T> vect, int ID){
	for (int i = 0; i <= vect.size(); i++){
		if(vect[i].getID() == ID){
			vect[i].str();
			break;
		}
		if(i == vect.size()){
			cout << "Profile not found.";
		}
	}
}
int main() {
	int user_choice;
	int second_choice;
	int third_choice;
	std::vector<Student> student_list;
	std::vector<Teacher> teacher_list;
	do{
		cout << "Enter your choice.\n1. Student information\n2. Teacher information\n3. Exit the program\n";
		cin >> user_choice;
		if(user_choice == 1){
			do{
				cout << "Enter your choice.\n1. New student's profile\n2. Show student's profile\n3. Go back to main page\n";
				cin >> second_choice;
				if(second_choice == 1){
					string name;
					int age;
					int yearGraduate;
					string mayjor;
					cout << "Enter student's name: ";
					cin >> name;
					cout << "Enter student's age: ";
					cin >> age;
					cout << "Enter student's year of graduation: ";
					cin >> yearGraduate;
					cout << "Enter student's mayjor: ";
					cin >> mayjor;
					cout <<"\n";
					Student newStudent(name,ID,age,yearGraduate,mayjor);
					newStudent.increaseID(ID);
					student_list.push_back(newStudent);
				}
				else if(second_choice == 2){
					cout << "Enter your choice:\n1. Search By name\n2. Search by ID\n";
					cin >> third_choice;
					if (third_choice == 1){
						string name;
						cout << "Enter student's name: ";
						cin >> name;
						findProfileByName(student_list, name);
					}	
					else if (third_choice == 2){
						int student_ID;
						cout << "Enter student's ID: ";
						cin >> student_ID;
						findProfileByID(student_list, student_ID);
					}
				}
			}while(second_choice != 3);
		}
		
		else if(user_choice == 2){
			do{
				cout << "Enter your choice.\n1. New teacher's profile\n2. Show teacher's profile\n3. Go back to main page\n";
				cin >> second_choice;
				if(second_choice == 1){
					string name;
					int age;
					int yearInOffice;
					string position;
					cout << "Enter teacher's name: ";
					cin >> name;
					cout << "Enter teacher's age: ";
					cin >> age;
					cout << "Enter teacher's position: ";
					cin >> position;
					cout << "Enter teacher's number year in office: ";
					cin >> yearInOffice;
					cout << "\n";
					Teacher newTeacher(name,ID,age,position,yearInOffice);
					newTeacher.increaseID(ID);
					teacher_list.push_back(newTeacher);
				}
				else if(second_choice == 2){
					cout << "Enter your choice:\n1. Search By name\n2. Search by ID\n";
					cin >> third_choice;
					if(third_choice==1){
						string name;
						cout << "Enter teacher's name: ";
						cin >> name;
						findProfileByName(teacher_list, name);
					}
					else if (third_choice == 2){
						int teacher_ID;
						cout << "Enter teacher's ID: ";
						cin >> teacher_ID;
						findProfileByID(teacher_list, teacher_ID);
					}
				}
			}while(second_choice != 3);
		}
	}while(user_choice != 3);
}
