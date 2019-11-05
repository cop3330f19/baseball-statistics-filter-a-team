#include "Filter.h"
#include <vector>

using namespace std;

//Swap array elements
static void Filter::swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
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
static void Filter::teamsort(vector<BaseballStatistic>& baseList) {
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
static int Filter::search(vector<BaseballStatistic> players, string Option){
	
	switch (Option)
	{
		case "T":
			string team;
			cout << "What team are you searching for?: ";
			cin >> team;
			
			if (getTeamName() = team)
			{
				cout << "How would you like to sort (PlayerName (P),TeamName(T))?";
				cin >> 
			}
		        break;
		case "P":
			cout << "What position are you searching for?: ";
			break;
		case "B":
			cout << "What type of Batter are you searching for(L,R)? ";
			break;
		case "BA":
			cout << "What batting average are you looking for? ";
			break;
		case "HR":
			cout << "What home run amont are you searching for? ";
			break;
		case "RBI":
			cout << "What RBI rating are you looking for? ";
			break;
		case "SB":
			cout << "What Stolen Bases amount are you looking for? ";
			break;
		case "OPS":
			cout << "What On Base plus slugging amount are you looking for? ";
			break;
		case "ERA":
			cout << "What Earned Run Average are you looking for? ";
			break;
	}
}
