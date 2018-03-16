//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
//sjwehner@my.milligan.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 03/15/2018

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void partIndex(string partType[], string partName[], int partQuant[], string partLoc[], const int maxParts); //listprint
//Displays output of part numbers, Names, Quantities, and locations.
//Only displays iformation for valid parts
//void quantitySort(int partQuant[], int Order[]);

void lowamnt(int partQuant[], string partName[], string partType[], string partLoc[], int quantityLow, const int maxParts);
void search(int i, string partType[], char choice, const int maxParts);//capacitor

int main()
{
	const int maxParts = 3;
	const int quantityLow = 20;

	ifstream LABFILES;
	ifstream partInfo;
	ofstream partData;
	string partType[maxParts];
	string partName[maxParts];
	int partQuant[maxParts];
	string partLoc[maxParts];
	int partNumber; //(partNumber-1) serves as an index to look up information for each part in the part arrays

	//Part types
	partType[0] = "capacitor";
	partType[1] = "resistor";
	partType[2] = "transistor";
	//Part names
	partName[0] = "100uF electrolytic";
	partName[1] = "1.5kOhm, 0.25W carbon film";
	partName[2] = "2N5401 PNP silicon";
	//Part quantities
	partQuant[0] = 20;
	partQuant[1] = 60;
	partQuant[2] = 80;
	//Part locations
	partLoc[0] = "0101A";
	partLoc[1] = "0102A";
	partLoc[2] = "0103A";

	cout << "Low parts:\n";
	lowamnt(partQuant, partName, partType, partLoc, quantityLow, maxParts);
	cout << "\n\n";

	char menuChoice;

	do
	{
		cout << endl;
		cout << "What would you like to do today? \n\n";
		cout << "To find a part press P\n";
		cout << "To access part list press I \n";
		cout << "To find class index press S\n";
		cout << "To get lab instructions press L\n";
		cout << "To exit press E\n\n";

		cin >> menuChoice;
		switch (menuChoice)
		{
		case 'P':
		case 'p':
			do
			{
				int partsRemoved;
				cout << endl << "Type part number or 0 to exit to main menu: ";
				cin >> partNumber;

				if ((partNumber < 0) || (partNumber > maxParts))
				{
					cout << "Part not found.\n\n";
				}
				else if (partNumber != 0) //Part found
				{
					cout << endl;
					cout << "Part Number " << partNumber << " requested" << "\n";
					cout << "Type: " << partType[partNumber - 1] << "\n";
					cout << "Name: " << partName[partNumber - 1] << " " << partType[partNumber - 1] << "\n";
					cout << "Quantity: " << partQuant[partNumber - 1] << " pcs" << "\n";
					cout << "Location: " << partLoc[partNumber - 1] << "\n\n";

					//add a check here to make sure that partsRemoved is not greater than the number of parts in stock - Casey
					cout << "How many parts are you removing? ";
					cin >> partsRemoved;
					partQuant[partNumber - 1] = partQuant[partNumber - 1] - partsRemoved; //updates part quantity located in partQuant array
					cout << partQuant[partNumber - 1] << " parts remaining\n\n";

					int choice;
					cout << "Type 1 if you would like to save this part information: ";
					cin >> choice;
					if (choice == 1) //had (choice = 1), cause infinite loop - Casey
					{
						partData.open("Datasheet.txt");
						if (partData.fail())
						{
							cout << "File failed to open";
							char wait;
							cin >> wait;
							exit(1);
						}
						partData << partNumber << " " << partName[partNumber - 1] << " " << partType[partNumber - 1]
							<< " " << partQuant[partNumber - 1] << " " << partLoc[partNumber - 1];
						partData.close();
					}
				}
			} while (partNumber != 0);
			break;

		case 'I':
		case 'i':
			partIndex(partName, partType, partQuant, partLoc, maxParts);
			break;

		case 'S'://Specific typ search
		case 's':
			char choice;
			cout << "Part type search\n" << "What type of part word you like to find?";
			cout << "For capacitors type C ";
			cout << "For Transisters type T ";
			cout << "For Resisters type R ";
			cin >> choice;
			switch(choice)
				case 'C':
				case'c':
					search(i, partType, choice, maxParts);
					break;
				case 't':
				case'T':

					break;
				case 'R':
				case'r':

					break;
			
			break;

		case 'L':
		case 'l':
			cout << endl;
			LABFILES.open("LAB1.txt"); //this option allows for the user to acess the labs
			if (LABFILES.fail())
			{
				cout << "Lab file failed to open";
				char wait;
				cin >> wait;
				exit(1);
			}

			char cstring[30];
			for (int i = 0; i < 30; i++)
			{
				LABFILES.get(cstring[i]);
				if (LABFILES.eof()) //Stop the loop when the end of the file has been reached - Casey
				{
					break;
				}
				else
				{
					cout << cstring[i]; //Now prints just one character at a time instead of the entire array every loop iteration - Casey
				}
			}
			cout << endl;

			LABFILES.close();
			break;

		case 'E':
		case 'e':
			break;

		default:
			cout << "Not a valid menu choice.\n\n";
		}

	} while ((menuChoice != 'E') && (menuChoice != 'e')); 

	return 0;
}

void partIndex(string partName[], string partType[], int partQuant[], string partLoc[], const int maxParts)
{
	for (int i = 1; i <= maxParts; i++)
	{
		
		cout << endl;
		cout << "Part Number: " << i << "\t";
		cout << "Part Type: " << partType[i - 1] << "\t";
		cout << "Part Name: " << partName[i - 1] << " " << partType[i - 1] << "\t";
		cout << "Part Quantity: " << partQuant[i - 1] << "\t";
		cout << "Part Location: " << partLoc[i - 1] << "\t\n\n";
	}
}

void lowamnt(int partQuant[], string partName[], string partType[], string partLoc[], int quantityLow, const int maxParts)
{
	int i=0;
	for (partQuant[i] >= quantityLow; i<=maxParts )
		if (partQuant[i] = quantityLow)
		{
			cout << "**WARNING**" << "Part number " << i << partName[i] << partType[i] << "in location" << partLoc[i] << "has" << partQuant[i] << "pieces left.";
		}
		else
			i++;
}

void search(int i, string partType[], char choice,const int maxParts)//capacitor
{
	int i = 0;
	bool found=false;
	if (choice = 'C' || 'c')
	{
		choice = "capacitor";
	}
	while ((!found) && (i <= maxParts))
		if ("capacitor" == partType[i])
		{
			found = true;
		}
	
		else
		{
			i++;
		}
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