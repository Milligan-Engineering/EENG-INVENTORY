#include "PartData.h"
#include "stdafx.h"
#include <fstream>
#include <cstdlib>

using namespace std;
//main functions
void PartData::PartRemoval()
{
	int partsRemoved;

	cout << "How many parts are you removing? ";
	cin >> partsRemoved;

	 while (partsRemoved > PI.partQuant[partNumber - 1])
	{
		cout << "parts removed greater than parts present.\n" << "enter a new number, \n";

		cout << "How many parts are you removing? ";
		cin >> partsRemoved;
	} 

	PI.partQuant[partNumber - 1] -= partsRemoved;  //updates part quantity located in partQuant array
	cout << PI.partQuant[partNumber - 1]<<" parts remaining\n\n";
	
}
	

void PartData::lowamnt()
{
	
	for (int i = 0; i < maxParts; i++)
	{
		if (PI.partQuant[i] <= PI.LowQuant[i])
		{
			cout << "**WARNING**\n " << " Part number " << i+1  << " " << PI.PartDescription[i] << " " << PI.PartType[i] << " in Room " << PL.Room[i]
				<< " Rack " << PL.Rack[i] << " Shelf " << PL.Shelf[i] << " Cabinet " << PL.Cabinet[i] << " has " << PI.partQuant[i] << " pieces left.\n";
		}
	}
}


void PartData::partIndex()
{
	for (int i = 1; i <= maxParts; i++)
	{

		cout << endl;
		cout << "Part Number: " << i << "\t";

		cout << "Part Name: " << PI.PartDescription[i - 1] << "\t";

		cout << "Part Description: " << PI.PartType[i - 1] << "\t";

		cout << "Model Number: " << PI.ModelNumber[i - 1] << "\t";

		cout << "Part Quantity: " << PI.partQuant[i - 1] << "\t";

		cout << "Room: " << PL.Room[i - 1] << "Rack: " << " " << PL.Rack[i - 1] << "Shelf: " << " " << PL.Shelf[i - 1] << "Cabinet: " << " " << PL.Cabinet[i - 1] << " " << "\n\n"; "\t\n\n";
	}
}


int PartData::partFind()
{

	cout << endl << "Type part number or 0 to exit to main menu: ";

	cin >> partNumber;
	if ((partNumber != 0))
	{
		if ((partNumber < 0) || (partNumber > maxParts))
		{
			cout << "Part not found.\n\n";
		}
		else if (partNumber != 0) //Part found
		{
			cout << endl;

			cout << "Part Number " << partNumber << " requested" << "\n";

			cout << "Name: " << PI.PartDescription[partNumber - 1] << "\n";

			cout << "Description: " << PI.PartType[partNumber - 1] << " " << "/n" << "Model Number: " << PI.ModelNumber[partNumber - 1] << "\n";

			cout << " Room: " << PL.Room[partNumber - 1] << " Rack:" << " " << PL.Rack[partNumber - 1] << " Shelf:"
				<< " " << PL.Shelf[partNumber - 1] << " Cabinet:" << " " << PL.Cabinet[partNumber - 1] << " " << "\n\n";

			cout << "Quantity: " << PI.partQuant[partNumber - 1] << " pcs" << "\n\n";
		}
	}
	return(partNumber);
}


int PartData::getPartQuant(int i)//accessor
{
	return(PI.partQuant[i]);
}

void PartData::SPSearch()
{
	char type[3];
	cout << "CN " << "connector" << "\n" << "EQ " << "Equipment" << "\n" << "RS " << "Resistor" << "\n" << "IC " << "Integrated Circuit" << "\n";
	cout << "What type list do would you like to see?";

	cin >> type;
	
	if ((type =="CN")|| (type =="EQ" )|| (type =="RS")||(type =="IC"))
	{
		for (int i = 1; i <= maxParts; i++)
		{
			PI.PartType[i];

			if (PI.PartType[i]== type)
			{

				cout << "Part Number: " << i - 1 << "\n";

				cout << "Part Name: " << PI.PartDescription[i - 1] << "\n";

				cout << "Model Number: " << PI.ModelNumber[i - 1] << "\n";

				cout << "Part Quantity: " << PI.partQuant[i - 1] << "\n";

				cout << " Room: " << PL.Room[i - 1] << " Rack: " << " " << PL.Rack[i - 1] << " Shelf: " << " " << PL.Shelf[i - 1] << " Cabinet: " << " " << PL.Cabinet[i - 1] << " " << "\n\n";

			}
		}
	}
}

//Data in/out Functions
int PartData::PushFileData()
{
	ofstream outDataStream;
	outDataStream.open("mainInventoryData.csv");

	if (outDataStream.fail())
	{
		cout << "Output file stream open failed \n";
		return(0);
	}
	outDataStream << " Number,";
	outDataStream << "Model Number,";
	outDataStream << "Description,";
	outDataStream << "Type,";
	outDataStream << "Quantity,";
	outDataStream << "Low Quantity,";
	outDataStream << "Room,";
	outDataStream << "Rack,";
	outDataStream << "Shelf,";
	outDataStream << "Cabinet" << "\n";

	for (int i = 0; i < maxParts; i++) // Save part name
	{
		outDataStream << i+1 << ",";

		outDataStream << PI.ModelNumber[i] << ",";

		outDataStream << PI.PartDescription[i] << ",";

		outDataStream << PI.PartType[i] << ",";

		outDataStream << PI.partQuant[i] << ",";

		outDataStream << PI.LowQuant[i] << ",";

		outDataStream << PL.Room[i] << ",";

		outDataStream << PL.Rack[i] << ",";

		outDataStream << PL.Shelf[i] << ",";

		outDataStream << PL.Cabinet[i] << "\n";

	}

	outDataStream.close();
	return(0);
}

int PartData::fetchFileData()
{

	int j=0;
	char getChar;
	ifstream inDataStream;

	inDataStream.open("mainInventoryData.csv");

	if (inDataStream.fail())
	{
		cout << "Input file stream open failed \n";
		return(1);
	}

	while (!inDataStream.eof()) 
	{
		for (int i = 0; i < 10; i++)
		{
			getChar = readValue(inDataStream, testArray);
		}
		getChar = readValue(inDataStream, testArray);
		if (!inDataStream.eof())
		{
			j++;
		}
	}

	inDataStream.close();

	inDataStream.open("mainInventoryData.csv");

	if (inDataStream.fail())
	{
		cout << "Input file stream open failed \n";
		return(1);
	}

	maxParts = j;

	PI.PartDescription = new string[maxParts];
	PI.PartType = new string[maxParts];
	PI.ModelNumber = new string[maxParts];
	PL.Room = new string[maxParts];
	PL.Rack = new int[maxParts];
	PL.Shelf = new int[maxParts];
	PL.Cabinet = new int[maxParts];
	PI.partQuant = new int[maxParts];
	PI.LowQuant = new int[maxParts];

	for (int i = 0; i < 10; i++)
	{
		getChar = readValue(inDataStream, testArray);
	}

	for (int i =0; i < maxParts; i++)
	{
		char testArray[100];

		getChar = readValue(inDataStream, testArray);// Read part #
		partNumber = atoi(testArray);

		getChar = readValue(inDataStream, testArray); // Read part Model Number
		PI.ModelNumber[i] = testArray;

		getChar = readValue(inDataStream, testArray);// Read part name
		PI.PartDescription[i] = testArray;

		getChar = readValue(inDataStream, testArray);// Read Description
		PI.PartType[i] = testArray;

		getChar = readValue(inDataStream, testArray);// Read part quantity
		PI.partQuant[i] = atoi(testArray);

		getChar = readValue(inDataStream, testArray);// Read low quant
		PI.LowQuant[i] = atoi(testArray);

		getChar = readValue(inDataStream, testArray);// Read part Room
		PL.Room[i] = testArray;

		getChar = readValue(inDataStream, testArray);// Read part Rack
		PL.Rack[i] = atoi(testArray);

		getChar = readValue(inDataStream, testArray);// Read part Shelf
		PL.Shelf[i] = atoi(testArray);

		getChar = readValue(inDataStream, testArray);// Read part Cabinet
		PL.Cabinet[i] = atoi(testArray);
	}


	return 0;

}

char PartData::readValue(ifstream& inputStream, char cell[])
{

	char getChar;
	inputStream.get(getChar);
	int j = 0;
	while ((getChar != ',') && (getChar != '\n') && !inputStream.eof())
	{
		cell[j] = getChar;
		j++;
		inputStream.get(getChar);
	}
	cell[j] = '\0';
	return(getChar);
}
//precondition: 
//postcondidtion: reads value of cell[j] and puts value into array of type char



//initializing
PartData::PartData()
{
	
}

PartData::~PartData()
{
}

/*void PartData::setlowQuant(int i)//Mutator
{
LowQuant[i] ;
}
*/


/*void PartData::PrintList()
{
{
int choice;
cout << "Type 1 if you would like to save this part information: ";
cin >> choice;
if (choice == 1)
{
partInfo.open("Datasheet.txt");
if (partInfo.fail())
{
cout << "File failed to open";
char wait;
cin >> wait;
exit(1);
}

partInfo << partNumber << " " << PI.PartDescription[partNumber - 1] << " " << PI.PartType[partNumber - 1]
<< " " << PI.partQuant[partNumber - 1] << " " << PL.Room[partNumber - 1] << " " << PL.Rack[partNumber - 1]
<< " " << PL.Shelf[partNumber - 1] << " " << PL.Cabinet[partNumber - 1];

partInfo.close();
}

} while (partNumber != 0);
}
//precondition:
//postcondidtion:
*/


/*void PartData::setlowQuant(int i)//Mutator
{
LowQuant[i] ;
}
*/