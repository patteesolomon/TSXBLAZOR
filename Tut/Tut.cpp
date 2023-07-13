// Tut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Constant for array sizes
const int SIZE = 45;
const int CUSTSIZE = 5;

fstream custFile("custFile.dat", ios::in | ios::out | ios::binary);

// Customer file
//fstream tempFile("custFile.dat", ios::out | ios::binary);
// For deletion swap

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

// templates 
template <class T>
class MyClass
{
public:

private:
	T score;

};
							// |x|
// Function prototypes
long S(char* a, char* b);

// flags to signal setInfo()

int main()
{
	std::cout << "Hello World!\n";
	// void functions


	return 0;
}

void write()
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
/*
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
	}*/
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

long S(char* a, char* b)
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

