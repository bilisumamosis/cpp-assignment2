#include <iostream>
#include <stdlib.h>
using namespace std;


// keeps track of the number of students
int n = 0;


struct student
{
	// input data
	string name, UID, grade;
	float midResult, finalResult, assignmentResult, labResult;
	
	// calculated data
	float sum, GPA;
};


// allocating some memory for the students

student students [30];





char inputUserDecision() {
	char userDecision;
	cout << "Press:" << endl << "'i' if you want to input student data" << endl << "'s' if you want to display a student's data using his/her ID" << endl << "'a' if you want to display all students' information" << endl << "'q' if you want to quit the program" << endl;
	cin >> userDecision;
	return userDecision;
}


bool isUserDecisionValid(char userDecision) {
	if (userDecision == 'i' || userDecision == 'a' || userDecision == 's' || userDecision == 'q')
		return true;
	else 
		return false;

	
}

string calcGrade(int sum)
{
	if(sum>=40) {
    	if(sum>=40&&sum<50) 
			return "D";
			
      	else if(sum>=50&&sum<55) 
				return "C-";
		
      	else if(sum>=55&&sum<60) 
				return "C";
		
      	else if(sum>=60&&sum<65) 
			return "C+";
		
	  		
      	else if(sum>=65&&sum<70) 
			return "B-";
		
	  		
      	else if(sum>=70&&sum<75) 
			return "B";
		
	  		
      	else if(sum>=75&&sum<80) 
			return "B+";
		
	  		
      	else if(sum>=80&&sum<85) 
			return "A-";
		
			
      	else if(sum>=85&&sum<90) 
			return "A";
		
	  		
      	else 
			return "A+";
		
	}
	  	 	

    else {
		 return "F";
	}
           	   	   
        
}


// using the calculated grade as an input, it calculates the GPA

float calcGPA(string grade) {
	if (grade == "D") 
		return 1.5;
	else if (grade == "C-")
		return 1.75;
	else if (grade == "C")
		return 2.0;
	else if (grade == "C+")
		return 2.5;
	else if (grade == "B-")
		return 2.75;
	else if (grade == "B")
		return 3.0;
	else if (grade == "B+")
		return 3.5;
	else if (grade == "A-")
		return 3.75;
	else if (grade == "A" || grade == "A+")
		return 4.0;
	else 
		return 0; 
}


void inputStudents() {
		cout << "Input name" << endl;
		cin >> students[n].name;
		cout << "Input UID" << endl;
		cin >> students[n].UID;
		cout << "Input final result" << endl;
		cin >> students[n].finalResult;
		
		while (students[n].finalResult > 50 || students[n].finalResult < 0) {
			cout << "Please input a final result that is between 50 and 0" << endl;
			cin >> students[n].finalResult;
		}
		
		cout << "Input mid Result" << endl;
		cin >> students[n].midResult;
		
		while (students[n].midResult > 25 || students[n].midResult < 0) {
			cout << "Please input a mid result that is between 25 and 0" << endl;
			cin >> students[n].midResult;
		}
		cout << "Input assignment result" << endl;
		cin >> students[n].assignmentResult;
		
		while (students[n].assignmentResult > 10 || students[n].assignmentResult < 0) {
			cout << "Please input a assignment result that is between 10 and 0" << endl;
			cin >> students[n].assignmentResult;
		}
		
		cout << "Input lab result" << endl;
		cin >> students[n].labResult;
		
		while (students[n].labResult > 15 || students[n].labResult < 0) {
			cout << "Please input a lab result that is between 15 and 0" << endl;
			cin >> students[n].labResult;
		}
		
		// doing the calculations
		
		students[n].sum = students[n].midResult + students[n].finalResult + students[n].assignmentResult + students[n].labResult;
		students[n].grade = calcGrade(students[n].sum);
		students[n].GPA = calcGPA(students[n].grade);
		
		// adding one more student to the list
		n++;
		
		// checks if the user wants to keep inputing
		char keepInputing;
		cout << "Do you want to keep inputing student data or do you want to return to the menu?" << endl << "Press 'y' if you want to keep inputing, press any key if you want to return to the menu" << endl;
		cin >> keepInputing;
		if (keepInputing == 'y') {
			inputStudents();
		}
		
	
			
}

void displayAllStudents(student students[]) {
	if (n != 0) {
		for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "UID: " << students[i].UID << endl;
		cout << "Name: " << students[i].name << endl;
		cout << "Mid Result: " << students[i].midResult << endl;
		cout << "Final Result: " << students[i].finalResult << endl;
		cout << "Assignment Result: " << students[i].assignmentResult << endl;
		cout << "Lab Assignment Result: " << students[i].labResult << endl;
		cout << "Out of 100%: " << students[i].sum << endl;
		cout << "Grade: " << students[i].grade << endl;
		cout << "GPA: " << students[i].GPA << endl;
		cout << endl;
	}
	} else 
		cout << "Sorry, there are no students. You haven't inputted any student data yet." << endl; 
	
}

void displayAStudent(student students[]) {
	if (n != 0) {
	
	cout << "Input a UID of the student you want to find" << endl;
		string inputUID;
		cin >> inputUID;
		
		for (int i = 0; i < n; i++) {
			// finding the specific student
			if (students[i].UID == inputUID) {
				cout << endl;
				cout << "UID: " << students[i].UID << endl;
				cout << "Name: " << students[i].name << endl;
				cout << "Mid Result: " << students[i].midResult << endl;
				cout << "Final Result: " << students[i].finalResult << endl;
				cout << "Assignment Result: " << students[i].assignmentResult << endl;
				cout << "Lab Assignment Result: " << students[i].labResult << endl;
				cout << "Out of 100%: " << students[i].sum << endl;
				cout << "Grade: " << students[i].grade << endl;
				cout << "GPA: " << students[i].GPA << endl;
				cout << endl;
				break; // to save memory
			} 
			else {
				cout << "Sorry, could't find a student with this UID" << endl << "Do you want to try agian?" << "Press 'y' if you want to try again, press any key if you don't" << endl;
				char tryAgain;
				cin >> tryAgain;
				if (tryAgain == 'y') {
					displayAStudent(students);
				}
				
				
			}
	
	}
	
	
	} else {
		cout << "Sorry, there are no students. You haven't inputted any student data yet." << endl; 
	}

	
	
		
	

}

void executeUserDecision(char userDecision) {

	if (userDecision == 'i') {
			inputStudents();
		}
		else if (userDecision == 's') {
			displayAStudent(students);
		}
		else if (userDecision == 'a') {
			displayAllStudents(students);
		}
		else {
			// its an invalid input hence the user should input again
			inputUserDecision();
		}

}









int main() {
		
		
		
		
		char userDecision = inputUserDecision();
		
		while (!isUserDecisionValid((userDecision))) {
			userDecision = inputUserDecision();
		}
		if (userDecision == 'q') {
			return 0;
		}
		executeUserDecision(userDecision);
		
		
		
		
		
		// keeps running the program until the user quits
		while (userDecision != 'q') {
			
			userDecision = inputUserDecision();
			while (!isUserDecisionValid((userDecision))) {
			userDecision = inputUserDecision();
			}
			
			executeUserDecision(userDecision);
			
			
		}
		
		
	
	


	return 0;	 
}

