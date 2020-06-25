//  GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class
using namespace std;
// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void inputGrades(); // input arbitrary number of grades from user
   void displayGradeReport() const;  // display report based on user input
   void displayInputs();
   double calculateGrade()const;
   void initializeData();
   ~GradeBook();


private:
   std::string courseName; // course name for this GradeBook
   unsigned int aCount; // count of A grades
   unsigned int bCount; // count of B grades
   unsigned int cCount; // count of C grades
   unsigned int dCount; // count of D grades
   unsigned int fCount; // count of F grades
   string letterGrade[100];
   int count = 0;
   int countGrades[6] = { 0,0,0,0,0,0 };
}; // end class GradeBook  