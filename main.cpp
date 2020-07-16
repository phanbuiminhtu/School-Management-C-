#include <iostream>
#include <string>
#include <vector>
#include "Student.cpp"
#include "Teacher.cpp"
#include "BST.cpp"

using std::cout;
using std::cin;
using std::string;
int student_IDs_list = 1000;
int teacher_IDs_list= 2000;
int studentID_array[1000];
string studentName_array[1000];
int teacherID_array[1000];
string teacherName_array[1000];
int i = 0;
int j = 0;

int searchArray(string name, string arr[]){
	int size = 1000;
	for (int i = 0; i <= size; i++){
		if(arr[i] == name){
			return i;
		}
	}
	return -1;
}

int main() {
	int user_choice;
	int second_choice;
	int third_choice;
	BST<Student> student_tree;
	BST<Teacher> teacher_tree;
	do{
		cout << "Enter your choice.\n1. Student information\n2. Teacher information\n3. Exit the program\n";
		cin >> user_choice;
		if(user_choice == 1){
			do{
				cout << "Enter your choice.\n1. New student's profile\n2. Show student's profile\n3. Delete student profile\n4. change student information\n5. Go back to main page\n";
				cin >> second_choice;
				if(second_choice == 1){//add new student
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
					Student *newStudent = new Student(name,student_IDs_list,age,yearGraduate,mayjor);
					studentID_array[i] = student_IDs_list;
					studentName_array[i] = name;
					newStudent->increaseID(student_IDs_list);
					i++;
					Node<Student> *node = new Node<Student> (newStudent);
					student_tree.addNode(node);
					
				}
				else if(second_choice == 2){//show student profile
					cout << "Enter your choice:\n1. Search By name\n2. Search by ID\n";
					cin >> third_choice;
					if (third_choice == 1){
						string name;
						cout << "Enter student's name: ";
						cin >> name;
						int student_ID = studentID_array[searchArray(name, studentName_array)];
						if(student_ID >= 0){
							Node<Student> *student_profile = student_tree.searchNode(student_ID);
							if(student_profile != NULL){
								student_profile->data->str();
							}
							else{
								cout << "Profile not found.";
							}
						}
						else{
							cout << "Profile not found.";
						}
					}	
					else if (third_choice == 2){
						int student_ID;
						cout << "Enter student's ID: ";
						cin >> student_ID;
						Node<Student> *student_profile = student_tree.searchNode(student_ID);
						if(student_profile != NULL){
							student_profile->data->str();
						}
						else{
							cout << "Profile not found.";
						}
						cout <<"\n";
					}
				}
				else if(second_choice == 3){
					int student_ID;
					cout << "Enter student ID: ";
					cin >> student_ID;
					student_tree.removeNode(student_ID);
					cout << "Profile has been remove.\n";
				}
				else if(second_choice == 4){
					int student_ID;
					int fourth_choice;
					string new_name;
					int new_age;
					string new_mayjor;
					int new_year;
					cout << "Enter student ID: ";
					cin >> student_ID;
					do{
						cout << "1. Change Name\n2. Change Age\n3. Change mayjor\n4. Change year graduate\n5. exit\n";
						cin >> fourth_choice;
						if(fourth_choice == 1){
							cout <<"Enter new name: ";
							cin >> new_name;
							student_tree.searchNode(student_ID)->data->changeName(new_name);
						}
						else if(fourth_choice == 2){
							cout <<"Enter new age: ";
							cin >> new_age;
							student_tree.searchNode(student_ID)->data->changeAge(new_age);
						}
						else if(fourth_choice == 3){
							cout << "Enter new mayjor: ";
							cin >> new_mayjor;
							student_tree.searchNode(student_ID)->data->changeMajor(new_mayjor);
						}
						else if(fourth_choice == 4){
							cout <<"Enter new year: ";
							cin >> new_year;
							student_tree.searchNode(student_ID)->data->changeYear(new_year);
						}
						else{
							cout << "Choose again.";
						}
						
					}while(fourth_choice !=5);
				}
			}while(second_choice != 5);
		}
		else if(user_choice == 2){
			do{
				cout << "Enter your choice.\n1. New teacher's profile\n2. Show teacher's profile\n3. Delete teacher profile\n4. Change teacher's information\n5. Go back to main page\n";
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
					Teacher *newTeacher = new Teacher(name,teacher_IDs_list,age,position,yearInOffice);
					teacherID_array[j] = teacher_IDs_list;
					teacherName_array[j] = name;
					newTeacher->increaseID(teacher_IDs_list);
					j++;
					Node<Teacher> *node = new Node<Teacher>(newTeacher);
					teacher_tree.addNode(node);
				}
				else if(second_choice == 2){//add new teacher
					cout << "Enter your choice:\n1. Search By name\n2. Search by ID\n";
					cin >> third_choice;
					if(third_choice==1){
						string name;
						cout << "Enter teacher's name: ";
						cin >> name;
						int teacher_ID =teacherID_array[searchArray(name, teacherName_array)];
						if(teacher_ID >= 0){
							Node<Teacher> *teacher_profile = teacher_tree.searchNode(teacher_ID);
							if(teacher_profile != NULL){
								teacher_profile->data->str();
							}
							else{
								cout << "Profile not found.\n";
							}
						}
						else{
							cout << "Profile not found.\n";
						}
					}
					else if (third_choice == 2){
						int teacher_ID;
						cout << "Enter teacher's ID: ";
						cin >> teacher_ID;
						Node<Teacher> *teacher_profile = teacher_tree.searchNode(teacher_ID);
						if(teacher_profile != NULL){
							teacher_profile->data->str();
						}
						else{
							cout << "Profile not found.\n";
						}
						cout <<"\n";
					}
				}
				else if(second_choice == 3){
					int teacher_ID;
					cout << "Enter teacher ID: ";
					cin >> teacher_ID;
					teacher_tree.removeNode(teacher_ID);
					cout << "Profile has been remove.\n";
				}
				else if(second_choice == 4){
					int teacher_ID;
					int fourth_choice;
					string new_name;
					int new_age;
					string new_pos;
					int new_year;
					cout << "Enter teacher ID: ";
					cin >> teacher_ID;
					do{
						cout << "1. Change Name\n2. Change Age\n3. Change position\n4. Change number of year employed\n5. exit\n";
						cin >> fourth_choice;
						if(fourth_choice == 1){
							cout <<"Enter new name: ";
							cin >> new_name;
							teacher_tree.searchNode(teacher_ID)->data->changeName(new_name);
						}
						else if(fourth_choice == 2){
							cout <<"Enter new age: ";
							cin >> new_age;
							teacher_tree.searchNode(teacher_ID)->data->changeAge(new_age);
						}
						else if(fourth_choice == 3){
							cout << "Enter new position: ";
							cin >> new_pos;
							teacher_tree.searchNode(teacher_ID)->data->changePosition(new_pos);
						}
						else if(fourth_choice == 4){
							cout <<"Enter new number of year: ";
							cin >> new_year;
							teacher_tree.searchNode(teacher_ID)->data->changeYear(new_year);
						}
						else{
							cout << "Choose again.";
						}
						
					}while(fourth_choice !=5);
				}
			}while(second_choice != 5);
		}
	}while(user_choice != 3);
}
