#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

static const int maxParts = 3;

struct PartInfo
{
	string ModelNumber[maxParts];
	string PartDescription[maxParts];
	string partType[maxParts];
	string partName[maxParts];

};
struct Location
{
	string Room[maxParts];
	int Rack[maxParts];
	int Shelf[maxParts];
	int Cabinet[maxParts];
};



class PartData//PartData class for function, variables, and arrays associated with part data
{

private:
	
	PartInfo PI;
	Location PL;
	int partQuant[maxParts];
	int quantityLow = 20;
	ofstream outDatastream;
	


public:

	PartData();
	~PartData();

	

	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval();
	void lowamnt();
	void partIndex();
	void partFind();
	int getPartQuant(int i);
	void setlowQuant(int i);
	//Data Transfer Functions
	int PushFileData();
	int fetchFileData();

	char readValue(ifstream& inputStream, char cell[]);

	typedef char* CharPtr;
	CharPtr p;
	char testArray[45];
	p = new testArray;

	
	

	friend int fetchFileData(PartData partstuff);
	//friend int pushFileData(PartData partstuff);
	
};
