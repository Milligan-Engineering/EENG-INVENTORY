//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
//sjwehner@my.milligan.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 05/02/2018

#include "stdafx.h"
#include "PartData.h"

using namespace std;

	int main()
	{
		PartData PartDataObject;// main class

		PartDataObject.fetchFileData();// pulling in CSV file

		
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
		return 0;
	}




