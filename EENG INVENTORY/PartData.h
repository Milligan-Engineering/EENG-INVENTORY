#pragma once
#include <string>

using namespace std; //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

class PartData//PartData class for function, variables, and arrays associated with part data
{
public:
	PartData();
	~PartData();

	int partNumber; //(partNumber-1) serves as an index to look up information for each part in the part arrays
	void PartRemoval(int partsRemoved, int partQuant[], int partNumber);
	friend void lowamnt(int partQuant[], string partName[], string partType[], string partLoc[], int quantityLow, const int maxParts);
	void partIndex(string partType[], string partName[], int partQuant[], string partLoc[], const int maxParts);

private:
	const int maxParts = 3;

	struct partInfo
	{
		string partType[maxParts];
		string partName[maxParts];
		string partLoc[maxParts];
		int partQuant[maxParts];
	};


};