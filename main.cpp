#include <iostream>
using namespace std;




// counts how many students are there
int c = 0;

// stores the decision of the user, q for quit, a for display all students data, s for display a students data
char decision;



struct student
{
	// input data
	string name, UID, grade;
	float midResult, finalResult, assignmentResult, labResult;
	
	// calculated data
	float sum, GPA;
};




// allocating memory for students
student students [100];

// first calculate the Grade using the sum because grade is unique for different GPAs, then calculate GPA using the calculated grade as an input

string gradeCalc(int sum)
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

float GPACalc(string grade) {
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




void inputStudents(student students[])
{
	// checks if you want to keep inputing or go back to main menu
	char keepInputing = 'y';
	while (keepInputing == 'y')

	{
		
		// iputing the data from the user
		cout << "input name" << endl;
		cin >> students[c].name;
		cout << "input UID" << endl;
		cin >> students[c].UID;
		cout << "input final result" << endl;
		cin >> students[c].finalResult;
		cout << "input mid Result" << endl;
		cin >> students[c].midResult;
		cout << "input assignment result" << endl;
		cin >> students[c].assignmentResult;
		cout << "input lab result" << endl;
		cin >> students[c].labResult;
		
		// doing the calculations
		
		students[c].sum = students[c].midResult + students[c].finalResult + students[c].assignmentResult + students[c].labResult;
		students[c].grade = gradeCalc(students[c].sum);
		students[c].GPA = GPACalc(students[c].grade);
		
		// adding one more student to the list
		c++;
		
		
		// checking if the user want to add more students or return to the main menu
		cout << "Click 'y' if you want to keep inputing students, 'n' if you want to go back to main menu" << endl;
		cin >> keepInputing;
	}
}



void displayAllStudents(student students[])
{

// display doesnt have keep displaying unlike input students

	for (int i = 0; i < c; i++)
	{
		cout << endl;
		cout << "UID: " << students[i].UID << endl;
		cout << "Name: " << students[i].name << endl;
		cout << "Mid Result: " << students[i].midResult << endl;
		cout << "Final Result: " << students[i].finalResult << endl;
		cout << "Assignment Result " << students[i].assignmentResult << endl;
		cout << "Lab Assignment Result " << students[i].labResult << endl;
		cout << "Out of 100%" << students[i].sum << endl;
		cout << "Grade: " << students[i].grade << endl;
		cout << "GPA: " << students[i].GPA << endl;
		cout << endl;
	}
	
	// goes to the main menu
	
	cout <<"Main Menu" << endl << "Press 'i' if you want to input students data, 's' if you want to display a specific student's data, 'q' if you want to quit the program" << endl;
	cin >> decision;
}

// display's a students data based on the UID

void displayAStudent(student students[]) {
	
	cout << "input a UID" << endl;
	string inputUID;
	cin >> inputUID;
	
	for (int i = 0; i < c; i++) {
		// finding the specific student
		if (students[i].UID == inputUID) {
			cout << endl;
			cout << "UID: " << students[i].UID << endl;
			cout << "Name: " << students[i].name << endl;
			cout << "Mid Result: " << students[i].midResult << endl;
			cout << "Final Result: " << students[i].finalResult << endl;
			cout << "Assignment Result " << students[i].assignmentResult << endl;
			cout << "Lab Assignment Result " << students[i].labResult << endl;
			cout << "Out of 100%" << students[i].sum << endl;
			cout << "Grade: " << students[i].grade << endl;
			cout << "GPA: " << students[i].GPA << endl;
			cout << endl;
			break; // to save memory
		}
		
		// add a couldnt find button
		
	}
	
	cout << "what do you want to do next?" << endl << "press 'i' if you want to input, 's' if you want to display a specific student, 'q' if you want to quit" << endl;
	cin >> decision;
}

// tells the user the commands and the results that they produce

void help() {
	system("cls");
}

void rankBasedOnSubject() {

}

void overallRank() {

}



int main()
{
	// initial of the program. here the user has only option of either inputing student data or quiting the program
	cout << "Welcome" << endl << "press i if you want to input student data, q if you want to quit the program" << endl;
	cin >> decision;
	
	
	if (decision == 'i')
	{
		inputStudents(students);
	}
	else
	{
		cout << "please input either i or q" << endl;
	}
	
	
	// the program keeps running until the user quits
	cout << "to input press i, to display all students press a, to display a students data press s, to quit press q"<< endl;
	cin >> decision;
	
	
	while (decision != 'q')
	{
		if (decision == 'i')
		{
			inputStudents(students);
		}
		else if (decision == 'a')
		{
			displayAllStudents(students);
		} else if (decision == 's') {
			displayAStudent(students);
		}
		else
		{
			cout << "please input either i or q" << endl;
		}
	}
	
	
	return 0;
}

