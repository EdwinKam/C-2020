// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string , string ); // constructor initialize courseName
   void setCourseName( std::string ); // sets the course name
   void setInstructorName(std::string); // sets the instructor name
   string getInstructorName() const;
   std::string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
   string instructorName;
}; // end class GradeBook  


