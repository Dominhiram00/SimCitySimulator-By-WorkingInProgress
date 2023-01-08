#ifndef COMMERCIAL_H
#define COMMERCIAL_H
#include <iostream>
#include <string>
/*This is created by Sakshee Kiran Shrestha. This header file consists of functions that updates the commercial zone as per the conditions*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Commercial
{
public:
	void CommercialCell();
	void FindC(vector<vector<char>>& region, int m, int n);
	void PassCommercialCells(vector<vector<char>>& region, int a, int b);
	bool isValid(int x, int y, int m, int n);
	void GetAdjacentVal(vector<char>& CommercialCells, vector<vector<char>>& region, int i, int j, int m, int n);
	void SetWorker(int AvailableWorker);
	int GetWorker() const;
	void SetGoods(int AvailableGoods);
	int GetGoods() const;


private:
	int AvailableWorker = 0;
	int AvailableGoods = 0;
	int refreshrate = 0;
};


#endif
