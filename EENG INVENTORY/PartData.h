#pragma once
#include <string>

using namespace std;

class PartData//PartData class for function, variables, and arrays associated with part data
{
public:
	PartData();
	~PartData();
// Need to give preconditions and postconditions for functions
// Need accessor and mutator functions.

	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval();
	void lowamnt();
	void partIndex();
	void partFind();

	//inheritance??
	friend int fetchFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts);
	friend int pushFileData(string partName[maxParts], string partType[maxParts], int partQuant[maxParts], string partLoc[maxParts], int maxParts);
	
private:
	static const int maxParts = 3; 
							   
	string partType[maxParts];
	string partName[maxParts];
	string partLoc[maxParts];
	int partQuant[maxParts];
	

};
