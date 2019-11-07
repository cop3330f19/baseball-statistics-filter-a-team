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
void printmenu();

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

  // reading file
  while(in.good())
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
        
	 printmenu();
	 cin >> option;
	 search(baseList,option);
	    
    }while(answer != "n" || answer != "no");
	
return 0;
}  

void printmenu(){
	cout << "*************************************" << endl;
	cout << "-------------------------------------" << endl;
	cout << "How would you like to search? (Type  " << endl;
	cout << "in character/s in parantheses for    " << endl;
        cout << "your search)                         " << endl;
        cout << "-------------------------------------" << endl;
	cout << "Team (T)                             " << endl;
	cout << "Position (P)                         " << endl;
	cout << "Batting (B)                          " << endl;
	cout << "Average (A)                          " << endl;
	cout << "Home (HR)                            " << endl;
	cout << "Runs Batted in (BI)                  " << endl;
	cout << "Stolen Bases (SB)                    " << endl;
	cout << "OPS (OPS)                            " << endl;
	cout << "ERA (ERA)                            " << endl
	cout << "*************************************" << endl;
}
    
/*while(in >> Tname >> fname >> Jnum >> lname >> y >> m >> d >> B >> T >> atbat >> avgbat>> hr >> rbi >> sb>> ops >> era >> p)
