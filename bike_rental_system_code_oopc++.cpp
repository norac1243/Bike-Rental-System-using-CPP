
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

//function that displays physical properites back to the user 
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

}; //end of class phyprop

//class engprop enables user to set desired fuel capacity, engine capacity and horse power
//it virtually inherits class phyprop above
class engprop :virtual public phyprop
{
public:
double SELfcap;
int SELecap;
double SELhp;

//constructor that initializes all capacities to 0
engprop()
{
SELecap = 0;
SELfcap = 0;
SELhp = 0;
}

//below arrays store available capacities and horse power
double fcap[10] = { 13.5, 14, 14.5, 15, 15.5, 16 };
int ecap[10] = { 75, 120, 140, 160, 200, 250 };
double hp[10] = { 7.6, 8.2, 9.6, 10.2, 10.5, 11.2 };

//function that gets desired capacites from user 
void getedata()
{
//User enters desired FUEL CAPACITY
cout << horLine << "|" << setw(44) << "Available Fuel Capacities" <<
setw(26) << "|" << horLine;
for (i = 0; i < 5; i++)
cout << "| " << left << setw(10) << fcap[i] << " L";
cout << "|" << horLine;
cout << "Enter required fuel capacity (In Litres): \n";
cin >> SELfcap;

//User enters desired ENGINE CAPACITY
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

//User enters desired HORSE POWER
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
  
cout << endl << endl << "Click enter to continue..";
cin.get();
system("cls");
cout << "\n-----------------------------|CA's BIKE RENTALS|-------------
----------------\n\n";
cout << endl
<< "\nYou have selected:\n";
} //END OF getedata()

//function that displays user's selected capacities and horse power 
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
}; //end of engprop class


//price class calculates the price of the bike 
//for the price calculation we require capacities and horse power as in engprop class and brand as in phyprop
//phyprop classes and data are all public so engprop inherits them 
//class price then virtually inherits engprop 
class price :virtual public engprop
{
protected:
int nb = 0, h = 35, j = 26, s = 27, f = 12, m = 19, v = 23;
public:
float c = 1, d = 1, e = 1;
float z;

//function that calculates factors for price
void call()
{
//considering brand for factor e
if (SELbran == bran[0])
{
e = e * 30;
}
else if (SELbran == bran[1])
{
e = e * 30;
}
else if (SELbran == bran[2])
{
e = e * 40;
}
else if (SELbran == bran[3])
{
e = e * 50;
}
else if (SELbran == bran[4])
{
e = e * 60;
}
else
{
e = e * 70;
}

//considering engine capacity for factor c
if (SELecap == ecap[0])
{
c = c * 200;
}
else if (SELecap == ecap[1])
{
c = c * 300;
}
else if (SELecap == ecap[2])
{
c = c * 400;
}
else if (SELecap == ecap[3])
{
c = c * 500;
}
else if (SELecap == ecap[4])
{
c = c * 600;
}
else
{
c = c * 700;
}

//considering horse power for factor d
if (SELhp == hp[0])
{
d = d * 200;
}
else if (SELhp == hp[1])
{
d = d * 300;
}
else if (SELhp == hp[2])
{
d = d * 400;
}
else if (SELhp == hp[3])
{
d = d * 500;
}
else if (SELhp == hp[4])
{
d = d * 600;
}
else
{
d = d * 700;
}
z = c + d + e; //sum of all above calculated factors 
}//end of function call ()

//displays overall properties of bike selected by calling displayedata from class engprop
void dis()
{
displayedata(); 
}

//below functions are defined outside the class scope 
void operator++();
void dispy();
};//end of class price
