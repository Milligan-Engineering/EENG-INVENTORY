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
//precondition:
//postcondidtion:
void PartData::lowamnt()
{
	int i = 0;
	for (i = 0; i < maxParts; i++)
	{
		if (partQuant[i] <= quantityLow)
		{
			cout << "**WARNING**\n " << " Part number " << i + 1 << " " << PI.partName[i] << " " << PI.PartDescription[i] << " in Room " << PL.Room[i]<< "Rack " << PL.Rack[i]<<"Shelf "<< PL.Shelf[i] <<"Cabinet"<< PL.Cabinet[i] << " has " << partQuant[i] << " pieces left.\n";
		}


	}
}
//precondition: partQuant array to be populated.
//postcondidtion: this prints a list of parts whose quantity is below the 20pcs(can be adjusted) threshhold.
void PartData::partIndex()
{
	for (int i = 1; i <= maxParts; i++)
	{

		cout << endl;
		cout << "Part Number: " << i << "\t";

		cout << "Part Name: " << PI.partName[i - 1] << "\t";
		 
		cout << "Part Description: " << PI.PartDescription[i - 1]<<"\t";

		cout<< "Model Number: "<< PI.ModelNumber[i - 1] << "\t";

		cout << "Part Quantity: " << partQuant[i - 1] << "\t";

		cout << "Room: " << PL.Room[i - 1] << "Rack: " << " " << PL.Rack[i - 1] << "Shelf: " << " " << PL.Shelf[i - 1] << "Cabinet: " << " " << PL.Cabinet[i - 1] << " " << "\n\n"; "\t\n\n";
	}
}
//precondition:
//postcondidtion:

void PartData::partFind()
{
	
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

		cout << "Name: " << PI.partName[partNumber - 1] << "\n";

		cout << "Description: " << PI.PartDescription[partNumber - 1] << " " << "/n"<< "Model Number: " << PI.ModelNumber[partNumber - 1] << "\n";

		cout << "Location: "<< "Room: " << PL.Room[partNumber - 1] <<"Rack: "<<" "<< PL.Rack[partNumber - 1]<<"Shelf: "<<" "<< PL.Shelf[partNumber - 1]<<"Cabinet: "<< " "<< PL.Cabinet[partNumber - 1]<<" "<<"\n\n";

		cout << "Quantity: " << partQuant[partNumber - 1] << " pcs" << "\n";
	}
}
//precondition:
//postcondidtion:

string PartData::getPartQuant(int i)//accessor
{
	return(partQuant[i]);
}
//precondition:
//postcondidtion:

int pushFileData();
{
	ofstream outDataStream;
	outDataStream.open("mainInventoryData.csv");

	outDataStream << " Number, ";
	outDataStream << "Name, ";
	outDataStream << "Description, ";
	outDataStream << "Model Number, ";
	outDataStream << "Room, ";
	outDataStream << "Rack, ";
	outDataStream << "Shelf, ";
	outDataStream << "Cabinet, ";

	if (outDataStream.fail())
	{
		cout << "Output file stream open failed \n";
		return(1);
	}

	for (int i = 0; i < maxParts; i++) // Save part name
	{
		outDataStream << i << ",";

		outDataStream << PI.partName[i] << ",";

		outDataStream << PI.PartDescription[i] << ",";

		outDataStream << PI.ModelNumber[i] << ",";

		outDataStream << PL.Room[i]<< ",";

		outDataStream << PL.Rack[i] << ",";

		outDataStream << PL.Shelf[i]<< ",";

		outDataStream << PL.Cabinet[i] << ",";

		outDataStream <<partQuant[i];

	}
}

void PartData::setlowQuant(int i)//Mutator
{
	quantityLow = i;
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


PartData::PartData()
{
	//Part quantities
	partQuant[0] = 20;
	partQuant[1] = 60;
	partQuant[2] = 19;

	//Part names
	partName[0] = "100uF electrolytic";
	partName[1] = "Oscillascope";
	partName[2] = ".5in";

	//Part Room
	Room[0] = "1";
	Room[1] = "2";
	Room[2] = "3";
	//Part Rack
	Rack[0] = "1";
	Rack[1] = "2";
	Rack[2] ="3" ;

	//Part Shelf
	Shelf[0] ="1";
	Shelf[1] ="2";
	Shelf[2]= "3";
	//Part Cabinet
	Cabinet[0]="1";
	Cabinet[1]="2";
	Cabinet[2]="3";
	//Part Description
		//**Conventions**
		//IC: Integrated Circuit
		//EQ: Equipment
		//RS: Resistor
		//CN: Connector
	PartDescription[0] ="RS" ;
	PartDescription[1] ="EQ";
	PartDescription[2] ="CN";
	//Part Model NUmber
	ModelNumber[0]="005A";
	ModelNumber[1]="0202CB";
	ModelNumber[2]="TI247";
	
}


PartData::~PartData()
{
}