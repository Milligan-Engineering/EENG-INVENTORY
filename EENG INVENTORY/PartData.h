#pragma once
#include "stdafx.h"
#include <fstream>
#include <cstdlib>

using namespace std;
//pointers
typedef string * StrPtr;
typedef int * IntPtr;

struct PartInfo
{
	StrPtr ModelNumber;
	StrPtr PartType;
	StrPtr PartDescription;
	IntPtr LowQuant;
	IntPtr partQuant;
};

struct Location
{
	StrPtr Room;
	IntPtr Rack;
	IntPtr Shelf;
	IntPtr Cabinet;

};

class PartData//PartData class for function, variables, and arrays associated with part data
{

private:

	PartInfo PI;
	Location PL; 
	
	ofstream outDatastream;
	ofstream partInfo;
	char testArray[80];

public:

	PartData();
	~PartData();
	
	int maxParts;//dynamically defined through the fetchFile function
	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays

	void PartRemoval();
	//precondition: has the number of parts present in  the array partQuant[]
	//postcondidtion: removes numerical amount from array partQuant[]

	void lowamnt();
	//precondition: partQuant array to be populated.
	//postcondidtion: this prints a list of parts whose quantity is below the 20pcs(can be adjusted) threshhold.

	void partIndex();
	//precondition: None
	//postcondidtion: list all parts present in csv

	int partFind();
	//precondition: user types in part #
	//postcondidtion: the function returns all information asocciated with that part
	
	int getPartQuant(int i);

	void SPSearch();

	//void setlowQuant(int i);

	//Data Transfer Functions
	int PushFileData();
	//precondition: includes any information added or modified while program ran
	//postcondidtion: exports the added/modified information to the external CSV file

	char readValue(ifstream& inputStream, char cell[]);

	int fetchFileData();
	//precondition: program starts
	//postcondidtion: brings in all information in the external CSV
	
};
