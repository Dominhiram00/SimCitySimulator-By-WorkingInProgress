/*#define INDUSTRIAL_H_INCLUDED

#ifndef INDUSTRIAL_H_INCLUDED

*/

#ifndef INDUSTRIAL_H_INCLUDED
#define INDUSTRIAL_H_INCLUDED
#include"helper.h"
using namespace std;

class industrial{                 // Defining class Industrial

public:

	void IndustrialCell();
    static int availableGoods;      //Static integer for goods
    static int availableWorkers;     // Static integer for workers 
    void updated(vector<helper> arr[],helper** input,int i);

};

#endif