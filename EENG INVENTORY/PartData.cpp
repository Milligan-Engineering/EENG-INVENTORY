#include "PartData.h"
#include <iostream>
#include <string>

void PartData::PartRemoval(int partsRemoved, int partQuant[], int partNumber)
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

void PartData::lowamnt(int partQuant[], string partName[], string partType[], string partLoc[], int quantityLow, const int maxParts)
{
	int i = 0;
	for (i = 0; i < maxParts; i++)
	{
		if (partQuant[i] <= quantityLow)
		{
			cout<< "**WARNING**\n " << " Part number " << i + 1 << " " << partName[i] << " " << partType[i] << " in location " << partLoc[i] << " has " << partQuant[i] << " pieces left.\n";
		}


	}
}

void PartData::partIndex(string partName[], string partType[], int partQuant[], string partLoc[], const int maxParts)
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

PartData::PartData()
{


}


PartData::~PartData()
{
}
