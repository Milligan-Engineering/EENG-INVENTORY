//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
//sjwehner@my.milligan.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 04/02/2018

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "PartData.h"

using namespace std;
const int maxParts = 3;
char testArray[45];


void PartRemoval(int partsRemoved, int partQuant[], int partNumber);

int fetchFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts);

int pushFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts);

char readValue(ifstream& inputStream, char cell[]);

//void partFind(string partName[], string partType[], int partQuant[], string partLoc[], const int maxParts, int partNumber);

void partIndex(string partType[], string partName[], int partQuant[], string partLoc[], const int maxParts); //listprint
//Displays output of part numbers, Names, Quantities, and locations.
//Only displays iformation for valid parts
//void quantitySort(int partQuant[], int Order[]);

void lowamnt(int partQuant[], string partName[], string partType[], string partLoc[], int quantityLow, const int maxParts);
//precondition: partQuant array to be populated.
//Postcondiitions: this prints a list of parts whose quantity is below the 20pcs(can be adjusted) threshhold.

//the next void functions are search functions for part types i.e. Tansistors, resistors, and capacitors.
//the require a menu choice and use that to search through the array for Tansistors, resistors, and capacitors.
// they output the parts that met the criteria of which part type you chose
/*void Csearch(int i, string partType[], char choice, const int maxParts);//capacitor
void Tsearch(int i, string partType[], char choice, const int maxParts);//Transisitor
void Rsearch(int i, string partType[], char choice, const int maxParts);//Resistor*/
int main()
{
	const int quantityLow = 20;
	ifstream LABFILES;
	ifstream partInfo;
	ifstream inDataStream;
	ofstream partData;
	ofstream outDatastream;
	string partType[maxParts];
	string partName[maxParts];
	string partLoc[maxParts];
	int partQuant[maxParts];
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
	partQuant[2] = 19;
	//Part locations
	partLoc[0] = "0101A";
	partLoc[1] = "0102A";
	partLoc[2] = "0103A";

	fetchFileData(partName, partType, partQuant, partLoc, maxParts);

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
			//partFind(partName, partType, partQuant, partLoc, maxParts, partNumber);
			do
			{
				
				cout << endl << "Type part number or 0 to exit to main menu: ";
				cin >> partNumber;

				if ((partNumber < 0) || (partNumber > maxParts))
				{
					cout << "Part not found.\n\n";
				}
				else if (partNumber != 0) //Part found
				{
					int partsRemoved;
					cout << endl;
					cout << "Part Number " << partNumber << " requested" << "\n";
					cout << "Type: " << partType[partNumber - 1] << "\n";
					cout << "Name: " << partName[partNumber - 1] << " " << partType[partNumber - 1] << "\n";
					cout << "Quantity: " << partQuant[partNumber - 1] << " pcs" << "\n";
					cout << "Location: " << partLoc[partNumber - 1] << "\n\n";
					PartRemoval(partsRemoved, partQuant, partNumber);
					/*mutator
					cout << "How many parts are you removing? ";
					cin >> partsRemoved;
					if (partsRemoved > partQuant[partNumber - 1])
					{
						cout << "parts removed greater than parts present.\n" << "enter a new number.";
					}
					partQuant[partNumber - 1] = partQuant[partNumber - 1] - partsRemoved; //updates part quantity located in partQuant array//add accesseor andmutator function here
					cout << partQuant[partNumber - 1] << " parts remaining\n\n";
					*/
					/*int choice;
					cout << "Type 1 if you would like to save this part information: ";
					cin >> choice;
					if (choice == 1)
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
					}*/
				}
			} while (partNumber != 0);
		
			break;

		case 'I':
		case 'i':

			partIndex(partName, partType, partQuant, partLoc, maxParts);
			break;

		case 'S'://Specific type search
		case 's':
			//string choice;
			cout << "Part type search\n" << "What type of part word you like to find?";
			cout << "For capacitors type C ";
			cout << "For Transisters type T ";
			cout << "For Resisters type R ";
			//cin >> choice;
		/*	switch(choice)
				case 'C':
				case'c':
					Csearch(i, partType, choice, maxParts);
					break;
				case 't':
				case'T':
					Tsearch(i, partType, choice, maxParts);
					break;
				case 'R':
				case'r':
					Rsearch(i, partType, choice, maxParts);
					break;*/
			
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
	pushFileData(partName, partType, partQuant, partLoc, maxParts);
	return 0;
}

/*void partFind(string partName[], string partType[], int partQuant[], string partLoc[], const int maxParts, int partNumber)
{
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
			}
		}
	} while (partNumber != 0);
}
*/

void PartRemoval(int partsRemoved, int partQuant[], int partNumber)
{
	

	cout << "How many parts are you removing? ";
	cin >> partsRemoved;
	if (partsRemoved > partQuant[partNumber - 1])
	{
		cout << "parts removed greater than parts present.\n" << "enter a new number.";
	}
	partQuant[partNumber - 1] = partQuant[partNumber - 1] - partsRemoved; //updates part quantity located in partQuant array//add accesseor and mutator function here
	cout << partQuant[partNumber - 1] << " parts remaining\n\n";
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
	int i = 0;
	for (i = 0; i < maxParts; i++)
	{
		if (partQuant[i] <= quantityLow)
		{
			cout << "**WARNING**\n " << " Part number " << i+1 << " " << partName[i] << " " << partType[i] << " in location " << partLoc[i] << " has " << partQuant[i] << " pieces left.\n";
		}


	}
}



int pushFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts)
{
	ofstream outDataStream;
	outDataStream.open("mainInventoryData.csv");
	if (outDataStream.fail())
	{
		cout << "Output file stream open failed \n";
		return(1);
	}
	outDataStream << "Part Number, ";
	for (int i = 0; i < maxParts; i++) // Save part name
	{
		outDataStream << i << ",";
	}
	outDataStream << "\n";
	outDataStream << "Name, ";
	for (int i = 0; i < maxParts; i++) // Save part name
	{
		outDataStream << partName[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Type, ";
	for (int i = 0; i < maxParts; i++) // Save part type
	{
		outDataStream << partType[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Quantity, ";
	for (int i = 0; i < maxParts; i++) // Save part quant
	{
		outDataStream << partQuant[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Location, ";
	for (int i = 0; i < maxParts; i++) // Save part location
	{
		outDataStream << partLoc[i] << ",";
	}
	outDataStream << "\n";


	outDataStream << "\n";
	outDataStream.close();
	return(0);
}

char readValue(ifstream& inputStream, char cell[])
{
	char getChar;
	inputStream.get(getChar);
	int j = 0;
	while ((getChar != ',') && (getChar != '\n'))
	{
		cell[j] = getChar;
		j++;
		inputStream.get(getChar);
	}
	cell[j] = '\0';
	return(getChar);
}

int fetchFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts)
{
	//	int val;
	char getChar;
	ifstream inDataStream;
	inDataStream.open("mainInventoryData.csv");
	if (inDataStream.fail())
	{
		cout << "Input file stream open failed \n";
		return(1);
	}
	getChar = readValue(inDataStream, testArray);// Read part #

	for (int i = 0; i < maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
	}
	getChar = readValue(inDataStream, testArray);// Read part name

	for (int i = 0; i < maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partName[i] = testArray;
	}
	getChar = readValue(inDataStream, testArray); // Read part type

	for (int i = 0; i < maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partType[i] = testArray;
	}
	getChar = readValue(inDataStream, testArray);// Read part quantity
	for (int i = 0; i < maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partQuant[i] = atoi(testArray);
	}
	getChar = readValue(inDataStream, testArray); // Read part Location

	for (int i = 0; i < maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partLoc[i] = testArray;
	}
	return(0);
}


/*
void Csearch(int i, string partType[], string choice, const int maxParts)//capacitor
{
	int i = 0;
	bool found = false;
	if (choice == "C" ||(choice == "c"))
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
void Tsearch(int i, string partType[], string choice, const int maxParts)//Transistor
{
	int i = 0;
	bool found = false;
	if (choice = "T" || "t")
	{
		choice = "transistor";
	}
	while ((!found) && (i <= maxParts))
		if ("transistor" == partType[i])
		{
			found = true;
		}

		else
		{
			i++;
		}
}
void Rsearch(int i, string partType[], string choice, const int maxParts)// Resistor
{
	int i = 0;
	bool found = false;
	if (choice = 'R' || 'r')
	{
		choice = "resistor";
	}
	while ((!found) && (i <= maxParts))
		if ("resistor" == partType[i])
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