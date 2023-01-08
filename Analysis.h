#pragma once
/*
* ===============================
* Analysis.h by Hiram Dominguez for Working in Pain/Group 1
* ===============================
* The Analysis.h file will prompt the user to enter coordinates from the 2D vector to inspect the
* zone's population and the area's total population. Bounds checking will be performed so the user
* doesn't analysis an extra node/element. This will be set into one function with two int arguments
* passing through.
*/
#include "Initializer.h"
using namespace std;

class Analysis {
public:

	void twoDeeTesting() {
		int rows{ 0 };
		int cols{ 0 };
		cout << "Type coordinates for region analysis (x,y): ";
		cin >> rows >> cols;

		cout << "(" << rows << "," << cols << ")";
		//vector<vector<int>> regionMap(rows, vector<int>(cols, 0));
	}
};