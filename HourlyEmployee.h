#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

class HourlyEmployee : public Employee {
  private:
    int hours;
    double wage;

  public:

		HourlyEmployee() : hours(0) , wage(0.0) {};

		HourlyEmployee(const char* n, const char* a, int num, int h, double w) : Employee(n, a, num), hours(h) , wage(w) {};

		~HourlyEmployee()	{};

    int getHoursWorked() const
      { return hours;  }

    double getHourlyWage() const
      { return wage; }

    double calcPay()
      { return wage * hours; }

    void printCheck() {
      cout << "Name: " << name << endl;
			cout << "Address: " << address << endl;
      cout << "--------------------------------------------------\n";
      cout << "Hours: " << getHoursWorked() << endl;
      cout << "Hourly Wage: $" << getHourlyWage() << endl;
    	cout << "Pay: $" << calcPay() << endl;
      cout << "\nDeposit\n";
    }

};

#endif
