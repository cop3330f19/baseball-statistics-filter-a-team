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

////Function
void loadFile(vector<BaseballStatistic>&);


int main(){
    
   
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
   
    vector<BaseballStatistic> baseList;
	
    loadFile(baseList);
        
    do{
	cout << "Do you want to search for someone (y or yes/n or no)? ";
	cin >> answer;
        
	 cout << "How would you like to find them Team (Position,Batting,Batting Average,Home Runs,Runs Batted In,Stolen Bases,OPS,ERA)? ";
	 
    }while(answer != n || answer != no);
    sort(baseList);
    cout << endl << "Sorted " << endl;
    printHeading();
    
    cout << endl << endl;
    string cont ="";
	
return 0;
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
      
      	while(in >> Tname >> fname >> Jnum >> lname >> y >> m >> d >> B >> T >> atbat >> avgbat>> hr >> rbi >> sb>> ops >> era >> p)
       {
		BaseballStatistic temp(Tname, fname, Jnum, lname, y, m, d, B, T, atbat, avgbat, hr, rbi, sb, ops, era, p);
		baseList.push_back(temp);
       }
   }
    
}
    
    
