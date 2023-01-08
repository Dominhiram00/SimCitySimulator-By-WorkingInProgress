/*
=============================
SimCity
by Working in Progress
=============================
A city zone growth simulator
=============================
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Commercial.h"
#include "Residential.h"
#include "Industrial.h"
using namespace std;

void Initializer_Execute();
void Analysis_Execute();

/*
    All .cpp files will run on this one main.cpp file
*/
int main() {
	Commercial commerce;
	Residential resident;
    industrial industry;
	
	Initializer_Execute();
	resident.ResidentialCell();
	commerce.CommercialCell();
    industry.IndustrialCell();
    Analysis_Execute();

	return 0;
}