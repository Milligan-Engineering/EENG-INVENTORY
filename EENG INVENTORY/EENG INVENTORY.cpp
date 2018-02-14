//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
// sjwehner@my.milliga.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 02/14/2017
#include <iostream>
#include <string>

using namespace std;
int partIndex(int partNumber[], string partName[], int partQuant[], string partLoc[]);
const int maxParts = 3;								
int partnumber;//search value
string partName[maxParts];
string partLoc[maxParts];
int partQuant[maxParts];
int partsRemoved;
int partNumber[maxParts];
char menuChoice; 






int main()
{
	//Part Name
	partName[0] = " 1uF capacitor";
	partName[1] = "resistor";
	partName[2] = "transistor";

	//Part Quantities
	partQuant[0] = 51;
	partQuant[1] = 73;
	partQuant[2] = 85;

	// Part Locations
	partLoc[0] = "0101A";
	partLoc[1] = "0102A";
	partLoc[2] = "0103A";
	
	cout << "What would you like to do today? \n\n";
	cout << "To find a part press P and to access part list press I ";
		cin >> menuChoice;
		
			switch (menuChoice)
			{
			case 'P':
			case'p':

				do
				{

					cout << "Type part Number or 0 to exit:\n";
					cin >> partnumber;


					if ((partnumber < 0) || (partnumber > maxParts)) //part not found
					{
						cout << "part not found.\n\n";
					}


					else // part found command string
					{
						cout << "part number: " << partnumber << " requested" << "\t";
						cout << "part name: " << partName[partnumber - 1] << "\t";
						cout << "Quantity: " << partQuant[partnumber - 1] << "pcs" << "\t\t";
						cout << "Location: " << partLoc[partnumber - 1] << "\n\n";
						cout << "How many parts are you removing? ";
						cin >> partsRemoved;
						partQuant[partnumber - 1] = partQuant[partnumber - 1] - partsRemoved; //updates part quantity located in partQuant array
						cout << partQuant[partnumber - 1] << " parts remaining\n\n";

					}
				} 
				while (partnumber != 0);
				break;

			case 'I':
			case'i':
				partIndex(partNumber, partName, partQuant, partLoc);
				
				
				break;
			}
			char wait;
			cin >> wait;
	

	return 0;
}
int partIndex(int partNumber[], string partName[], int partQuant[], string partLoc[])
// prints out part list
{
	int i;
	for (i = 0; i < maxParts; i++)
	{

		cout << "Part Number: " << i << "\t";
		cout << "Part Name: " << partName[i] << "\t";
		cout << "Part Quantity: " << partQuant[i] << "\t";
		cout << "Part Location: " << partLoc[i] << "\t""\n\n";
	}
	return 0;
}


//for (i = 0, ++i, i <= maxParts)
//printPartInfo(i);								// printPartInfo
//cout << partName[i]"\t" << partQuant[i]"\t" << partLoc[i]"\t";