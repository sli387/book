#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

class SalariedEmployee : public Employee {
  private:
    double wage;
    int week;

  public:

		SalariedEmployee() : wage(0) , week(0.0) {};

		SalariedEmployee(const char* n, const char* a, int num, double w, int wk) : Employee(n, a, num), wage(w) , week(wk) {};

		~SalariedEmployee()	{};

    double getWeeklyWage() const
      { return wage; }

		int getWeekWorked() const 
			{	return week;	}

    double calcPay()
      { return wage * week * 54; }

    void printCheck() {
      cout << "Name: " << name << endl;
      cout << "--------------------------------------------------\n";
      cout << "Weeks: " << getWeekWorked() << endl;
	    cout << "Wage: $" << getWeeklyWage() << endl;
	    cout << "Pay: $" << calcPay() << endl;
      cout << "\n\nDeposit\n";
    }
}; 

#endif
