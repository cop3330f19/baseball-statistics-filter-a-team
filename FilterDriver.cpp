#include <fstream>
#include "BaseballStatistic.h"
#include "Date.h"
#include "StringHelper.h"
#include "Filter.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

//Function
void swap(int, int, vector<BaseballStatistic>&);
void sort(vector<BaseballStatistic>&);
int search(vector<BaseballStatistic>, string, string);
void loadFile(vector<BaseballStatistic>&);


int main(){
    
    vector<BaseballStatistic> baseList;
	
	loadFile(baseList);

}
void loadFile (vector<BaseballStatistic>& baseList){
  ifstream in;
  in.open("BStats.csv");// open file
 
  string temp; // temp variable to hold the old value during the swap
 
  while(getline(in,temp)) // reading file
  {
      	while(in >> Tname >> fname >> Jnum >> lname >> y >> m >> d >> B >> T >> atBats >> avgbat>> hr >> rbi >> sb>> ops >> era >> p){
		
		BaseballStatistic temp(Tname, fname, Jnum, lname, y, m, d, B, T, atBats, avgbat, hr, rbi, sb, ops, era, p);
		eList.push_back(temp);
	}
     cout << temp <<endl;
  }
   


return 0;
}
