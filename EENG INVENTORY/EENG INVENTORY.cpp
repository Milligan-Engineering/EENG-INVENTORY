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

//char testArray[45];

	




int main()
{
	ifstream inDataStream;
	
	ifstream partInfo;
	PartData PartDataObject;
	ifstream LABFILES;
	ofstream partData;
	//fetchFileData(PartDataObject);//fetches CSV for program

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
					PartDataObject.partFind();
					PartDataObject.PartRemoval();
					/*
					int choice;
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
					}
					*/
			} while (PartDataObject.partNumber != 0);
			break;

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
		*/
			break;

		case 'L':
		case 'l':// A test lab file is stored this calls it an dprints it to the console
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
				if (Datastreamflow.LABFILES.eof()) //Stop the loop when the end of the file has been reached - Casey
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
			//Exit program choice (**closes program**)
			break;

		default:
			cout << "Not a valid menu choice.\n\n";
		}

	} while ((menuChoice != 'E') && (menuChoice != 'e')); 

	//pushFileData(PartDataObject);//pushes and stores CSV for program
	PartDataObject.PushFileData();

	delete [] PartDataObject.testArray;

	return 0;
	}

 /*int pushFileData(PartData partstuff)
{
	ofstream outDataStream;
	outDataStream.open("mainInventoryData.csv");
	if (outDataStream.fail())
	{
		cout << "Output file stream open failed \n";
		return(1);
	}
	outDataStream << "Part Number, ";
	for (int i = 0; i < partstuff.maxParts; i++) // Save part name
	{
		outDataStream << i << ",";
	}
	outDataStream << "\n";
	outDataStream << "Name, ";
	for (int i = 0; i < partstuff.maxParts; i++) // Save part name
	{
		outDataStream << partstuff.partName[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Type, ";
	for (int i = 0; i < partstuff.maxParts; i++) // Save part type
	{
		outDataStream << partstuff.partType[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Quantity, ";
	for (int i = 0; i < partstuff.maxParts; i++) // Save part quant
	{
		outDataStream << partstuff.partQuant[i] << ",";
	}
	outDataStream << "\n";
	outDataStream << "Location, ";
	for (int i = 0; i < partstuff.maxParts; i++) // Save part location
	{
		outDataStream << partstuff.partLoc[i] << ",";
	}
	outDataStream << "\n";


	outDataStream << "\n";
	outDataStream.close();
	return(0);
}
*/

/*
 int fetchFileData(PartData partstuff)
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

	for (int i = 0; i < partstuff.maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
	}
	getChar = readValue(inDataStream, testArray);// Read part name

	for (int i = 0; i < partstuff.maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partstuff.partName[i] = testArray;
	}
	getChar = readValue(inDataStream, testArray); // Read part type

	for (int i = 0; i < partstuff.maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partstuff.partType[i] = testArray;
	}
	getChar = readValue(inDataStream, testArray);// Read part quantity
	for (int i = 0; i < partstuff.maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partstuff.partQuant[i] = atoi(testArray);
	}
	getChar = readValue(inDataStream, testArray); // Read part Location

	for (int i = 0; i < partstuff.maxParts; i++)
	{
		getChar = readValue(inDataStream, testArray);
		partstuff.partLoc[i] = testArray;
	}
	return(0);
}



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