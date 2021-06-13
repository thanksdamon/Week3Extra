// ITCS2530Week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>


using namespace std;


int main()
{
    ofstream outFile; // output file stream variable

    // Defining variables and constants
    static int MAX_ORDER_TOTAL = 150;
    static int MIN_ORDER_TOTAL = 50;
    static int MID_ORDER_TOTAL = 100;

    static double USA_COST_MIN = 6.00;
    static double USA_COST_MAX = 12.00;
    static double USA_COST_MID = 9.00;

    static double CAN_COST_MIN = 8.00;
    static double CAN_COST_MAX = 15.00;
    static double CAN_COST_MID = 12.00;

    static double AUS_COST_MIN = 10.00;
    static double AUS_COST_MAX = 17.00;
    static double AUS_COST_MID = 14.00;

    static double MARS_COST_MIN = 100'000.00;
    static double MARS_COST_MAX = 1'000'000.00;
    static double MARS_COST_MID = 500'000.00;

    static double FRAGILE_FEE = 2.00;

    string itemName, fragile, dest;
    double total, scost, gtotal;
    
    outFile.open("Order.txt"); // Opening file for writing output


    cout << "............................................." << endl;
    cout << "ITCS 2530 - Programming Assignment for Week 3" << endl;
    cout << "............................................." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Please enter the item name (no spaces)........: ";
    cin >> itemName;
    cout << endl;

    // Writing to text file
    outFile << "............................................." << endl;
    outFile << "ITCS 2530 - Programming Assignment for Week 3" << endl;
    outFile << "............................................." << endl;
    outFile << endl;
    outFile << endl;
    outFile << endl;
    outFile << "Please enter the item name (no spaces)........: ";
    outFile << endl;

    cout << "Is the item fragile? (y=yes/n=no)........: ";
    outFile << "Is the item fragile? (y=yes/n=no)........: ";
    cin >> fragile;
    cout << endl;
    outFile << endl;
    // converting input to all caps for the string comparison
    transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);
    if (fragile != "Y" && fragile != "N")
    {
        cout << "Invalid entry, exiting.";
        outFile << "Invalid entry, exiting.";
        return 0;
    }


    cout << "Please enter your order total...........: ";
    outFile << "Please enter your order total...........: ";
    cin >> total;
    cout << endl;
    outFile << endl;

    cout << "Please enter your destination. (usa/can/aus/mars)..........: ";
    outFile << "Please enter your destination. (usa/can/aus/mars)..........: ";
    cin >> dest;
    cout << endl;
    outFile << endl;
    // converting input to all caps for string comparison
    transform(dest.begin(), dest.end(), dest.begin(), ::toupper);
    if (dest != "USA" && dest != "AUS" && dest != "CAN" && dest != "MARS")
    {
        cout << "Invalid entry, exiting.";
        outFile << "Invalid entry, exiting.";
        return 0;
    }

    // these determine shipping costs depending on user input
    if (dest == "USA" && total <= MIN_ORDER_TOTAL)
        scost = USA_COST_MIN;
    else if (dest == "USA" && total > MIN_ORDER_TOTAL && total <= MID_ORDER_TOTAL)
        scost = USA_COST_MID;
    else if (dest == "USA" && total > MID_ORDER_TOTAL && total <= MAX_ORDER_TOTAL)
        scost = USA_COST_MAX;

    if (dest == "AUS" && total <= MIN_ORDER_TOTAL)
        scost = AUS_COST_MIN;
    else if (dest == "AUS" && total > MIN_ORDER_TOTAL && total <= MID_ORDER_TOTAL)
        scost = AUS_COST_MID;
    else if (dest == "AUS" && total > MID_ORDER_TOTAL && total <= MAX_ORDER_TOTAL)
        scost = AUS_COST_MAX;

    if (dest == "CAN" && total <= MIN_ORDER_TOTAL)
        scost = CAN_COST_MIN;
    else if (dest == "CAN" && total > MIN_ORDER_TOTAL && total <= MID_ORDER_TOTAL)
        scost = CAN_COST_MID;
    else if (dest == "CAN" && total > MID_ORDER_TOTAL && total <= MAX_ORDER_TOTAL)
        scost = CAN_COST_MAX;

    if (dest == "MARS" && total <= MIN_ORDER_TOTAL)
        scost = MARS_COST_MIN;
    else if (dest == "MARS" && total > MIN_ORDER_TOTAL && total <= MID_ORDER_TOTAL)
        scost = MARS_COST_MID;
    else if (dest == "MARS" && total > MID_ORDER_TOTAL && total <= MAX_ORDER_TOTAL)
        scost = MARS_COST_MAX;


    if (total > MAX_ORDER_TOTAL)
        scost = 0;
    // adds the fragile fee if needed
    if (fragile == "Y")
        scost += FRAGILE_FEE;
    else
        scost += 0;
    // calculates grand total
    gtotal = scost + total;




    cout << "Your item is................" + itemName << endl;
    cout << "Your shipping cost is.........$";
    cout << scost << endl;
    cout << "You are shipping to........." + dest << endl;
    cout << "Your total shipping costs are..........$";
    cout << gtotal;
    cout << endl;
    cout << "--------------------------------Thank You!";

    // outputs to text file
    outFile << "Your item is................" + itemName << endl;
    outFile << "Your shipping cost is.........$";
    outFile << scost << endl;
    outFile << "You are shipping to........." + dest << endl;
    outFile << "Your total shipping costs are..........$";
    outFile << gtotal;
    outFile << endl;
    outFile << "--------------------------------Thank You!";
    // closes text file after the last output
    outFile.close();
    return 0;
}
