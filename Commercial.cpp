/*This is created by Sakshee Kiran Shrestha. This cpp file consists of all the functions defined in the respective header file.*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Commercial.h"

using namespace std;

void Commercial::CommercialCell()
{
	ifstream fin;		//ifstream to read the file

	fin.open("region.csv");							//opening the file

	if (fin.fail())								//checking file errors if there are any
	{
		cout << "ERROR! UNABLE TO OPEN THE FILE.";		//displaying a message to the uder is file cannot be opened.

	}

	string line;
	vector<vector<char>> region;			//vector to store the data read from the .csv file

	while (getline(fin, line))
	{
		vector <char> row;

		for (char& c : line)
		{
			if (c != ',')
			{
				row.push_back(c);			//storing the data to the region vector
			}
		}
		region.push_back(row);
	}




	fin.close();

	int m = region.size();
	int n = region[0].size();

	FindC(region, m, n);			//calling a function to find all C cells

}
void Commercial::FindC(vector<vector<char>>& region, int m, int n)		//function to find the C cells
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char character;

			character = region.at(i).at(j);

			if (character == 'C')
			{
				PassCommercialCells(region, i, j);				//Passing the index of the found cell
			}
		}
	}
}
void Commercial::PassCommercialCells(vector<vector<char>>& region, int a, int b)
{
	vector <char> CommercialCells;

	CommercialCells.push_back(region[a][b]);

	int m = region.size();
	int n = region[0].size();
	GetAdjacentVal(CommercialCells, region, a, b, m, n);				//calling the function to find the adjacent cells
}
bool Commercial::isValid(int x, int y, int m, int n)
{
	if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
		return 0;
	return 1;
}
void Commercial::GetAdjacentVal(vector<char>& CommercialCells, vector<vector<char>>& region, int i, int j, int m, int n)		//function to find adjacent cells
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


	int availablegoods = GetGoods();
	int availableworker = GetWorker();

	// looping in for the conditions in the adjacent cells for population increment on cell C.
	if (region[i][j] == 'C' && availableworker >= 1 && availablegoods >= 1)
	{
		for (int b = 0; b < v.size(); b++)
		{
			if (b == 'T')
			{
				region[i][j] = 1;
				availableworker--;
				availablegoods--;
			}
		}



	}
	else if (region[i][j] == 'C' && AvailableWorker >= 1 && AvailableGoods >= 1) {

		for (int b = 0; b < v.size(); b++)
		{
			int count = 0;
			if (b == '1')
			{
				count++;
			}
			if (count >= 1)
			{
				region[i][j] = 1;
				availableworker--;
				availablegoods--;
			}
		}
	}
	else if (region[i][j] == 1 && AvailableWorker >= 1 && AvailableGoods >= 1)
	{
		for (int b = 0; b < v.size(); b++)
		{
			int count = 0;
			if (b == '1')
			{
				count++;
			}
			if (count >= 2)
			{
				region[i][j] = region[i][j] + 1;
				availableworker--;
				availablegoods--;
			}
		}
	}

	SetWorker(availableworker);
	SetGoods(availablegoods);

	//DisplayResults(region);

}

void Commercial::SetWorker(int AvailableWorker)
{
	this->AvailableWorker = AvailableWorker;
}

int Commercial::GetWorker() const
{
	return AvailableWorker;
}

void Commercial::SetGoods(int AvailableGoods)
{
	this->AvailableGoods = AvailableGoods;
}
int Commercial::GetGoods() const
{
	return AvailableGoods;
}
