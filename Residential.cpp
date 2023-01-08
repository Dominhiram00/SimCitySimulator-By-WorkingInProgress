/*This is created by Sakshee Kiran Shrestha. This is a .cpp file defining all the functions declared in the respectice header file.*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Residential.h"

using namespace std;

void Residential::ResidentialCell()	//declaring the residential cell function 
{
	ifstream fin;		//ifstream to read the file

	fin.open("region.csv");							//opening the file

	if (fin.fail())								//checking file errors if there are any
	{
		cout << "ERROR! UNABLE TO OPEN THE FILE.";		//displaying a message to the uder is file cannot be opened.

	}

	string line;
	vector<vector<char>> region;				//vector to store the cells read from the file

	while (getline(fin, line))				//reading the file
	{
		vector <char> row;

		for (char& c : line)
		{
			if (c != ',')
			{
				row.push_back(c);		//storing the read data to a vectpr
			}
		}
		region.push_back(row);
	}



	fin.close();

	int m = region.size();
	int n = region[0].size();

	FindR(region, m, n);			//Looking for R cells in the region


}
void Residential::FindR(vector<vector<char>>& region, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)					//Looping through the region for searching R
		{
			char character;

			character = region.at(i).at(j);

			if (character == 'R')
			{

				//GetAdjacentVal(region, i, j, m, n);
				//cout << i << " " << j << endl;
				PassResidentialCells(region, i, j);			//passing the found R's index

			}
		}
	}
}

void Residential::PassResidentialCells(vector<vector<char>>& region, int a, int b)
{
	vector <char> ResidentialCells;

	ResidentialCells.push_back(region[a][b]);

	int m = region.size();
	int n = region[0].size();
	GetAdjacentVal(ResidentialCells, region, a, b, m, n);			//calling a function to look for the adjacent cells
}

bool Residential::isValid(int x, int y, int m, int n)
{
	if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
		return 0;
	return 1;
}
void Residential::GetAdjacentVal(vector<char>& ResidentialCells, vector<vector<char>>& region, int i, int j, int m, int n)
{
	vector<char> v;

	// Checking for all the possible adjacent positions
	if (isValid(i - 1, j - 1, n, m))
		v.push_back(region[i - 1][j - 1]);
	if (isValid(i - 1, j, n, m))
		v.push_back(region[i - 1][j]);
	if (isValid(i - 1, j + 1, n, m))
		v.push_back(region[i - 1][j + 1]);
	if (isValid(i, j - 1, n, m))
		v.push_back(region[i][j - 1]);
	if (isValid(i, j + 1, n, m))
		v.push_back(region[i][j + 1]);
	if (isValid(i + 1, j - 1, n, m))
		v.push_back(region[i + 1][j - 1]);
	if (isValid(i + 1, j, n, m))
		v.push_back(region[i + 1][j]);
	if (isValid(i + 1, j + 1, n, m))
		v.push_back(region[i + 1][j + 1]);

	int availableworker = GetWorker();
	//checking the adjacent position conditions for each cells' population increment
	if (region[i][j] == 'R')
	{

		for (int a = 0; a < v.size(); a++)
		{

			int x = v[a];
			if (x == 'T')
			{
				region[i][j] = 1;
				availableworker++;

			}

		}

	}
	else if (region[i][j] == 'R')
	{
		for (int a = 0; a < v.size(); a++)
		{
			int x = v[a];
			if (x == 1)
			{
				region[i][j] = 1;
			}
		}

		availableworker++;

	}
	else if (region[i][j] == 1)
	{
		int count = 0;

		for (int a = 0; a < v.size(); a++)
		{
			int x = v[a];
			if (x == 1)
			{
				count++;

			}
		}
		if (count >= 2)
		{
			region[i][j] += 1;
			availableworker++;
		}
	}
	else if (region[i][j] == 2)
	{
		int count = 0;
		for (int a = 0; a < v.size(); a++)
		{
			int x = v[a];

			if (x == 2)
			{
				count++;
			}
		}
		if (count >= 4)
		{
			region[i][j] += 1;
			availableworker++;
		}
	}
	else if (region[i][j] == 3)
	{
		int count = 0;
		for (int a = 0; a < v.size(); a++)
		{
			int x = v[a];

			if (x == 3)
			{
				count++;
			}
		}
		if (count >= 6)
		{
			region[i][j] += 1;
			availableworker++;

		}
	}
	else if (region[i][j] == 4)
	{
		int count = 0;
		for (int a = 0; a < v.size(); a++)
		{
			int x = v[a];

			if (x == 4)
			{
				count++;
			}
		}
		if (count >= 8)
		{
			region[i][j] += 1;
			availableworker++;

		}
	}
	SetWorker(availableworker);

	
}

void Residential::SetWorker(int AvailableWorker)
{
	this->AvailableWorker = AvailableWorker;
}
int Residential::GetWorker() const
{
	return AvailableWorker;
}







