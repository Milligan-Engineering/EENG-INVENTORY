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
		if (partQuant[i] = PI.LowQuant[i])
		{
			cout << "**WARNING**\n " << " Part number " << i + 1 << " " << PI.PartDescription[i] << " " << PI.PartType[i] << " in Room " << PL.Room[i]<< "Rack " << PL.Rack[i]<<"Shelf "<< PL.Shelf[i] <<"Cabinet"<< PL.Cabinet[i] << " has " << partQuant[i] << " pieces left.\n";
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

		cout << "Part Name: " << PI.PartDescription[i - 1] << "\t";
		 
		cout << "Part Description: " << PI.PartType[i - 1]<<"\t";

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

		cout << "Name: " << PI.PartDescription[partNumber - 1] << "\n";

		cout << "Description: " << PI.PartType[partNumber - 1] << " " << "/n"<< "Model Number: " << PI.ModelNumber[partNumber - 1] << "\n";

		cout << "Location: "<< "Room: " << PL.Room[partNumber - 1] <<"Rack: "<<" "<< PL.Rack[partNumber - 1]<<"Shelf: "<<" "<< PL.Shelf[partNumber - 1]<<"Cabinet: "<< " "<< PL.Cabinet[partNumber - 1]<<" "<<"\n\n";

		cout << "Quantity: " << partQuant[partNumber - 1] << " pcs" << "\n";
	}
}	
//precondition:
//postcondidtion:

int PartData::getPartQuant(int i)//accessor
{
	return(partQuant[i]);
}
//precondition:
//postcondidtion:

/*void PartData::setlowQuant(int i)//Mutator
{
	LowQuant[i] ;
}
*/
//Data transfer Functions
int PartData::PushFileData()
{
	ofstream outDataStream;
	outDataStream.open("mainInventoryData.csv");

if (outDataStream.fail())
	{
		cout << "Output file stream open failed \n";
		return(1);
	}


	outDataStream << " Number,";
	outDataStream << "Name,";
	outDataStream << "Description,";
	outDataStream << "Model Number,";
	outDataStream << "Room,";
	outDataStream << "Rack,";
	outDataStream << "Shelf,";
	outDataStream << "Cabinet,";
	outDataStream<< "Quantity,"<<"\n";

	

	for (int i = 0; i < maxParts; i++) // Save part name
	{
		outDataStream << i << ",";

		outDataStream << PI.PartDescription[i] << ",";

		outDataStream << PI.PartType[i] << ",";

		outDataStream << PI.ModelNumber[i] << ",";

		outDataStream << PL.Room[i]<< ",";

		outDataStream << PL.Rack[i] << ",";

		outDataStream << PL.Shelf[i]<< ",";

		outDataStream << PL.Cabinet[i] << ",";

		outDataStream << partQuant[i]<< "\n";

	}

	outDataStream.close();
	return(0);
}






int PartData::fetchFileData()
{
	int i = 0;

	char getChar;
	ifstream inDataStream;
	inDataStream.open("mainInventoryData.csv");

	if (inDataStream.fail())
	{
		cout << "Input file stream open failed \n";
		return(1);
	}

	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);
	getChar = readValue(inDataStream, testArray);

	while (i<=20)//(!inDataStream.eof())
	{

		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);

		i++;

	}
	inDataStream.close("mainInventoryData.csv");

	{
		inDataStream.open("mainInventoryData.csv");

		if (inDataStream.fail())
		{
			cout << "Input file stream open failed \n";
			return(1);
		}
		maxParts= 20;

		PI.PartDescription = new string[maxParts];
		PI.PartType = new string[maxParts];
		PI.ModelNumber = new string[maxParts];
		PL.Room = new string[maxParts];
		PL.Rack = new int[maxParts];
		PL.Shelf = new int[maxParts];
		PL.Cabinet = new int[maxParts];
		partQuant = new int[maxParts];

		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);
		getChar = readValue(inDataStream, testArray);

		for (int i = 0; i < maxParts; i++)
		{
			char testArray[45];

			getChar = readValue(inDataStream, testArray);// Read part #
			partNumber = atoi(testArray);

			getChar = readValue(inDataStream, testArray); // Read part Model Number
			PI.ModelNumber[i] = testArray;

			getChar = readValue(inDataStream, testArray);// Read part name
			PI.PartDescription[i] = testArray;

			getChar = readValue(inDataStream, testArray);// Read Description
			PI.PartType[i] = testArray;

			getChar = readValue(inDataStream, testArray);// Read part Room
			PL.Room[i] = testArray;

			getChar = readValue(inDataStream, testArray);// Read part Rack
			PL.Rack[i] = atoi(testArray);

			getChar = readValue(inDataStream, testArray);// Read part Shelf
			PL.Shelf[i] = atoi(testArray);

			getChar = readValue(inDataStream, testArray);// Read part Cabinet
			PL.Cabinet[i] = atoi(testArray);

			getChar = readValue(inDataStream, testArray);// Read part quantity
			partQuant[i] = atoi(testArray);

			getChar = readValue(inDataStream, testArray);// Read low quant
			PI.LowQuant[i] = atoi(testArray);

		}
	}
	
	return 0;

}


char PartData::readValue(ifstream& inputStream, char cell[]) 
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

void PartData::PrintList()
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
				<< " " << partQuant[partNumber - 1] << " " << PL.Room[partNumber - 1] << " " << PL.Rack[partNumber - 1]
				<< " " << PL.Shelf[partNumber - 1] << " " << PL.Cabinet[partNumber - 1];

			partInfo.close();
		}

	} while (partNumber != 0);
}




//initializing
PartData::PartData()
{
	/*
	//Part quantities
	partQuant[0] = 95;
	partQuant[1] = 9;
	partQuant[2] = 5;

	//Low Quants
	PI.LowQuant[0] = 20;
	PI.LowQuant[1] = 1;
	PI.LowQuant[2] = 25;


	//Part names
	PI.PartDescription[0] = "100uF electrolytic";// changed part name to part descripton
	PI.PartDescription[1] = "Oscillascope";
	PI.PartDescription[2] = ".5in";

	//Part Room
	PL.Room[0] = "L01";
	PL.Room[1] = "L02";
	PL.Room[2] = "L03";
	//Part Rack
	PL.Rack[0] = 1;
	PL.Rack[1] = 2;
	PL.Rack[2] = 3 ;

	//Part Shelf
	PL.Shelf[0] =1;
	PL.Shelf[1] =2;
	PL.Shelf[2]= 3;
	//Part Cabinet
	PL.Cabinet[0]=1;
	PL.Cabinet[1]=2;
	PL.Cabinet[2]=3;
	//Part Description
		//**Conventions**
		//IC: Integrated Circuit
		//EQ: Equipment
		//RS: Resistor
		//CN: Connector
	PI.PartType[0] ="RS" ; //changed from description to type
	PI.PartType[1] ="EQ";
	PI.PartType[2] ="CN";
	//Part Model NUmber
	PI.ModelNumber[0]="005A";
	PI.ModelNumber[1]="0202CB";
	PI.ModelNumber[2]="TI247";
	*/
}


PartData::~PartData()
{
}