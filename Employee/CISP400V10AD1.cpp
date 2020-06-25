// CISP400V10AD1.cpp
// Create and manipulate two Employee objects.
#include <iostream>
using std::cout;
using std::endl;
  
#include "Employee.h" // include definition of class Employee

// function main begins program execution
int main()
{
   // create two Employee objects
   Employee employee1( "Lisa", "Roberts", 4500 );
   Employee employee2( "Mark", "Stein", 4000 );
   Employee employee3( "John", "Lin", -500 );
   Employee employee4( "Robert", "Ackmen", 0 );

   // display each Employee's yearly salary
   cout << "\nEmployees' yearly salaries: " << endl;

   // retrieve and display employee1's monthly salary multiplied by 12
   int monthlySalary1 = employee1.getMonthlySalary();
   cout << " " << employee1.getFirstName() << " " << employee1.getLastName()
      << ": $" << monthlySalary1 * 12 << endl;

   // retrieve and display employee2's monthly salary multiplied by 12
   int monthlySalary2 = employee2.getMonthlySalary();
   cout << " " << employee2.getFirstName() << " " << employee2.getLastName()
      << ": $" << monthlySalary2 * 12 << endl;

      // retrieve and display employee3's monthly salary multiplied by 12
   int monthlySalary3 = employee3.getMonthlySalary();
   cout << " " << employee3.getFirstName() << " " << employee3.getLastName() 
      << ": $" << monthlySalary3 * 12 << endl;

   // retrieve and display employee4's monthly salary multiplied by 12
   int monthlySalary4 = employee4.getMonthlySalary();
   cout << " " << employee4.getFirstName() << " " << employee4.getLastName()
      << ": $" << monthlySalary4 * 12 << endl<<endl;

   // give each Employee a number raise
  employee1.increaseMonthlySalary(- 5);
  employee2.increaseMonthlySalary(- 10);
  employee3.increaseMonthlySalary( 45);
  employee4.increaseMonthlySalary(55);

   // display each Employee's yearly salary again
   cout << "\nEmployees' yearly salaries after adjustment: " << endl;

   // retrieve and display employee1's monthly salary multiplied by 12
   monthlySalary1 = employee1.getMonthlySalary();
   cout << " " << employee1.getFirstName() << " " << employee1.getLastName()
      << ": $" << monthlySalary1 * 12 << endl;
     // retrieve and display employee2's monthly salary multiplied by 12
   monthlySalary2 = employee2.getMonthlySalary();
   cout << " " << employee2.getFirstName() << " " << employee2.getLastName()
      << ": $" << monthlySalary2 * 12 << endl;
         // retrieve and display employee3's monthly salary multiplied by 12
    monthlySalary3 = employee3.getMonthlySalary();
	cout << " " << employee3.getFirstName() << " " << employee3.getLastName()
      << ": $" << monthlySalary3 * 12 << endl;

   // retrieve and display employee4's monthly salary multiplied by 12
   monthlySalary4 = employee4.getMonthlySalary();
   cout << " " << employee4.getFirstName() << " " << employee4.getLastName()
      << ": $" << monthlySalary4 * 12 << endl<<endl;

   system("PAUSE");
   return 0; // indicate successful termination
} // end main

