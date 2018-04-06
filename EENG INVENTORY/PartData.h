#pragma once
#include <string>

using namespace std;

class PartData//PartData class for function, variables, and arrays associated with part data
{

private:
	
	static const int maxParts = 3; 					   
	string partType[maxParts];
	string partName[maxParts];
	string partLoc[maxParts];
	int partQuant[maxParts];
	int quantityLow = 20;

public:

	PartData();
	~PartData();

	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval();
	void lowamnt();
	void partIndex();
	void partFind();
	string getPartLoc(int i);
	void setlowQuant(int i);

	//inheritance??

	friend int fetchFileData(PartData partstuff);
	friend int pushFileData(PartData partstuff);
	
};
