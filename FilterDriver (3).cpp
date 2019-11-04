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
void printHeading();


int main(){
    
    vector<BaseballStatistic> baseList;
	
	loadFile(baseList);
    
    cout << " Pre Sorted List" << endl;
    printHeading();
    for(int )
        
    sort(baseList);
    cout << endl << "Sorted " << endl;
    printHeading();
    
    cout << endl << endl;
    string cont ="";
    
    
void loadFile (vector<BaseballStatistic>& baseList){
  ifstream in;
  in.open("BStats.csv");// open file
 
  string temp; // temp variable to hold the old value during the swap
}
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
    void swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
    
    BaseballStatistic temp = baseList[oIdx]; //temporary employee variable to hold the old value during swap
    baseListList[oIdx] = baseListList[nIdx]; // assign the min_idx(element to be moved) to it's position
    baseListList[nIdx] = temp; //assign the element previously at the now sorted postion
    }

    void sort(vector<BaseballStatistic>& baseList){
    
     int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < baseList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        
        for (j = i+1; j < baseList.size(); j++) 
          if (
              (baseList[j].getLName().compare(baseList[min_idx].getLName()) < 0) //if getLName() @ j is < getLName() @ min_idx
              
            min_idx = j; 
      
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
        
       
    } 
}


int search(vector<BaseballStatistic> players, string fname, string lname, string p, string ){
  
  int lo = 0;
  int hi = players.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi/2); 
  
        // Check if name is present at mid 
        if (players[location].getLName() == lname && players[location].getFName() == fname) 
            return location; 
  
        // If name greater, ignore left half 
        if (players[location].getLName() < lname 
			|| (players[location].getLName() == lname && players[location].getFName() < fname)) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
    } 
  
    // then element was not present 
    return -1; 
 
}
    
    
