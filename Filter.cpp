#include "Filter.h"

//Swap array elements
void Filter::swap(vector<BaseballStatistic>& baseList, int oIdx, int nIdx){
    BaseballStatistic temp = baseList[oIdx]; //temporary employee variable to hold the old value during swap
    baseList[oIdx] = baseList[nIdx]; // assign the min_idx(element to be moved) to it's position
    baseList[nIdx] = temp; //assign the element previously at the now sorted postion
}

//Sort function for sorting by player name and position
void Filter::namesort(vector<BaseballStatistic>& baseList)
{
    
     int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    /*for (i = 0; i < baseList.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
      
        
        for (j = i+1; j < baseList.size(); j++)
		{
          if ((baseList[j].getLastName().compare(baseList[min_idx].getLastName()) < 0) || //if getLasttName() @ j is < getLastName() @ min_idx
               (baseList[j].getLastName().compare(baseList[min_idx].getLastName()) == 0 && baseList[j].getFirstName().compare(baseList[min_idx].getFirstName()) < 0) || //getLName()s are equal and getFName() @ j is < getFName() @ min_idx
	  			     (baseList[j].getLastName().compare(baseList[min_idx].getLastName()) == 0 && baseList[j].getFirstName().compare(baseList[min_idx].getFirstName()) == 0 && baseList[j].getPosition().compare(baseList[min_idx].getPosition()) < 0)						  
					   )   
              
            min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
				}*/
    cout <<baseList[0].getTeamName() <<endl;
}

//Sort function for sorting by team
void Filter::teamsort(vector<BaseballStatistic>& baseList) {
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
		(baseList[j].getJerseyNum() < baseList[min_idx].getJerseyNum()) //if getJerseyNum() @ j is < getJerseyNum() @ min_idx
	     )         
          	min_idx = j;
            
        // Swap the found minimum element with the first element 
        swap(baseList, min_idx, i);
       
	}
    } 
}

//Search function for finding player by name            
int Filter::search(vector<BaseballStatistic>& players, string Option){

    string choice;
    StringHelper help;
    string t = help.toUpper(Option);
	
    if(t.compare("I") == 0)
    {
	string team;
	cout << "What team are you searching for?: ";
	cin >> team;
            bool foundteam = false;
	    for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getTeamName() == team)
                {
                    foundteam = true;
                    cout << "How would you like to find your team (PlayerName & Position (P),TeamName & Jersey Number(T))? ";
                    cin >> choice;
			
                    choice = help.toUpper(Option);
                    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                        else
                            cout << "Invalid choice" << endl;
                }
            }
            if(!foundteam)
				cout << "Team not found" << endl;
    }
    else if(t.compare("P") == 0)
    {
	string pos;
	cout << "What position are you searching for?: ";
	cin >> pos;
            bool foundpos = false;
                
            for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getPosition() == pos)
                {
                    foundpos = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
            
            if(!foundpos)
				cout << "Position not found" << endl;
    }
    else if(t.compare("B") == 0)
    {
	char bat;
	cout << "What type of Batter are you searching for(L,R)? ";
	cin >> bat;
			
            bool foundb = false;
            for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getBatting() == bat)
                {
                    foundb = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
        
            if(!foundb)
				cout << "Batting hand not found" << endl;
    }
    else if(t.compare("BA") == 0)
    {
	   double ba;
	   cout << "What batting average are you looking for? ";
      	   cin >> ba;
            bool foundba = false;
        
	    for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getBattingAverage() == ba)
                {
                    foundba = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
        
            if(!foundba)
				cout << "Batting Average not found" << endl;
    }
    else if(t.compare("HR") == 0)
    {
	    int hr;
	    cout << "What home run amont are you searching for? ";
	    cin >> hr;
	    bool foundhr = false;
        
            for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getHR() == hr)
                {
                    foundhr = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
        
            if(!foundhr)
				cout << "Home runs not found" << endl;
    }
    else if(t.compare("RBI") == 0)
    {
	   int rbi;
	   cout << "What RBI rating are you looking for? ";
	   cin >> rbi;
	   bool foundbi = false;
        
            for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getRBI() == rbi)
                {
                    foundbi = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))?";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
			
            if(!foundbi)
				cout << "RBI not found" << endl;
    }
    else if(t.compare("SB") == 0)
    {
			int sb;
			cout << "What Stolen Bases amount are you looking for? ";
			cin >> sb;
			bool foundsb = false;
        
             for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getSB() == sb)
                {
                    foundsb = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
             }
			
            if(!foundsb)
				cout << "stolen Bases not found" << endl;
    }
    else if(t.compare("OPS") == 0)
    {
			double ops;
			cout << "What On Base plus slugging amount are you looking for? ";
			cin >> ops;
            bool foundops = false;
        
			for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getOPS() == ops)
                {
                    foundops = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))? ";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
            
            if(!foundops)
				cout << "OPS not found" << endl;
    }
    else if(t.compare("ERA") == 0)
    {
			double era;
			cout << "What Earned Run Average are you looking for? ";
			cin >> era;
            bool foundera = false;
        
			for(int i = 0; i < players.size(); i++)
            {
                if (players[i].getERA() == era)
                {
                    foundera = true;
                    cout << "How would you like to sort (PlayerName (P),TeamName(T))?";
                    cin >> choice;
			
		    choice = help.toUpper(Option);
		    if (choice == "P")
                        namesort(players);
                    else if (choice == "T")
                        teamsort(players);
                    else
                         cout << "Invalid choice" << endl;
                }
            }
			
            if(!foundera)
				cout << "ERA not found" << endl;
    }
    else
    {
	cout << "Invalid selection choice" << endl << endl;
    }
}

int Filter::binarysearch(vector<BaseballStatistic>& decision, string key){
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
        if (decision[location].getLastName() < lname 
			|| (decision[location].getLastName() == lname && decision[location].getFirstName() < fname)) 
            lo = location + 1; 
  
        // If name is smaller, ignore right half 
        else
            hi = location - 1; 
   } 
  
    // if we reach here, then element was not present 
    return -1; 
 
}

int main()
{
    return 0;
}
