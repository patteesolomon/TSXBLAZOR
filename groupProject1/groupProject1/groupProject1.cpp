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
const int CUSTSIZE = 5;

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
//void deleteRec(long);   // delete one record
//void showAll();         // display all records

// flags to signal setInfo()
bool rnew = false;      // To signal if the record is new  
bool mod = false;       // To signal if the record is being modified

int main() //Christina Camacho
{
	//creating the file
	//Open, close and temp files in the function to make it safer
	//fstream file("custFile.dat", ios::out | ios::binary);
	//fstream fileTemp("tempFile.dat", ios::out | ios::binary);

	//calls structure into the main function
	Customer info[SIZE];
	long fp;
	cout << "*****************************************************************" << endl;
	cout << "                         CUSTOMER ACCOUNTS                       " << endl;
	cout << "                        By: THE TERMINATORS                      " << endl;
	cout << "*****************************************************************" << endl << endl;

	int choice;
	//enter choice
	cout << "The following program allows you to alter Customer Account information." << endl;
	cout << "To write a record to a file select 1." << endl;
	cout << "To display a record of your choice select 2." << endl;
	cout << "To delete a record select 3. " << endl;
	cout << "To show all records select 4." << endl;
	cout << "Select 5 to quit the program." << endl << endl;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			cout << "\nYou selected Enter a new Customer Account.\n\n";
			//If new record then run the function setInfo until you no longer need a new record
			rnew = true;
			setInfo(0);
			rnew = false;
			break;
		case 2:
			//make things pretty
			cout << "Display a record. " << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			//call the position in the search function
			 search();
			 break;
			//if the file found then display it
			if (fp != -1)
			{
				display(fp);//call display function
			}
			//Otherwise throw an error
			/*else
				cout << "Record not found" << endl;
			break;*/
			//case 3:
				//deleteRec(); //call delete record function
				//search();
				//break;
			//case 4:
				//show(info); //call show all function
				//break;
		}
		//Option to request that a person write a record first or to return an error message is no records exists
		cout << "What is your selection now?" << endl;
		cout << "To write a record to a file select 1." << endl;
		cout << "To display a record of your choice select 2." << endl;
		cout << "To delete a record select 3. " << endl;
		cout << "To show all records select 4." << endl;
		cout << "Select 5 to quit the program." << endl << endl;
		break;
	}
	return 0;
}
/* *****************************************************************
 The setInfo function write record to the file.*
 *********************************************/

void setInfo(long fp)
{

	Customer info;
	fstream custFile;

	char again = 'Y';            // to or hold Y or N
	int count = 0;

	// Get the information of each customer



	cout << "RECORD #: " << count + 1 << endl;
	do
	{
		cout << "Please Enter Your Name: ";
		cin.getline(info.name, SIZE);
	} while (info.name[0] == '\0');

	do
	{
		cout << "Please Enter Your Home Address: ";
		cin.getline(info.address, SIZE);
	} while (info.address[0] == '\0');

	do
	{
		cout << "Please Enter Your City: ";
		cin.getline(info.city, SIZE);
	} while (info.city[0] == '\0');

	do
	{
		cout << "Please Enter Your State: ";
		cin.getline(info.state, SIZE);
	} while (info.state[0] == '\0');

	do
	{
		cout << "Please Enter Your Zip Code: ";
		cin.getline(info.zip, SIZE);
	} while (info.zip[0] == '\0');

	do
	{
		cout << "Please Enter Your Telephone Number: ";
		cin.getline(info.phone, SIZE);
	} while (info.phone[0] == '\0');

	do
	{
		cout << "Please Enter Your Account Balance: ";
		cin >> info.balance;
		// validate the account balance 
		if (info.balance < 0)
		{
			cout << "Sorry, We Don't Accept Negative Value!"
				<< "Try Again: ";
			cin >> info.balance;
		}
	} while (info.balance == '\0');

	cin.ignore();

	do
	{
		cout << "Please Enter Date of Your Last Payment: ";
		cin.getline(info.lastPay, SIZE);
	} while (strlen(info.lastPay) == '\0');

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
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	custFile.write(reinterpret_cast<char*>(&info), sizeof(info));

	cout << "Do you want to add another record? \n"
		<< " Press Y for yes and N for no: ";
	cin.get(again);

	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	count++;


	custFile.close();

}

// *****************************************************************
// The display function displays a single record.                  *
// *****************************************************************
void display(long fp)//Christina Camacho // todo fix
{
	Customer c;
	//open file
	fstream custFile("custFile.dat", ios::out | ios::binary);
	string a = ""; // size in bytes to chars 
	//error message
	if (custFile.fail())
	{
		cout << "File not open" << endl;
		return;
	}
	//check if the file has data in it
	/*if ()
	{
		cout << "File is empty";
		custFile.close();
		return;
	}*/

	//search through the file
	custFile.seekg(fp, ios::beg);
	custFile.read(reinterpret_cast<char*>(&c), sizeof(c));

	cout << "Name: " << c.name << endl;
	cout << "Address: " << c.address << endl;
	cout << "City: " << c.city << " State: " << c.state
		<< "Zip code: " << c.zip << endl;
	cout << "Phone Number: " << c.phone << endl;
	cout << "Current Balance: " << c.balance << endl;
	cout << "Last Payment: " << c.lastPay << endl;

	//close the file
	custFile.close();
	//Get the data and display
	cin.get();
}

// *****************************************************************
// The search function returns the file pointer position.          *
// *****************************************************************
long search()
{
	Customer info[CUSTSIZE];
	Customer reader;
	fstream file("custFile.dat", ios::in | ios::binary);
	file.open("custFile.dat", ios::in | ios::binary);

	if (!file)
	{
		std::cout << "Melm.. The file cannot be found." << endl;
	}

	string sName;
	std::cout << "Select which customer record you would like to pull up by" << endl;
	std::cout << "entering their First Name, Space, Last Name. For example: John Smith." << endl;
	cin >> sName;

	bool flag = false; // found

	// element
	int element = 0;

	long pos = 0; // position in the file

	//string tIndex[CUSTSIZE]; // terminator Index

	file.seekg(0L, ios::end); // to the end

	file.read(reinterpret_cast<char*>(&reader), sizeof(reader));

	// hadangeki copys from the input that is converted to bytes
	long had = static_cast<long>(sName.size());

	while (!file.eof())
	{
		// address
		if (info[pos].name != sName)
		{
			info[element] = reader;
			element++;
			//file.read(reinterpret_cast<char*>(&reader), sizeof(reader));
			/*file.read(reinterpret_cast<char*>(&pos), sizeof(pos));
*/
			// list search for comparisons
			//file.seekg(0L, 324L); // intervals

			//// each customer is 323bytes so each one has an address
			//file.read(reinterpret_cast<char*>(&info[0].name), sizeof(info[0].name));
			//// next
			//file.seekg(324L, 647L);
			//file.read(reinterpret_cast<char*>(&info[1].name), sizeof(info[1].name));
			//// next
			//file.seekg(647L, 970L);
			//file.read(reinterpret_cast<char*>(&info[2].name), sizeof(info[2].name));
			//// next
			//file.seekg(970L, 1293L);
			//file.read(reinterpret_cast<char*>(&info[3].name), sizeof(info[3].name));
			//// next
			//file.seekg(1293L, 1615L);
			//file.read(reinterpret_cast<char*>(&info[4].name), sizeof(info[4].name));
		}
		else
		{
			file.close();
			flag = true;
			std::cout << "found" << endl;
			// search loop for comparison
			
		}
		for (int i = 1; i < 5; i++) // todo
		{
			if (sName == info[i].name)
			{
				string v = info[i].name;
				// only add the below if the returned position isn't what you needed...
				// Honestly I need to know where that position is everytime I close the file
				// do I need to go back or stop after reading where I left off?
				/*
				had = static_cast<long>(v.size());
				pos = hadangeki;*/
			}
		}
	}

	/*struct Array
	{
		int arr[Arr];
	};

	const int Arr = 42;
	Array Ar[Arr];*/


	//close the file
	file.close();

	return pos; // returns that long
}


/*void toString()
{
	Customer m;

	cout << m[].address;
	cout << m[].balance;
	cout << m[].city;
	cout << m[].lastPay;
	cout << m[].name;
	cout << m[].phone;
	cout << m[].state;
	cout << m[].zip;
}*/

// *****************************************************************
// The showAll function shows all the customer records.            *
// *****************************************************************
void showAll(Customer c[])    //christion butterworth
{
	fstream file("custFile.dat", ios::out | ios::binary);
	fstream fileTemp("tempFile.dat", ios::out | ios::binary);

	for (int x = 0; x < CUSTSIZE; x++)
	{
		cout << "All Customer Accounts\n";
		cout << "Name: " << c[x].name << endl;
		cout << "Address: " << c[x].address << endl;
		cout << "City and State:  " << c[x].state << c[x].city << endl;
		cout << "Zip: " << c[x].zip << endl;
		cout << "Phone Number : " << c[x].phone << endl;
		cout << "Current Balance : " << c[x].balance << endl;
		cout << "Last Payment : " << c[x].lastPay << endl;
	}

	//close the files
	fileTemp.close();
	file.close();
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
	Customer cust;

	//open customer file for both output and input data
	custFile.open("custFile.dat", ios::out | ios::in | ios::binary);
	// test to ensure file opened
	if (custFile.fail())
	{
		cout << "/Error! Unable to open file.";
		custFile.close();
		return;
	}

	custFile.seekp(fp, ios::beg);
	// place a null terminator to the beginning of the name member searched for
	strcpy_s(cust.name, "\0");
	custFile.write(reinterpret_cast<char*>(&cust), sizeof(cust));
	custFile.close();
	custFile.open("custFile.dat", ios:: in | ios :: binary);
	tempFile.open("tempFile.dat", ios:: out | ios::binary);

	custFile.read(reinterpret_cast<char*>(&cust), sizeof(cust));




	////char again;            // to or hold Y or N
	//do
	//{
	//    pos = search();
	//    cout << "Do you want to delete another record? " << endl;
	//    cin >> again;
	//} while (again == 'Y' || again == 'y');

	// close the files
	custFile.close();
	tempFile.close();
}


