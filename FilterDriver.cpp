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
  int Jnum, atbat, hr, rbi, sb, y, m, d;
  double avgbat, ops, era;
  char B, T;
  string answer, option;
	
  vector<BaseballStatistic> baseList;

  //Opens Baseball stats data file	
  ifstream in;
  in.open("BStats.csv");// open file
  string temp;
  // reading file
  while(getline(in, temp))
  {
	
        stringstream strs (temp);
        string temptoken;
        int pos = 0;
        while(getline(strs, temptoken, ','))
        {
                switch(pos)
                {
                    case 0:
                    {
                        Tname = temptoken;
                        break;
                    }
                    case 1:
                    {
                        fname = temptoken;
                        break;
                    }
                    case 2:
                    {
                        Jnum = std::stoi(temptoken);
                        break;
                    }
                    case 3:
                    {
                        lname = temptoken;
                        break;
                    }
                    case 4:
                    {
                         y = std::stoi(temptoken);
                        break;
                    }
                    case 5:
                    {
                        m = std::stoi(temptoken);
                        break;
                    }
                    case 6:
                    {
                        d = std::stoi(temptoken);
                        break;
                    }
                    case 7:
                    {
                        B = temptoken[0];
                        break;
                    }
                    case 8:
                    {
                        T = temptoken[0];
                        break;
                    }
                    case 9:
                    {
                        atbat = std::stoi(temptoken);
                        break;
                    }
                    case 10:
                    {
                        avgbat = std::stod(temptoken);
                        break;
                    }
                    case 11:
                    {
                        hr = std::stoi(temptoken);
                        break;
                    }
                    case 12:
                    {
                        rbi = std::stoi(temptoken);
                        break;
                    }
                    case 13:
                    {
                        sb = std::stoi(temptoken);
                        break;
                    }
                    case 14:
                    {
                        ops = std::stod(temptoken);
                        break;
                    }
                    case 15:
                    {
                        era = std::stod(temptoken);
                        break;
                    }
                    case 16:
                    {
                        p = temptoken[0];
                        break;
                    }
                }
                pos++;
            //baselist.push_back(temp);
        }
        BaseballStatistic tempb(fname, lname, Tname, Jnum, p, atbat, hr, rbi, B, T, sb, avgbat, d, m, y, ops, era);
         baseList.push_back(tempb);
         fname = "";
          lname = "";
          Tname = "";
          p = "";
   }
     
    //While loop that runs as long as user wants to continues to search  for a team (as long as the user doesn't say no)
    do{
	cout << "Do you want to search for someone (y or yes/n or no)? ";
	cin >> answer;
        
	 printmenu();
	 cin >> option;
     Filter s;
	 s.search(baseList,option);
	    
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
	cout << "ERA (ERA)                            " << endl;
	cout << "*************************************" << endl;
}
