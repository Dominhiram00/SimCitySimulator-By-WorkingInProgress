=======================
Initailzer.h
Created by Hiram Dominguez for Working in Pain
=======================
The "Initiailzer.h" file will have four different functions to start off the program:
1. Extracting the configuration file to set the timer and refresh rate
2. Set all zone letters to a value of zero by creating objects
3. Create a matrix by using a dynamic 2D array
4. Display the intial status of all zones, timer, and refresh rate

Data for each zone with be grabbed by using a getter for any team member to use.
===============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Set each zone as its own object for ease of access for the other team members
class industrialZone {
private:
    int population = 0;
public:
    char industrialLetter = 'I';
    void setData(int x) {
        population = x;
    }

    int getData() {
        return population;
    }
};

class residentalZone {
private:
    int population = 0;
public:
    char residentialLetter = 'R';
    void setData(int x) {
        population = x;
    }

    int getData() {
        return population;
    }
};

class commerceZone {
private:
    int population = 0;
public:
    char commercelLetter = 'C';
    void setData(int x) {
        population = x;
    }

    int getData() {
        return population;
    }
};

class pollution {
private:
    int pollutionRate = 0;
public:
    void setPollutionRate(int x) {
        pollutionRate = 0;
    }

    int getPollutioniRate() {
        return pollutionRate;
    }

};

class powerlines_roads_powerplants {
public:
    char powerline = 'T';
    char road = '-';
    char powerline_road = '#';
    char power_plant = 'P';
};

/*The Initalizer class will be split into three functions to
remain in order for debugging.
*/
class Initializer {
private:
    ifstream configFile;
    ifstream regionFile;
    vector<char> regionFileStorage;
    char zoneLetter;
    industrialZone industry;
    residentalZone resident;
    commerceZone commerce;
    int timer, refresh_rate;
    string regionFileName;

public:
    /*
    To gather the nessacary information from the configuration file, I used three string variables
    to store the text before the token, then stored the file name, time steps, and refresh rate into
    their own variables from the private section of this code.
    */
    void configurationSet() {
        configFile.open("config1.txt");
        string temp, temp2, temp3;
        while (configFile) {
            getline(configFile, temp, ':');
            configFile >> regionFileName;
            getline(configFile, temp2, ':');
            configFile >> timer;
            getline(configFile, temp3, ':');
            configFile >> refresh_rate;
        }
        configFile.close();
    }

    /*By using a dynamic 2D array to create a matrix to create a fixed
    rectangle displaying each letter*/
    void mapSet() {
        regionFile.open("region1.csv");
        string regionFileLine;
        while (regionFile) {
            getline(regionFile, regionFileLine, ',');
            copy(regionFileLine.begin(), regionFileLine.end(), back_inserter(regionFileStorage));
        }
        regionFile.close();
    }
    /*Gathering all the getters and configuration data to set the
    initial output displaying the regional file name, time step,
    and refresh rate*/

    void currentRegionState() {
        int timer_temp = timer;
        for (int master{ 0 }; master < timer;  master++) {
            for (int i{ 0 }; i < regionFileStorage.size(); i++)
            {
                zoneLetter = regionFileStorage.at(i);
                if (zoneLetter == 'R') {
                    zoneLetter = '0';
                }
                cout << regionFileStorage[i];
            }

            cout << "Region File Name: " << regionFileName << endl;
            cout << "Timestep: " << timer_temp  << endl;
            cout << "Refresh Rate: " << refresh_rate << endl;
            cout << "\n";
            timer_temp--;
        }
    }
};