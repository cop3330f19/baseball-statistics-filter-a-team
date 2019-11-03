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

int Jnum = 0;
int atBat = 0;
int hr = 0;
int rbi = 0; 
int sb = 0;
int d = 0;
int m = 0;
int y =0;
double avgbat = 0;
double ops = 0; 
double era = 0;
char B; 
char T;


////Function
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
      string Tname, fname, lname, p;
	int Jnum, atbat, hr, rbi, sb;
    double avgbat, ops, era;
    char B, T;
      
      	while(in >> Tname >> fname >> Jnum >> lname >> y >> m >> d >> B >> T >> atbat >> avgbat>> hr >> rbi >> sb>> ops >> era >> p){
		
		BaseballStatistic temp(Tname, fname, Jnum, lname, y, m, d, B, T, atbat, avgbat, hr, rbi, sb, ops, era, p);
		eList.push_back(temp);
	}
  }
}
    void swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
    
    BaseballStatistic temp = baseList[oIdx]; //temporary employee variable to hold the old value during swap
    baseListList[oIdx] = baseListList[nIdx]; // assign the min_idx(element to be moved) to it's position
    baseListList[nIdx] = temp; //assign the element previously at the now sorted postion


return 0;
}
