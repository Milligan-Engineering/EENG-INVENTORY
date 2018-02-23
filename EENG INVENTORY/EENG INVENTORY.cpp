//EENG INVENTORY
//Author: Sam Wehner
//EENG 221
// sjwehner@my.milligan.edu
//program if an inventory system that will be used to monitor and maintain quantities, locactions, and names of stored parts.
//Last modified 02//2017
#include <iostream>
#include <string>

//Function is good

using namespace std;
void partIndex(int partNumber[], string partName[], int partQuant[], string partLoc[]);//listprint
// Displays output of part numbers, Names, Quantities, and locations.
// Only displays iformation for valid parts


const int maxParts = 3;			

//See if you can start getting rid of global variables.

int partnumber;//search value
int partNumber[maxParts];
string partName[maxParts];
string partLoc[maxParts];
//string capacitor[3];
//string resistor[3];
//string transistor[3];
int partQuant[maxParts];
//int partsRemoved;



int main()
{
	
	
		//Part catagories
		//capacitor[3] = { 'cap1', 'cap2', 'cap3' };
		//resistor[3] = { 'res1','res2', 'res3' };
		//transistor[3]= { 'tran1', 'tran2', 'tran3' };;
		//Part Name
		partName[0] = "capacitor";
		partName[1] = "resistor";
		partName[2] = "transistor";

		//Part Quantities
		partQuant[0] = 70;
		partQuant[1] = 60;
		partQuant[2] = 80;

		// Part Locations
		partLoc[0] = "0101A";
		partLoc[1] = "0102A";
		partLoc[2] = "0103A";
		char menuChoice;
		cin >> menuChoice;
		do
		{
			cout << "What would you like to do today? \n\n";
			cout << "To find a part press P:\n" << "To access part list press I: \n" << "To exit press E:\n";
			// Break this into one line for each option. *COMPLETE
			// Add an exit option. *COMPLETE
			// Put in a loop so user can do several tasks without exiting program.


			switch (menuChoice)
			{
			case 'P':
			case'p':

				do
				{
					//phasing out Global variables
					int partsRemoved;
					cout << "Type part Number or E to exit:\n";
					cin >> partnumber;



					if ((partnumber <= 0) || (partnumber > maxParts)) //part not found
					{
						cout << "part not found.\n\n";
					}


					else // part found command string
					{
						cout << "part number: " << partnumber << " requested" << "\t";
						cout << "part name: " << partName[partnumber - 1] << "\t";
						cout << "Quantity: " << partQuant[partnumber - 1] << "pcs" << "\t\t";
						cout << "Location: " << partLoc[partnumber - 1] << "\n\n";
						cout << "How many parts are you removing? ";
						cin >> partsRemoved;
						partQuant[partnumber - 1] = partQuant[partnumber - 1] - partsRemoved; //updates part quantity located in partQuant array
						cout << partQuant[partnumber - 1] << " parts remaining\n\n";

					}

				} 
				while (partnumber != 0);
				break;

			case 'I':
			case'i':
				partIndex(partNumber, partName, partQuant, partLoc);

				break;

			case'C': //"part check" option
			case'c'://quantitySort(int partQuant, int Order, int quant);


				break;

			case 'E':
			case 'e':

				return(0);

				break;
			}

			/*	{
					//char menuChoice;
					cout <<"press M to return to the menu\n"<< " or press E to exit\n ";
						switch (menuChoice)
						{
						case'E':
						case'e':
								return(0);

						}
				}
				*///Tell user to enter any character to exit program.
			char wait;
			cin >> wait;
		}

 
	while ((menuChoice !='E')||(menuChoice !='e'));

	return 0;
}

void partIndex(int partNumber[], string partName[], int partQuant[], string partLoc[])//listprint
// prints out part list
{
	int i;
	for (i = 0; i < maxParts; i++)
	{

		cout << "Part Number: " << i << "\t";
		cout << "Part Name: " << partName[i] << "\t";
		cout << "Part Quantity: " << partQuant[i] << "\t";
		cout << "Part Location: " << partLoc[i] << "\t""\n\n";
	}
	
}




 //void quantitySort(int partQuant[], int Order[], int quant)
//{
	//int temp;
	//for (int i = 0; i < quant - 1; i++)
//	{
		//for (int j = 0; j < quant - i - 1; j++)
//		{
//			if (partQuant[Order[j]] > partQuant[Order[j + 1]])
//			{
//				temp = Order[j];
//				Order[j] = Order[j + 1];
//				Order[j + 1] = temp;
//			}
//		}
//	}



