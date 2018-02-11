//EENG INVENTORY
//Sam Wehner
//EENG 221
// sjwehner@my.milliga.edu
//Last modified 02/08/2017
#include <iostream>
#include <string>

using namespace std;
const int maxParts = 3;								
int partNumber;
string partName[maxParts];
string partLoc[maxParts];
int partQuant[maxParts];
int partsRemoved;
char menuChoice; 
int printPartInfo(partNumber);




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
	
	cout << "What would you like to do today?\n\n";
	cout << "To find a part press P and to access part list press I";
		cin >> menuChoice;
		//do
		//{
			switch (menuChoice)
			{
			case 'P':
			case'p':

				do
				{

					cout << "Type part Number or 0 to exit:\n";
					cin >> partNumber;


					if ((partNumber < 0) || (partNumber > maxParts)) //part not found
					{
						cout << "part not found.\n\n";
					}


					else // part found command string
					{
						cout << "part number: " << partNumber << " requested" << "\t";
						cout << "part name: " << partName[partNumber - 1] << "\t";
						cout << "Quantity: " << partQuant[partNumber - 1] << "pcs" << "\t";
						cout << "Location: " << partLoc[partNumber - 1] << "\n\n";
						cout << "How many parts are you removing? ";
						
						cin >> partsRemoved;
						partQuant[partNumber - 1] = partQuant[partNumber - 1] - partsRemoved; //updates part quantity located in partQuant array
						cout << partQuant[partNumber - 1] << " parts remaining\n\n";

					}
				} 
				while (partNumber != 0);
				break;

			case 'I':
			case'i':
		
				for (i=0, i++);
					//printPartInfo(i);								// printPartInfo
					cout << partName[i]"\t" << partQuant[i]"\t" << partLoc[i]"\t";


				break;
			}
		
 

	

	return 0;
}