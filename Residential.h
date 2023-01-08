
/*This is created by Sakshee Kiran Shrestha. This header file consists of functions that updates the residential zone as per the conditions*/
#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


class Residential
{
public:
	void ResidentialCell();	//declaring the residential cell function 
	void FindR(vector<vector<char>>& region, int m, int n);
	void PassResidentialCells(vector<vector<char>>& region, int a, int b);
	bool isValid(int x, int y, int m, int n);
	void GetAdjacentVal(vector<char>& ResidentialCells, vector<vector<char>>& region, int i, int j, int m, int n);
	void DisplayResults(vector < vector<char>>& region);
	void SetWorker(int AvailableWorker);
	int GetWorker() const;

private:
	int AvailableWorker = 0;
};


#endif
