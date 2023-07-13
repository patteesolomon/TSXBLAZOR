// TutStuff2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

const int NUM_TAGYR = 2;
const int NUM_VOLMIR = 3;
const int NUM_ESSENOX = 5;

fstream JOM("class.txt", ios::in, ios::out);

fstream outfile("monday.txt", ios::in | ios::out | ios::trunc);

// Templates

template <class T> class a
{
	int x;
	int y;
	if (x >= y) { x = true; }
	else { x = false; }
};

//structs

struct SD
{
	string name;
	int price;
	int num;

};

struct rune
{
	string name;
	string dec;
	string type;
	int* id = nullptr;
};


class Cpal
{
	protected: 
		string men;

	private:
		int me = 0;
		string name;

	public: 
		void setName(string x)
		{
			name = x;
			cout << "bled" << endl;
		}
		string getName() 
		{
			return name;
		};
};

class Momisdead
{
public:
	string name;
};

void transaction(SD[], int s, double& aflac);

int getChoice(SD[]);

int main()
{
	/// some ints 
	int a = 5;
	int *b = &a;
	int c = *b;
	///

	// multiple instantiations
	Momisdead ded;
	ded.name = "mom";
	cout << ded.name;

	Cpal mo;
	mo.setName("wowNIPX");
    std::cout << "Hello World!\n";
	mo.setName(ded.name);

	mo.setName("bleck\n");
	cout << mo.getName();
	cout << "\n";

	cout << "     Here it is " + c;

	cout << "\n";


	system("PAUSE");
	return 0;
}

int rContainer()
{
	rune Tainer;
	rune prp;
	rune megani;

	int addup = 0;
	int tainer0 = 0;
	int markp1 = 0;
	int meg2 = 0;

	Tainer.id = &tainer0;
	prp.id = &markp1;
	megani.id = &meg2;
	
	int items0[]=  { tainer0 };
	int items1[] = { markp1 };
	int items2[] = { meg2 };

	for (int i = 0; items0 < 0; i++)
	{
		cout << items0[i];
		addup += items2[i];
		addup += items1[i];
		addup += items0[i];
	}
	return addup;
}

void transaction(SD[], int s, double& aflac)
{

}

int getChoice(SD[])
{
	return -1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
