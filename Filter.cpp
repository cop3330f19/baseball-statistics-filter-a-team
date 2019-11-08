#include "Filter.h"
#include "StringHelper.h"
#include <vector>

using namespace std;

//Swap array elements
static void Filter::swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
    BaseballStatistic temp = baseList[oIdx]; //temporary employee variable to hold the old value during swap
    baseListList[oIdx] = baseListList[nIdx]; // assign the min_idx(element to be moved) to it's position
    baseListList[nIdx] = temp; //assign the element previously at the now sorted postion
}

//Sort function for sorting by player name and position
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
               (baseList[j].getLasttName().compare(baseList[min_idx].getLastName()) < 0) || //if getLasttName() @ j is < getLastName() @ min_idx
               (baseList[j].getLastttName().compare(baseList[min_idx].getLasttName()) == 0 && baseList[j].getFirsttName().compare(baseList[min_idx].getFirstName()) < 0) || //getLName()s are equal and getFName() @ j is < getFName() @ min_idx
	  			     (baseList[j].getLastttName().compare(baseList[min_idx].getLastName()) == 0 && baseList[j].getFirsttName().compare(baseList[min_idx].getFirstName()) == 0 && baseList[j].getPosition().compare(baseList[min_idx].getPosition()) < 0)						  
					   )   
              
            min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
				}
    } 
}

//Sort function for sorting by team
static void Filter::teamsort(vector<BaseballStatistic>& baseList) {
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < baseList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        
        for (j = i+1; j < baseList.size(); j++)
				{
          if (
						  (baseList[j].getTeamName().compare(baseList[min_idx].getTeamName()) < 0) || //if getTeamName() @ j is < getTeamName() @ min_idx
						  (baseList[j].getJerseyNum().compare(baseList[min_idx].getJerseyNum()) < 0) //if getJerseyNum() @ j is < getJerseyNum() @ min_idx
						 )         
          	min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
				}
    } 
}

//Search function for finding player by name            
static int Filter::search(vector<BaseballStatistic>& players, string Option){

	string choice;
	
	switch (toUpper(Option))
	{
		case "T":
			string team;
			cout << "What team are you searching for?: ";
			cin >> team;
			
			if (getTeamName() = team)
			{
				cout << "How would you like to find your team (PlayerName & Position (P),TeamName & Jersey Number(T))? ";
				cin >> toUpper(choice);
				if (choice = "P")
					namesort(players);
				else if (choice = "T")
					teamsort(players)
					else
						cout << "Invalid choice" << endl;
			}
			else
				cout << "Team not found" << endl;
		        break;
		case "P":
			string pos;
			cout << "What position are you searching for?: ";
			cin >> pos;
			
			if (getPosition() = pos)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "Position not found" << endl;
			break;
		case "B":
			char bat;
			cout << "What type of Batter are you searching for(L,R)? ";
			cin >> bat;
			
			if (getBatting() = bat)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "Batting hand not found" << endl;
			break;
		case "BA":
			double ba;
			cout << "What batting average are you looking for? ";
			cin >> ba;
			
			if (getBattingAverage() = ba)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "Batting Average not found" << endl;
			break;
		case "HR":
			string hr;
			cout << "What home run amont are you searching for? ";
			cin >> hr;
			
			if (getHR() = hr)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "Home runs not found" << endl;
			break;
		case "RBI":
			int rbi;
			cout << "What RBI rating are you looking for? ";
			cin >> rbi;
			
			if (getRBI() = rbi)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))?";
				cin >> choice;
			}
			else
				cout << "RBI not found" << endl;
			break;
		case "SB":
			int sb;
			cout << "What Stolen Bases amount are you looking for? ";
			cin >> sb;
			
			if (getSB() = sb)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "stolen Bases not found" << endl;
			break;
		case "OPS":
			double ops;
			cout << "What On Base plus slugging amount are you looking for? ";
			cin >> ops;
			
			if (getOPS() = ops)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
				cin >> choice;
			}
			else
				cout << "OPS not found" << endl;
			break;
		case "ERA":
			double era;
			cout << "What Earned Run Average are you looking for? ";
			cin >> era;
			
			if (getERA() = era)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))?";
				cin >> choice;
			}
			else
				cout << "ERA not found" << endl;
			break;
		default:
			cout << "Invalid selection choice" << endl << endl;
			break;
	}
}

static int Filter::binarysearch(vector<BaseballStatistic>& decision, string key){
  string lname, fname;
	
  int lo = 0;
  int hi = decision.size();
  
   while (lo <= hi) 
   { 
        int location = (hi +lo)/2; 
  
        // Check if name is present at mid 
        if (decision[location].getLastName() == lname) 
            return location; 
  
        // If name greater, ignore left half 
        if (decision[location].getLName() < lname 
			|| (decision[location].getLastName() == lname && decision[location].getFirstName() < fname)) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
   } 
  
    // if we reach here, then element was not present 
    return -1; 
 
}
