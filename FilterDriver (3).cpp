#include "BaseballStatistic.h"
#include "Date.h"
#include "StringHelper.h"
#include "Filter.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////Function


int main(){
  string Tname, fname, lname, p;
  int Jnum, atbat, hr, rbi, sb;
  double avgbat, ops, era;
  char B, T;
  string answer, option;
	
  vector<BaseballStatistic> baseList;

  //Opens Baseball stats data file	
  ifstream in;
  in.open("BStats.csv");// open file

  while(in.good()) // reading file
  {
        string temp; // temp variable to hold the old value during the swap
	if (!getline( in, temp ))
	{
		return 0;
	}
	
	stringstream strs (temp);
	
   	while(strs)
        {	
		//Reads in each individual statistic line
		getline(strs,Tname,',');
		getline(strs,fname,',');
		getline(strs,Jnum,',');
		getline(strs,lname,',');
		getline(strs,y,',');
		getline(strs,m,',');
		getline(strs,d,',');
		getline(strs,B,',');
		getline(strs,T,',');
		getline(strs,atbat,',');
		getline(strs,avgbat,',');
		getline(strs,hr,',');
		getline(strs,rbi,',');
		getline(strs,sb,',');
		getline(strs,ops,',');
		getline(strs,era,',');
		getline(strs,p,',');
		
		baselist.push_back(temp);
        }
   }
     
    //While loop that runs as long as user wants to continues to search  for a team (as long as the user doesn't say no)
    do{
	cout << "Do you want to search for someone (y or yes/n or no)? ";
	cin >> answer;
        
	 cout << "How would you like to find them Team (Position,Batting,Batting Average,Home Runs,Runs Batted In,Stolen Bases,OPS,ERA)? ";
	 cin >> option;
	 search(baseList,option);
	    
    }while(answer != "n" || answer != "no");
    sort(baseList);
    cout << endl << "Sorted " << endl;
    printHeading();
    
    cout << endl << endl;
    string cont ="";
	
return 0;
}   
    
/*int Jnum = 0;
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
    while(in >> Tname >> fname >> Jnum >> lname >> y >> m >> d >> B >> T >> atbat >> avgbat>> hr >> rbi >> sb>> ops >> era >> p)
