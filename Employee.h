#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
using namespace std;

class Employee {

  protected:
    int number;
    char name[25];
    char address[35];
    void initName(char* n);
  
	public:

		Employee() : number(0) {
			strcpy(name, "none");
			name[23] = '\0';
			
			strcpy(address, "none");
			address[35] = '\0';

		}

		Employee(const char* n, const char*a, int num) {
			strcpy(name, n);
			name[25] = '\0';

			strcpy(address, a);
			address[35] = '\0';

			number = num;
		}

		~Employee()	{};

    int getEmployeeNumber() const
      { return number; }

    void getName() const
  	  { cout << name << endl; }

  	void getAddress()
      { cout << address << endl; }

    virtual double calcPay(void) = 0;
		virtual void printCheck(void) = 0;

};

#endif
