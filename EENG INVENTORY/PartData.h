#pragma once
#include <string>

using namespace std;

class PartData//PartData class for function, variables, and arrays associated with part data
{
public:
	PartData();
	~PartData();

	int partNumber;// (partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval();
	void lowamnt();
	void partIndex();
	void partFind();

private:
	static const int maxParts = 3; 
							   
	string partType[maxParts];
	string partName[maxParts];
	string partLoc[maxParts];
	int partQuant[maxParts];
	

};
