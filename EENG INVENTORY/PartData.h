#pragma once
#include <string>

using namespace std;

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
	static const int maxParts = 3;
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
	string getPartLoc(int i);
	void setlowQuant(int i);

	int pushFileData();

	char readValue(ifstream& inputStream, char cell[]);

	friend int fetchFileData(PartData partstuff);
	//friend int pushFileData(PartData partstuff);
	
};
