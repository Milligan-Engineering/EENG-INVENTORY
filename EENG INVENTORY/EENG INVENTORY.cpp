//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
//sjwehner@my.milligan.edu
//program is an inventory system that will be used to monitor and maintain information of stored parts.
//Last modified 05/02/2018

#include "stdafx.h"
#include "PartData.h"
#include <fstream>
#include <cstdlib>

using namespace std;
	int main()
	{
		PartData PartDataObject;// main class
		char menuChoice;
		do
		{
			cout << endl;
			cout << "What would you like to do today? \n\n";
			cout << "To find a part press P\n";
			cout << "To find type index press S\n";
			cout << "To access part list press I \n";
			cout << "To exit press E\n\n";

			cin >> menuChoice;
			switch (menuChoice)
			{
			case 'P':
			case 'p':
				if (PartDataObject.partFind() != 0)
				{
					PartDataObject.PartRemoval();
				}
				break;

			case 'I':
			case 'i':
				PartDataObject.partIndex();//prints list off all parts contained in the CSV
				break;

			case 'S':
			case 's':
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
		return 0;
	}




