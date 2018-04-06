#include "PartData.h"
#include <iostream>
#include <string>

using namespace std;

void PartData::PartRemoval()
{
	int partsRemoved; 

	cout << "How many parts are you removing? ";
	cin >> partsRemoved;
	if (partsRemoved > partQuant[partNumber - 1])
	{
		cout << "parts removed greater than parts present.\n" << "enter a new number.";
	}
	partQuant[partNumber - 1] = partQuant[partNumber - 1] - partsRemoved; //updates part quantity located in partQuant array//add accesseor and mutator function here
	cout << partQuant[partNumber - 1] << " parts remaining\n\n";
}

void PartData::lowamnt()
{
	int i = 0;
	for (i = 0; i < maxParts; i++)
	{
		if (partQuant[i] <= quantityLow)
		{
			cout << "**WARNING**\n " << " Part number " << i + 1 << " " << partName[i] << " " << partType[i] << " in location " << partLoc[i] << " has " << partQuant[i] << " pieces left.\n";
		}


	}
}

void PartData::partIndex()
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

void PartData::partFind()
{
	//int partNumber;
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

PartData::PartData()
{


}


PartData::~PartData()
{
}