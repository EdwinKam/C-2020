// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include <iostream>
#include <array>
#include<iomanip>
#include<string>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook(string name)
	: aCount(0), // initialize count of A grades to 0 
	bCount(0), // initialize count of B grades to 0
	cCount(0), // initialize count of C grades to 0
	dCount(0), // initialize count of D grades to 0
	fCount(0)  // initialize count of F grades to 0
{
	setCourseName(name);

	//cout << endl;
	displayGradeReport();
} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName(string name)
{
	if (name.size() <= 30) // if name has 25 or fewer characters
		courseName = name; // store the course name in the object
	else // if name is longer than 25 characters
	{ // set courseName to first 25 characters of parameter name
		courseName = name.substr(0, 30); // select first 25 characters
		cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
			<< "Limiting courseName to first 25 characters.\n" << endl;
	} // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
	return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
	// this statement calls getCourseName to get the 
	// name of the course this GradeBook represents
	cout << "Welcome to the grade book for\n" << getCourseName() << "!\n"
		<< endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
int GradeBook::inputGrades( int count)
{
	int grade; // grade entered by user

	cout << "Enter the letter grades." << endl
		<< "Enter the EOF character to end input." << endl;

	// loop until user types end-of-file key sequence
	while ((grade=cin.get())!= EOF)
	{
		// determine which grade was entered
		switch (grade) // switch statement nested in while
		{
		case 'A': // grade was uppercase A
		case 'a': // or lowercase a
			++aCount; // increment aCount
			countGrades[0]++;
			letterGrade[count++] = grade;
			return count;
			
			break; // necessary to exit switch

		case 'B': // grade was uppercase B
		case 'b': // or lowercase b
			++bCount; // increment bCount 
			countGrades[1]++;
			letterGrade[count++] = grade;
			return count;
			break; // exit switch

		case 'C': // grade was uppercase C
		case 'c': // or lowercase c
			++cCount; // increment cCount  
			countGrades[2]++;
			letterGrade[count++] = grade;
			return count;
			break; // exit switch

		case 'D': // grade was uppercase D
		case 'd': // or lowercase d
			++dCount; // increment dCount  
			countGrades[3]++;
			letterGrade[count++] = grade;
			return count;
			break; // exit switch

		case 'F': // grade was uppercase F
		case 'f': // or lowercase f
			++fCount; // increment fCount    
			countGrades[4]++;
			letterGrade[count++] = grade;
			return count;
			break; // exit switch

		case '\n': // ignore newlines,  
		case '\t': // tabs, 
		case ' ': // and spaces in input
			break; // exit switch

		default: // catch all other characters
			cout << "Incorrect letter grade entered."
				<< " Enter a new grade." << endl;
			letterGrade[count++] = grade;
			int error;
			count++;
			return 0;
			break; // optional; will exit switch anyway
		} // end switch
	} // end while
} // end function inputGrades

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
	// output summary of results
	cout << "The total number of data entered is " << count;
	cout << "\nThe total number of students recieve grade is " << aCount + bCount + cCount + dCount + fCount;
	cout << "\nNumber of students who received each letter grade:"
		<< "\nA:\t" << aCount // display number of A grades
		<< "\nB:\t" << bCount // display number of B grades
		<< "\nC:\t" << cCount // display number of C grades 
		<< "\nD:\t" << dCount // display number of D grades
		<< "\nF:\t" << fCount // display number of F grades
		<< "\nError:\t" << error
		<< endl;
	cout << "The class average gpa is " << fixed << setprecision(1) << calculateGrade() << endl;
} // end function displayGradeReport

void GradeBook::displayInputs()
{
	cout << "The data entered is listed at the following:\n";
	for (int i = 0; i < count; i += 4)
	{
		cout << "[" << i << "] -> " << letterGrade[i] << "\t[" << i + 1 << "] -> " << letterGrade[i + 1] << "\t[" << i + 2 << "] -> " << letterGrade[i + 2] << "\t[" << i + 3 << "] -> " << letterGrade[i + 3] << endl;
	}
}

void GradeBook::displayAllStudentGrades()
{
	cout <<"The data entered is listed at the following:\n";

}

double GradeBook::calculateGrade()const
{
	if (count == 0)
	{
		return 0;
	}
	double gpa = 0;
	for (int i = 0; i < 4; i++)
	{
		gpa += countGrades[i] * (4 - i);
	}
	//cout << "gpa: " << gpa << endl;


	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		sum += countGrades[i];
		//cout << i << endl;
	}
	//cout << "sum: " << sum;

	gpa = gpa / sum;
	return gpa;

}

void GradeBook::inputStudentName(int index)
{
	if (index != 0) {
		cout << "Enter student name: ";
		string haha;
		cin >> haha;
		studentName[index] = haha;
	}
}




void GradeBook::displayStudentName()
{
	cout << "Index\tStudent Name\t\tGrade\tGrade\tIndex\tStudent Name\t\tGrade\n";
}


GradeBook::~GradeBook()
{
	cout << "Destructor is called!\n";
}


void GradeBook::initializeData()
{
	aCount = 0;
	bCount = 0;
	cCount = 0;
	fCount = 0;
	dCount = 0;
	for (int i = 0; i < 100; i++)
	{
		studentName[i] = "";
		letterGrade[i] = "";
	}
	for (int i = 0; i < 6; i++)
	{
		countGrades[i] = 0;
	}
	count = 0;
}

void GradeBook::inputData()
{
	cout << "Enter the letter grade";

	inputStudentName(inputGrades( count));
	//inputStudentName();
	
	

}
