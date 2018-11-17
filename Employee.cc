#include <iostream>
#include <cstring>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std;

void menu();

int main() {
	menu();
}

void menu() {
	int number;
	double wage;
	int hours;
	char name[25];
	char address[35];

	cout << "Which employee would you like to calculate the pay of :\n\t1.Hourly Employee\n\t2.Salary Employee\n\nChoice: ";
	cin >> number;

	switch (number) {
		case 1:
		{
			cin.ignore();
			cout << "\nEmployee\nName : ";
			cin.getline(name, 25);

			cout << "Address: ";
			cin.getline(address, 35);

			cout << "How many hours did " << name << " work?\nHours: ";
			cin >> hours;

			cout << "How much do " << name << " get paid?\nWage: $";
			cin >> wage;
			
			HourlyEmployee person(name, address, 3, hours, wage);

			cout << endl;
			person.printCheck();
		}
			break;

		case 2:
		{
			cin.ignore();
			cout << "\nSearch for Employee\nName : ";
			cin.getline(name, 25);

			cout << "Address: ";
			cin.getline(address, 35);

			cout << "How many hours per week did " << name << " work?\nHours: ";
			cin >> hours;

			cout << "How much do " << name << " get paid a hour?\nWage: $";
			cin >> wage;
			
			SalariedEmployee person(name, address, 3, wage, hours);

			person.printCheck();
		}
			break;
	}
}
