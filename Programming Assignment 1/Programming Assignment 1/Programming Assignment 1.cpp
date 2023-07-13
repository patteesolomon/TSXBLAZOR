/******************************
   Team Name:The Terminators
   Date: 9-25-2019
   File Name spc12-16.cpp
   Description:
Your group project is on page 717, assignment number 16 - Customer Accounts.
Main Christina
setInfo Sao
Display 1 record Christina
Search Sol
deleteRec Jeremy
Showall  Christion
********************************/
// Chapter 12, Programming Challenge 16: Customer Accounts
// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


// Constant for array sizes
const int SIZE = 45;

fstream custFile;      // Customer file
fstream tempFile;      // For deletion swap

struct Customer
{
	char name[SIZE];
	char address[SIZE];
	char city[SIZE];
	char state[SIZE];
	char zip[SIZE];
	char phone[SIZE];
	double balance;
	char lastPay[SIZE];
};

// Function prototypes
void setInfo(long);     // write record to file
void display(long);     // display one record
long search();          // call a search in the function so we do not have to keep writing them
void deleteRec(long);   // delete one record
void showAll();         // display all records

// flags to signal setInfo()
bool rnew = false;      // To signal if the record is new  
bool mod = false;       // To signal if the record is being modified

int main() //Christina Camacho
{
	//calls structure into the main function
	long filePosition;
	int choice = 0;
	char selection = 'Y';
	cout << "*****************************************************************" << endl;
	cout << "                         CUSTOMER ACCOUNTS                       " << endl;
	cout << "                        By: THE TERMINATORS                      " << endl;
	cout << "*****************************************************************" << endl << endl;
	//enter choice
	cout << "This Program Allows You to Alter Customer Account Information.\n";
	cout << "1. Enter New Record into the File. " << endl;
	cout << "2. Display a Record of Your Choice. " << endl;
	cout << "3. Delete a Record. " << endl;
	cout << "4. Change a Record. " << endl;
	cout << "5. Display All the Content of the Entire File." << endl;
	cout << "6. Exist the Program." << endl << endl;
	cout << "Please Select (1-6): ";
	cin >> choice;
	while (choice < 1 || choice > 6)
	{
		cout << "Please Enter (1-6): ";
		cin >> choice;
	}

	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			cout << "\n New Customer Account is Selected.\n";
			cout << "-----------------------------------------------------------------------------\n";
			//If new record then run the function setInfo until you no longer need a new record
			rnew = true;
			cin.ignore();
			setInfo(0);
			rnew = false;
			break;
		case 2:
			//make things pretty
			cout << "\n Display a Record is Selected. \n" << endl;
			cout << "------------------------------------------------------------------------------\n";
			//call the position in the search function
			filePosition = search();
			//if the file found then display it
			if (filePosition != -1)
			{
				display(filePosition);//call display function
			}
			//Otherwise throw an error
			else
				cout << "Record not found" << endl;
			break;
		case 3:
			cout << "\n Delete Record is Selected.\n";
			cout << "------------------------------------------------------------------------------\n";
			filePosition = search();
			char again;

			if (filePosition != -1)
			{

				do
				{
					display(filePosition);
					cout << "\nAre You Sure?\n"
						<< "Select 'Y' for Yes and 'N' for No:\n";
					cin >> selection;
					if (selection == 'Y' || selection == 'y')
					{
						deleteRec(filePosition);
						break;
					}
					else if (selection == 'N' || selection == 'n')
					{
						cout << "\nRecord Remain the Same\n";
						break;
					}
					cout << "Do you want to delete another record? (Y) or (N)" << endl;
					cin >> again;
				} while (again == 'Y' || again == 'y');
			}
			else
			{
				cout << "\nRecord Was Not Found.\n";
				break;
			}
			break;
		case 4:
			cout << "\n Change a Record is Selected\n";
			cout << "------------------------------------------------------------------------------\n";
			//find the search position
			filePosition = search();
			//change record
			mod = true;
			if (filePosition != -1)
			{
				cout << "\n Current Record Contents: \n";
				display(filePosition);
				cout << "\n Please Enter New Content: \n";
				setInfo(filePosition);
				mod = false;
			}
			break;
		case 5:
			cout << "\n Display All Record is Selected.\n";
			cout << "------------------------------------------------------------------------------\n";
			showAll();
			break;
		case 6:
			exit(EXIT_SUCCESS);
		default:
			break;
		}
		//Option to request that a person write a record first or to return an error message is no records exists
		cout << "-----------------------------------------------------------------------------------\n";
		cout << "What is Your Selection Now?" << endl;
		cout << "1. Enter New Record into the File. " << endl;
		cout << "2. Display a Record of Your Choice. " << endl;
		cout << "3. Delete a Record. " << endl;
		cout << "4. Change a Record. " << endl;
		cout << "5. Display All the Content of the Entire File." << endl;
		cout << "6. Exist the Program." << endl << endl;
		cout << "Please Select (1-6): ";
		cin >> choice;
	}
	return 0;
}
// *****************************************************************
// The setInfo function write record to the file.                  *
// *****************************************************************

void setInfo(long fp)
{
	// information of customer type
	Customer info;
	// Get the information of each customer
	// get Name of the customer
	do
	{
		cout << "Please Enter Your Name: ";
		cin.getline(info.name, SIZE);
	} while (info.name[0] == '\0');

	// get Address of the customer
	do
	{
		cout << "Please Enter Your Home Address: ";
		cin.getline(info.address, SIZE);
	} while (info.address[0] == '\0');

	// get City where customer live
	do
	{
		cout << "Please Enter Your City: ";
		cin.getline(info.city, SIZE);
	} while (info.city[0] == '\0');

	// get State the customer living in
	do
	{
		cout << "Please Enter Your State: ";
		cin.getline(info.state, SIZE);
	} while (info.state[0] == '\0');

	// get the Zip Code of the customer area
	do
	{
		cout << "Please Enter Your Zip Code: ";
		cin.getline(info.zip, SIZE);
	} while (info.zip[0] == '\0');

	// get the Telephone number of the customer
	do
	{
		cout << "Please Enter Your Telephone Number: ";
		cin.getline(info.phone, SIZE);
	} while (info.phone[0] == '\0');

	// get the Balance of the customer
	do
	{
		cout << "Please Enter Your Account Balance: ";
		cin >> info.balance;
		// validate the account balance 
		if (info.balance <= 0 || isalpha)
		{
			cout << "Sorry, We Don't Accept Negative Value!\n"
				<< "Try Again: ";
			cin >> info.balance;
			break;
		}
	} while (info.balance == '\0');

	cin.ignore();

	// get the Date of customer last payment
	do
	{
		cout << "Please Enter Date of Your Last Payment: ";
		cin.getline(info.lastPay, SIZE);
	} while (strlen(info.lastPay) == '\0');

	// where to save the record if it new or modify
	if (rnew)
	{
		custFile.open("customer.dat", ios::out | ios::app | ios::binary);
	}
	else if (mod)
	{
		custFile.open("customer.dat", ios::in | ios::out | ios::binary);
		custFile.seekp(fp, ios::beg);
	}
	cout << endl;

	// write to the custFile
	custFile.write(reinterpret_cast<char*>(&info), sizeof(info));

	// check to see if file is saving
	if (custFile.fail())
	{
		cout << "Error Recording the File.\n";
	}
	else
	{
		cout << "Record Successed\n";
	}
	// close the file
	custFile.close();
}

// *****************************************************************
// The display function displays a single record.                  *
// *****************************************************************
void display(long fp)//Christina Camacho // todo fix
{
	Customer c;
	//open file
	custFile.open("customer.dat", ios::in | ios::binary);
	//error message
	if (custFile.fail())
	{
		cout << "File not open" << endl;
		return;
	}
	//check if the file has data in it
	if (custFile.peek() == EOF)
	{
		cout << "\nFile is empty.";
		custFile.close();
		return;
	}

	//search through the file
	custFile.seekg(fp, ios::beg);
	custFile.read(reinterpret_cast<char*>(&c), sizeof(c));

	cout << "Name: " << c.name << endl;
	cout << "Address: " << c.address << endl;
	cout << "City: " << c.city << endl;
	cout << "State: " << c.state << endl;
	cout << "Zip code: " << c.zip << endl;
	cout << "Phone Number: " << c.phone << endl;
	cout << "Current Balance: " << c.balance << endl;
	cout << "Last Payment: " << c.lastPay << endl;

	//close the file
	custFile.close();
}

// *****************************************************************
// The search function returns the file pointer position.          *
// *****************************************************************
long search()
{
	char cName[SIZE];
	Customer reader;
	long fileSize;
	cout << "Please Entering their First Name, Space, Last Name: ";

	// these two are for the char readin for space
	cin.ignore();
	cin.getline(cName, SIZE);

	custFile.open("customer.dat", ios::in | ios::binary);
	if (custFile.fail())
	{
		cout << "Error Opening the File\n";
		custFile.close();
		return -1;
	}

	custFile.seekg(0L, ios::beg); // going from the begining
	while (!custFile.eof())
	{
		custFile.read(reinterpret_cast<char*> (&reader), sizeof(reader));
		if (strstr(cName, reader.name) != NULL)
		{
			fileSize = custFile.tellg();
			custFile.close();
			return(fileSize - sizeof(reader));
		}
	}

	cout << "Can't Find the Record\n";
	custFile.close();
	return -1;
}
// *****************************************************************
// The showAll function shows all the customer records.            *
// *****************************************************************
void showAll()    //christion butterworth
{
	custFile.open("customer.dat", ios::in | ios::binary);
	Customer c;
	int record = 0;
	if (custFile.fail())
	{
		cout << "\nError Open the File\n";
		custFile.close();
		return;
	}


	custFile.seekg(0L, ios::beg);    // to set position to read the file
	while (custFile.peek() != EOF)
	{
		custFile.read(reinterpret_cast<char*>(&c), sizeof(c));
		cout << " RECORD #: " << record + 1 << endl;
		cout << "Name: " << c.name << endl;
		cout << "Address: " << c.address << endl;
		cout << "City:  " << c.city << endl;
		cout << "State: " << c.state << endl;
		cout << "Zip: " << c.zip << endl;
		cout << "Phone Number : " << c.phone << endl;
		cout << "Current Balance : " << c.balance << endl;
		cout << "Last Payment : " << c.lastPay << endl << endl;
		record++;
	}

	//close the files
	custFile.close();
}

// *****************************************************************
// This function marks a record for deletion by placing            *
// the null terminator at the beginning of the name member.        *
// The contents of the file are then copied to a temporary file,   *
// then the temporary file is copied back to the Customer file     *
// -- without the deleted record.                                  *
// Ideally, this function would be expanded to allow multiple      *
// record deletions before the final file swap takes place.        *
// *****************************************************************
void deleteRec(long fp)    // Jeremy Laney
{
	// variable declaration
	Customer cust;    // hold customer record of type customer

	//open customer file for both output and input data
	custFile.open("customer.dat", ios::out | ios::in | ios::binary);

	// test to ensure file open
	if (custFile.fail())
	{
		cout << "/Error! Unable to open file.";
		custFile.close();
		return;
	}

	// place a null terminator to the beginning of the name member searched for
	strcpy_s(cust.name, "\0"); //null terminator write to a cust.name in the file position

	//write to this position from the beginning
	custFile.seekg(fp, ios::beg);
	//null terminator (c name) being placed
	custFile.write(reinterpret_cast<char*>(&cust), sizeof(cust));
	custFile.close();

	// open to swap from customer to temporary file
	custFile.open("customer.dat", ios::in | ios::binary);//reading from the cust file
	tempFile.open("temporary.dat", ios::out | ios::binary);//writing to the temp  fil
	// swap the customer into the temporary file
	while (custFile.peek() != EOF)
	{
		custFile.read(reinterpret_cast<char*>(&cust), sizeof(cust));
		tempFile.write(reinterpret_cast<char*>(&cust), sizeof(cust));
	}
	// close both file to open again
	custFile.close();
	tempFile.close();

	// open to swap from temporary file back into customer file
	tempFile.open("temporary.dat", ios::in | ios::binary);
	custFile.open("customer.dat", ios::out | ios::binary | ios::trunc);
	// swap the temporary back into customer file
	tempFile.read(reinterpret_cast<char*>(&cust), sizeof(cust));
	while (!tempFile.eof())        // while not at the end of file
	{
		// if not null terminator
		if (cust.name[0] != '\0')
		{
			// write back into customer file
			custFile.write(reinterpret_cast<char*>(&cust), sizeof(cust));
		}
		tempFile.read(reinterpret_cast<char*>(&cust), sizeof(cust));
	}

	// close both files
	custFile.close();
	tempFile.close();
	cout << "Delete Success !!\n";
}