#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

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
	char testArray[80];

	ofstream partInfo;

	//ifstream partInfo;

public:

	PartData();
	~PartData();
	int maxParts;
	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval();
	void lowamnt();
	void partIndex();
	void partFind();
	int getPartQuant(int i);
	//void setlowQuant(int i);

	//Data Transfer Functions
	int PushFileData();

	char readValue(ifstream& inputStream, char cell[]);

	int fetchFileData();

	void PrintList();

	
	/*
	typedef char* CharPtr;
	CharPtr p;
	char testArray[45];
	p = new testArray;

	*/
	

	//friend int fetchFileData(PartData partstuff);
	//friend int pushFileData(PartData partstuff);
	
};
