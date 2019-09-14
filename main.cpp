#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <random>
#include "BikeHubs.h"
#include "PickUpDropOff.h"

using namespace std;

int main()
{
    int hour;       // variable for drop up hour
    string ID;

    std::vector<string> Bikes;    // Vector Holding Hired Bikes
    std::vector<int> Times;       // Vector Holding Drop up times
    std::vector<char>RetHubs;     // vector holding return hubs

    std::default_random_engine generator;    // variable for dropping random hours

    BikeHubs hire;            // creating class object for Bike Hubs
    PickUpDropOff PickDrop;   // creating class object for picking up and dropping off bikes

    hire.InitHubList();       // initialises the hubs with bikes

    for(int x = 0; x < 5; x++)    // loop for 24 hours
    {
        cout << "Hour " << x <<endl;
        hire.ReadHubList();        // reads the hub lsit and writes them to the screen

        ID = PickDrop.PickUpBike();

        if (ID == "non")         // if no bikes hire in that hour....
        {
            cout << "No Bike Hired in Hour: " << x <<endl;
        }
        else                        // if a bike has been hired....
        {
            Bikes.push_back(ID);      // stores bikes being picked up from hubs in vector

            std::uniform_int_distribution<int> distribution(x+2,23);
            hour = distribution(generator);  // generates number in the range 1..24
            Times.push_back(hour);           // stores time in vector

            cout << "Drop-Off Time Is: " << Times[x] <<endl;
            RetHubs.push_back(PickDrop.DropOffBike(Bikes,Times,x)); // save return hubs in vector
        }

        hire.OnHire(Bikes,Times,RetHubs,x);  // display bikes on hire to screen
    }

    hire.ReadHubList();   // display hubs at the end of the day
    return 0;
}
