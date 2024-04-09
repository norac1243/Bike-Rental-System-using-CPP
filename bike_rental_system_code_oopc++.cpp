
/*OOP with C++ PROGRAMMING LABORATORY
MINI PROJECT
BIKE RENTAL SYSTEM
DONE BY:
ABIGIAL FERNANDES GOLIAS 
CARON SALLY PEREIRA 
CLASS: SE COMP (RC2019-20)
BATCH: P1
DATE OF SUBMISSION: 14/11/22
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include<ios>
using namespace std;

//BELOW variables are used for display 
string horLine = "\n------------------------------------------------------------------
-----\n";
string pipe = "|";
string horLineForDisp = "\n---------------------------------\n";
int i = 0;

//BELOW CLASS STORES physical properties of each bike and enables USERS to select the specifications of desired bike.
class phyprop
{
  public:
  string col[50] = { "BLUE", "BLACK", "RED", "WHITE", "YELLOW", "GREEN" };
  string bran[50] = { "HONDA", "JUPITER", "SUZUKI", "MAESTRO", "VESPA", "FASCINO"};
  string mod[50] = { "25S", "6G", "CB200X", "SP125", "PCX160", "AX25" };
  string SELcol;
  string SELbran;
  string SELmod;

// function for entering physical properties
void getpdata()
{
cout << horLine << "|" << setw(44);
//User enters desired BRAND
cout << "Available Brands" << setw(26) << "|" << horLine;
for (i = 0; i < 5; i++)
{
cout << "| " << left << setw(12) << bran[i];
}
cout << "|" << horLine;
cout << "Enter Brand: \n";
cin >> SELbran;

//User enters desired MODEL
cout << horLine << "|" << setw(69) << "Available Models";
cout << setw(26) << "|" << horLine;
for (i = 0; i < 5; i++)
cout << "| " << left << setw(12) << mod[i];
cout << "|" << horLine;
cout << "Enter Model: \n";
cin >> SELmod;

//User enters desired Colour
cout << horLine << "|" << setw(69) << "Available Colours" << setw(26) <<
"|" << horLine;
for (i = 0; i < 5; i++)
cout << "| " << left << setw(12) << col[i];
cout << "|" << horLine;
cout << "Enter Desired Colour: \n";
cin >> SELcol;
}//end of function getpdata()


void displaypdata()
{
cout << horLineForDisp << "|" << setw(31) << left << "Bike Details" <<
setw(10) << "|" << horLineForDisp;
cout << pipe << left << setw(20) << "Brand";
cout << pipe << left << setw(10) << SELbran << pipe << horLineForDisp;
cout << pipe << left << setw(20) << "Model";
cout << pipe << left << setw(10) << SELmod << pipe << horLineForDisp;
cout << pipe << left << setw(20) << "Colour";
cout << pipe << left << setw(10) << SELcol << pipe << horLineForDisp;
}
};
class engprop :virtual public phyprop
{
public:
double SELfcap;
int SELecap;
double SELhp;
engprop()
{
SELecap = 0;
SELfcap = 0;
SELhp = 0;
}
double fcap[10] = { 13.5, 14, 14.5, 15, 15.5, 16 };
int ecap[10] = { 75, 120, 140, 160, 200, 250 };
double hp[10] = { 7.6, 8.2, 9.6, 10.2, 10.5, 11.2 };
void getedata()
{
cout << horLine << "|" << setw(44) << "Available Fuel Capacities" <<
setw(26) << "|" << horLine;
for (i = 0; i < 5; i++)
cout << "| " << left << setw(10) << fcap[i] << " L";
cout << "|" << horLine;
cout << "Enter required fuel capacity (In Litres): \n";
cin >> SELfcap;
cout << horLine << "|" << setw(69) << "Available Engine Capacities" <<
setw(26) << "|" << horLine;
for (i = 0; i < 5; i++)
{
cout << "|" << left << setw(9) << ecap[i] << "cc";
}
cout << "|" << left << setw(7) << ecap[5] << "hp"
<< "| " << horLine;
cout << "Enter required engine capacity (In cc): \n";
cin >> SELecap;
cout << horLine << "|" << setw(69) << "Available Horse Power On Bikes"
<< setw(22) << "|" << horLine << "| ";
for (i = 0; i < 5; i++)
{
cout << left << setw(9) << hp[i] << "hp"
<< "|";
}
cout << left << setw(6) << hp[5] << "hp"
<< "| " << horLine;
cout << "Enter required horse power (In bhp): \n";
cin >> SELhp;
cout << endl
<< endl
<< "Click enter to continue..";
cin.get();
system("cls");
cout << "\n-----------------------------|CA's BIKE RENTALS|-------------
----------------\n\n";
cout << endl
<< "\nYou have selected:\n";
}
void displayedata()
{
displaypdata();
cout << pipe << left << setw(20) << "Fuel Capacity";
cout << pipe << left << setw(10) << SELfcap << pipe << horLineForDisp;
cout << pipe << left << setw(20) << "Engine Capacity";
cout << pipe << left << setw(10) << SELecap << pipe << horLineForDisp;
cout << pipe << left << setw(20) << "Horse Power";
cout << pipe << left << setw(10) << SELhp << pipe << horLineForDisp;
}
};
class price :virtual public engprop
{
protected:
int nb = 0, h = 35, j = 26, s = 27, f = 12, m = 19, v = 23;
public:
float c = 1, d = 1, e = 1;
float z;
