#include"Industrial.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void Industrial::IndustrialCell()
{
	ifstream fin;		//ifstream to read the file

	fin.open("region1.csv");							//opening the file

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

	for (vector<char>& row : region) {
		for (char& c : row) {
			cout << c << " ";
		}

		cout << "\n";
	}


	fin.close();

	int m = region.size();
	int n = region[0].size();

	FindC(region, m, n);			//calling a function to find all C cells

}
    

int industrial::availableGoods{ 0 };

int population;

   int rows;

   int col;

   int count1 = 0;



   population = arr[i][0].pop;

   rows = arr[i][0].rowIndex;

   col = arr[i][0].columnIndex;

void Industrial(vector<node> arr[],node** input,int row,int col){

int index=0;

  for(int i=0;i<row;i++){

      for(int j=0;j<col;j++){

          if(input[i][j].symbol=='R'||input[i][j].symbol=='C'||input[i][j].symbol=='I'){

              if(j==0){

                  arr[index].push_back(input[i][j]);

                  

                  if(i==0){

                      

                      arr[index].push_back(input[i][j+1]);

                      arr[index].push_back(input[i+1][j]);

                      arr[index].push_back(input[i+1][j+1]);

                      

                  }

                  else if(i==row-1){

                      

                      arr[index].push_back(input[i][j+1]);

                      arr[index].push_back(input[i-1][j]);

                      arr[index].push_back(input[i-1][j+1]);

                  }

                  else{

                      

                      arr[index].push_back(input[i][j+1]);

                      arr[index].push_back(input[i+1][j]);

                      arr[index].push_back(input[i+1][j+1]);

                      arr[index].push_back(input[i-1][j]);

                      arr[index].push_back(input[i-1][j+1]);

                      

                  }

                  

              }

              else if(j==col-1){

                  arr[index].push_back(input[i][j]);

                  if(i==0){

                      arr[index].push_back(input[i][j-1]);

                      arr[index].push_back(input[i+1][j]);

                      arr[index].push_back(input[i+1][j-1]);

                      

                  }

                  else if(i==row-1){

                      arr[index].push_back(input[i-1][j]);

                      arr[index].push_back(input[i-1][j-1]);

                      arr[index].push_back(input[i][j-1]);

                  }

                  else{

                      arr[index].push_back(input[i][j-1]);

                      arr[index].push_back(input[i-1][j-1]);

                      arr[index].push_back(input[i-1][j]);

                      arr[index].push_back(input[i+1][j]);

                      arr[index].push_back(input[i+1][j-1]);

                  }

              }

              else if(j>0&&j<col-1&&i!=0&&i!=row-1){

                  

                  arr[index].push_back(input[i][j]);

                  arr[index].push_back(input[i][j+1]);

                  arr[index].push_back(input[i][j-1]);

                  arr[index].push_back(input[i-1][j-1]);

                  arr[index].push_back(input[i-1][j]);

                  arr[index].push_back(input[i-1][j+1]);

                  arr[index].push_back(input[i+1][j-1]);

                  arr[index].push_back(input[i+1][j]);

                  arr[index].push_back(input[i+1][j+1]);

                  

              }

              index++;

          }

          else

            continue;

          

      }

  }

  }

void industrial::updated(vector<helper> arr[],helper** input,int i){   // Defining the function industrial
        for(int j=1;j<arr[i].size();j++)

        {

            if(arr[i][j].sym == '#' && availableWorkers >= 2  && population==0){

                arr[i][0].pop=1;         // Setting Available workers to 2 and population to 0

                input[rows][col].pop=1;

                availableWorkers = availableWorkers-1;

                availableGoods = availableGoods + 1;

            }

            else if(arr[i][j].pop>=1 && availableWorkers>=1  && population==0){

                count1++;                  // Setting available workers to 1 and population to 0

                arr[i][0].pop=arr[i][0].pop+1;

                input[rows][col].pop= input[rows][col].pop+1;

                availableWorkers=availableWorkers-1;   // Available worker is decreased by 1 is condition satisfies.

                availableGoods = availableGoods + 1;     // Available goods increased by 1 if condition satisfies

            }

            else if(population==1){             // Else if loop if the population is 1

                if(arr[i][j].pop>=1)

                    count1++;

                    if(count1>=2&&r.availableWorkers >= 2){

                        arr[i][0].pop=arr[i][0].pop + 1;

                        input[rows][col].pop= input[rows][col].pop + 1;

                        availableWorkers=availableWorkers- 1;      // Available workers decreased by 1 if loop satisfies

                        availableGoods  = availableGoods + 1;         // Available goods increased by 1 if loop satisfies

                    }

            }

            else if(population == 2){                                // Else if loop if the population is set to 2

                if(arr[i][j].pop >= 2)

                    count1++;

                if(count1>=4&&availableWorkers>=2){

                    arr[i][0].pop=arr[i][0].pop + 1;

                    input[rows][col].pop= input[rows][col].pop+1;

                    availableWorkers=availableWorkers-1;             // Available workers decreased by 1 if the loop satisfies

                    availableGoods = availableGoods + 1;             // Availabe goods increased by 1 if the loop satisfies

                }

            }





        }

}