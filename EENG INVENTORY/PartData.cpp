
#include "PartData.h"
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
				<< " Rack " << PL.Rack[i] << " Shelf " << PL.Shelf[i] << " Cabinet " << PL.Cabinet[i] << " has " << PI.partQuant[i] << " pieces left.\n\n";
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
			cout << "Part Number: " << partNumber << " requested" << "\n";
			cout<< "Model Number: " << PI.ModelNumber[partNumber - 1] << "\n";
			cout << "Description: " << PI.PartDescription[partNumber - 1] << "\n";
			cout << "Type: " << PI.PartType[partNumber - 1] << " " << "\n";
			cout << "Quantity: " << PI.partQuant[partNumber - 1] << " pcs\n";
			cout << "Room: " << PL.Room[partNumber - 1] << " Rack:" << " " << PL.Rack[partNumber - 1] << " Shelf:"
				<< " " << PL.Shelf[partNumber - 1] << " Cabinet:" << " " << PL.Cabinet[partNumber - 1] << "\n\n";

			 
		}
	}
	return(partNumber);
}
void PartData::SPSearch()
{
	string type;

	cout << "\n"<<"CN " << "connector" << "\n" << "EQ " << "Equipment" << "\n" << "RS " << "Resistor" << "\n" << "IC " << "Integrated Circuit" << "\n";
	cout << "What type list do would you like to see? **Input should look like 'CN'**\n";

	cin >> type;
	
		for (int i = 1; i <= maxParts; i++)
		{
			PI.PartType[i];

			if (type == PI.PartType[i])

			{
				cout << "\n";
				cout << "Part Number: " << i << "\n";
				cout << "Part Name: " << PI.PartDescription[i - 1] << "\n";
				cout << "Model Number: " << PI.ModelNumber[i - 1] << "\n";
				cout << "Part Quantity: " << PI.partQuant[i - 1] << "\n";
				cout << "Room: " << PL.Room[i - 1] << " Rack: " << " " << PL.Rack[i - 1] << " Shelf: " << " " << PL.Shelf[i - 1] << " Cabinet: " << " " << PL.Cabinet[i - 1] << " " << "\n\n";
			}
		}
	
}

//Data i/o Functions
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

//Accessors
	int PartData::getPartQuant(int i)
	{
		return(PI.partQuant[i]);
	}
	int PartData::getLowQuant(int i)
	{
		return(PI.LowQuant[i]);
	}
	string PartData::getModelNumber(int i)
	{
		return(PI.ModelNumber[i]);
	}
	string PartData::getPartDescription(int i)
	{
		return(PI.PartDescription[i]);
	}
	string PartData::getPartType(int i)
	{
		return(PI.PartType[i]);
	}
	string PartData::getRoom(int i)
	{
		return(PL.Room[i]);
	}
	int PartData::getRack(int i)
	{
		return(PL.Rack[i]);
	}
	int PartData::getShelf(int i)
	{
		return(PL.Shelf[i]);
	}
	int PartData::getCabinet(int i)
	{
		return(PL.Cabinet[i]);
	}
	   
	//Mutators
	void PartData::setpartQuant(int i)
	{
		PI.partQuant[i];
	}
	void PartData::setLowQuant(int i)
	{
		PI.LowQuant[i];
	}
	void PartData::setModelNumber(int i)
	{
		PI.ModelNumber[i];
	}
	void PartData::setPartDescription(int i)
	{
		PI.PartDescription[i];
	}
	void PartData::setPartType(int i)
	{
		PI.PartType[i];
	}
	void PartData::setRoom(int i)
	{
		PL.Room[i];
	}
	void PartData::setRack(int i)
	{
		PL.Rack[i];
	}
	void PartData::setShelf(int i)
	{
		PL.Shelf[i];
	}
	void PartData::setCabinet(int i)
	{
		PL.Cabinet[i];
	}

PartData::PartData()
{
	fetchFileData();// pulling in CSV file
	lowamnt();
}

PartData::~PartData()
{
	PushFileData();

	delete[] PI.PartDescription;
	delete[] PI.PartType;
	delete[] PI.ModelNumber;
	delete[] PL.Room;
	delete[] PL.Rack;
	delete[] PL.Shelf;
	delete[] PL.Cabinet;
	delete[] PI.partQuant;
	delete[] PI.LowQuant;
}
