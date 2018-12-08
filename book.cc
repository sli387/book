#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void menu();

//contains all function / operations
void pick(int);

//actual functions for the address book operations
void add();
void del();
void upd();


int main() {
  //creates and closes the file: book
  ofstream myfile("book.txt", ios::binary);
  myfile << "Address Book" << endl;

  myfile.close();
  //include menu to operate the address book
  cout << "New Address Book Created" << endl;
  menu();

  return 0;
}


void menu() {
  //variable to store the choice
  int number;

  cout << "\n\tMenu" << endl;
  cout << "_______________________________" << endl;
  cout << "1. View Address Book" << endl;
  cout << "2. Search Address Book" << endl;
  cout << "- - - - - - - - - - - - - - - -" << endl;
  cout << "3. Add Contact" << endl;
  cout << "4. Delete Contact" << endl;
  cout << "5. Update Contact" << endl;
  cout << "6. Exit" << endl;
  cout << endl;

  cout << "Choice : ";
  cin >> number;

  //checks if the user entered a valid number
  if(number > 0 && number < 7){
    //calls the function holding the actions
    pick(number);

		//returns to the menu so that the user can exit on their own
		cout << "\nReturning to Menu" << endl << endl;
		menu();

  } else {
    //tells user the input is wrong and asks for another one
    cout << "INVALID INPUT" << endl;
    cout << "Please enter a number from 1 to 6." << endl;
    menu();
  }
}


//contains the functions for the book
void pick(int choice) {

  string line;

  switch(choice) {
    case 1:
			{
				ifstream myfile;
        //view address book in abc order 
        cout << "Viewing Book\n" << endl;
				myfile.open("book.txt");
        //opens the file of address book
        if(myfile.is_open()) {
          while ( getline(myfile, line) ) {
              cout << line << endl;
          }

        	myfile.close();

        	} else {
          	cout << "File Not Open." << endl;
        	}
            break;
			}

    case 2:
			{
				ifstream myfile;
        //search address book for this string
				string searching;
				int check;
				
				cin.ignore();
				myfile.open("book.txt");

				//opens the file and searches for string
				cout << "Search Book" << endl;	

				if(myfile.is_open()) {
					cout << "Search for Name : ";
					getline(cin, searching);

					while( getline(myfile, line) ) {
						if(line.find(searching) != string::npos) {
							check++;
						} 
					}
					
					if(check > 0) {
						cout << "\nContact in Book." << endl;
					} else {
						cout << "\nContact not in Book." << endl;
					}
				}
        break;
			}

    case 3:
			//add contact
			add();
			break;

    case 4:
			//delete contact
			del();
      break;

    case 5:
			//update contact
      upd();
      break;
	
    case 6:
      //exits program
      cout << "Exiting Address Book. . ." << endl;
      exit(EXIT_SUCCESS);
      break;
  }
}



void add() {
	ofstream myfile;
	cin.ignore();
	string name, address, phone;
	myfile.open("book.txt", ios::app);

	//add contact
	cout << "Adding to Book" << endl;

	if(myfile.is_open()) {
		//lets user add to book.txt

		cout << "Name : ";
		getline(cin, name);

		cout << "Address : ";
		getline(cin, address);

		cout << "Phone : ";
		getline(cin, phone);

		myfile << "-------------------" << endl;
		myfile << "\n\t" << name + "\n\t" + address + "\n\t" + phone << endl << endl;

		myfile.close();

	} else {
		cout << "File Not Open." << endl;
	}
}

void del() {
	fstream myfile;
	string line, searching;
	int count;
	int place;

	cin.ignore();
	//delete contact
  cout << "Delete from Book" << endl;
	myfile.open("book.txt");

	if(myfile.is_open()) {
		cout << "Search for Name : ";
		getline(cin, searching);

		while( getline(myfile, line) ) {
			if(line.find(searching) != string::npos) {
				cout << "Deleting the Contact." << endl;
			} 
		}
	}
}

void upd() {
	fstream myfile;
	string line, searching;
	cin.ignore();
	//delete contact
  cout << "Delete from Book" << endl;
	myfile.open("book.txt");

	if(myfile.is_open()) {
		cout << "Search for Name : ";
		getline(cin, searching);

		while( getline(myfile, line) ) {
			if(line.find(searching) != string::npos) {
				cin.ignore();
				//deletes the found contact

				cin.ignore();
				//adds a new contact
				add();
			} 
		}
	}
}
