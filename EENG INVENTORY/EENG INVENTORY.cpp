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

		//PartDataObject.fetchFileData();// pulling in CSV file

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
				cout << "Part type search\n" << "What type of part word you like to find?";
				cout << "For capacitors type C ";
				cout << "For Transisters type T ";
				cout << "For Resisters type R ";
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

		//delete [] PartDataObject.testArray;

		return 0;
	}


	
/*void quantitySort(int partQuant[], int Order[])
{

	int temp;
	for (int i = 0; i < partQuant[i] - 1; i++)
	{
		for (int j = 0; j < partQuant[i] - i - 1; j++)
		{
			if (partQuant[Order[j]] > partQuant[Order[j + 1]])
			{
				temp = Order[j];
				Order[j] = Order[j + 1];
				Order[j + 1] = temp;
			}
		}
	}
}*/