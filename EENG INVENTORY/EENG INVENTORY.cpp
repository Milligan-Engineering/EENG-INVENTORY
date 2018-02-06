//EENG INVENTORY
//Sam Wehner
//EENG 221
//01/28/2017
#include <iostream>
#include <string>

using namespace std;
const int maxParts = 3;								
int partNumber;
string partName[maxParts];
string partLoc[maxParts];
int partQuant[maxParts];
int partsRemoved;

// Changed menuChoice to char as we discussed in class.

char menuChoice; 
//enum{ A=1, B=2};

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

	// Part Locations97\+
	partLoc[0] = "0101A";
	partLoc[1] = "0102A";
	partLoc[2] = "0103A";
	
	cout << "What would you like to do today?\n\n";
	cout << "To find a part press A and to exit the program press B";
		cin >> menuChoice;
	switch (menuChoice)
	{
	case 'A':
			do 
				{

					cout << "Type part Number or 0 to exit:\n";   
					cin >> partNumber;

// Porblem here when a 0 is typed in. It goes into the "else" block and looks for partName[-1]
// You might want to move the while up to here so it exits before looking for the part.

					if ((partNumber < 0) || (partNumber > maxParts)) //part not found
					{
						cout << "part not found.\n\n";
					}


					else // part found command string
					{
						cout << "part number: " << partNumber << " requested" <<"\n";
						cout << "part name: " << partName[partNumber-1]<< "\n";
						cout << "Quantity: " << partQuant[partNumber-1] << "pcs" << "\n";
						cout << "Location: "<< partLoc[partNumber-1]<<"\n\n";
						cout<< "How many parts are you removing? ";
						cin >> partsRemoved;
						 partQuant[partNumber-1] = partQuant[partNumber-1] - partsRemoved; //updates part quantity located in partQuant array
						 cout << partQuant[partNumber - 1]<<" parts remaining\n\n";
			 
					}
				}
			while (partNumber != 0);
				break;
	case 'B':
		
		break;
	}
 

	

	return 0;
}