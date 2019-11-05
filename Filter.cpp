#include "Filter.h"
#include <vector>

using namespace std;

//Swap array elements
static void FILTER::swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
    BaseballStatistic temp = baseList[oIdx]; //temporary employee variable to hold the old value during swap
    baseListList[oIdx] = baseListList[nIdx]; // assign the min_idx(element to be moved) to it's position
    baseListList[nIdx] = temp; //assign the element previously at the now sorted postion
}

//Sort function for sorting by player name
static void Filter::namesort(vector<BaseballStatistic>& baseList){
    
     int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < baseList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        
        for (j = i+1; j < baseList.size(); j++)
	{
          if (
              (baseList[j].getFirstName().compare(baseList[min_idx].getFirstName()) < 0) || //if getFirstName() @ j is < getFirstName() @ min_idx
              (baseList[j].getLastName().compare(baseList[min_idx].getLastName()) < 0)      //if getLastName() @ j is < getLastName() @ min_idx
	  )   
              
            min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
	}
    } 
}

//Sort function for sorting by team
static void teamsort(vector<BaseballStatistic>&) {
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < baseList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        
        for (j = i+1; j < baseList.size(); j++)
	{
          if ((baseList[j].getTeamName().compare(baseList[min_idx].getTeamName()) < 0)) //if getTeamName() @ j is < getTeamName() @ min_idx        
          	min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
	}
    } 
}

//Search function for finding player by name            
static int FILTER::search(vector<BaseballStatistic> players, string fname, string lname, string p, string ){
  
  int lo = 0;
  int hi = players.size();
  
   while (lo <= hi) 
    { 
        int location = (lo + hi)/2; 
  
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
