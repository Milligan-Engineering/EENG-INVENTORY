//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
//sjwehner@my.milligan.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 04/06/2018

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "PartData.h"

using namespace std;

	struct DataRead
	{
		ifstream inDataStream;
	};

	int main()
	{
		DataRead DR;
		PartData PartDataObject;// main class

		PartDataObject.fetchFileData();// pulling in CSV file

		cout << "Low parts:\n";
		PartDataObject.lowamnt();
		cout << "\n\n";

		char menuChoice;
		do
		{
			cout << endl;
			cout << "What would you like to do today? \n\n";
			cout << "To find a part press P\n";
			cout << "To access part list press I \n";
			cout << "To find type index press S\n";
			cout << "To get lab instructions press L\n";
			cout << "To exit press E\n\n";

			cin >> menuChoice;
			switch (menuChoice)
			{
			case 'P':
			case 'p':
				PartDataObject.partFind();
				PartDataObject.PartRemoval();
				//PartDataObject.PrintList();
			case 'I':
			case 'i':
				PartDataObject.partIndex();//prints list off all parts contained in the CSV
				break;

			case 'S'://Specific type search
			case 's':
				//string choice;
				PartDataObject.SPSearch();

				break;

			case 'E':
			case 'e':
				//Exit program choice (**closes program**)
				break;

			default:
				cout << "Not a valid menu choice.\n\n";

			}



		} while ((menuChoice != 'E') && (menuChoice != 'e'));

		
		PartDataObject.PushFileData();

			//delete [] PartDataObject.
		

		return 0;
	}

	void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period)
	{

		clock_t goal, now;
		now = CLOCKS_PER_SEC;
		now = clock();
		goal = static_cast<clock_t>(1000 * period) * CLOCKS_PER_SEC / 1000;
		while (goal > clock() - now)
			;
		for (int i = 0; i < numVal; i++)
		{
			data[i] = avgVal[i] - rangeVal[i] / 2 + (rand() % 1000)*rangeVal[i] / 1000; // assign random numbers
		}


	}


