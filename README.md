# Baseball Statistics Filter

**COP3330: INTRODUCTION TO OBJECT ORIENTED PROGRAMMING
GROUP PROJECT 1**

**Due: November 5, 2019 12:30pm**

*Groups listed in Blackboard*


## Problem:

Write a program to read the entire contents of a text file, "BStats.csv" into a vector, to produce a statistic search. Each line contains:
 
-	Team name
-	Uniform Number
-	Last name
-	First name
-	Year of birth
-	Month of birth
-	Day of birth
-	Batting Arm (B)
-	Throwing Arm (T)
-	At Bats (AB)
-	Batting Average (AVG)
-	Home Runs (HR)
-	Runs Batted In (RBI)
-	Stolen Bases (SB)
-	On Base Plus Slugging (OPS)
-	Earned Run Average (ERA)
-	Position (P)
 
This file contains the 40-man active roster and statistics for each National League team. After the CSV file has been read, allow the user to search based on several characteristics:
 
-	Team           
-	Position       
-	Batting        
-	Batting Average
-	Home Runs      
-	Runs Batted In 
-	Stolen Bases   
-	OPS            
-	ERA            
 
User may select to search by any number of options. Before displaying the results allow the user to select from 1 of 2 sorting options:
-	By Player Name & Position
-	By Team & Jersey Number  


Design:

Use the following class H file to build the BaseballStatistic Class to store the information from the CSV file.
```
#ifndef BASEBALL_STATISTIC_H
#define BASEBALL_STATISTIC_H

#include "Date.h"
#include <string>


class BaseballStatistic
{
	
	private:
		std::string firstName,
			lastName,
			teamName,
			position;
		
		int jerseyNum,
			atBats,
			hr,
			rbi,
			sb;
		
		char batting,
			throwing;
		
		double battingAverage,
			ops,
			era;
			
		Date * dob;
		
	public:
		BaseballStatistic(std::string, std::string, std::string, int,
			std::string, int, int, int, char, char, int, double, int,
			int, int, double, double);
			

		
		//mutator
		void setFirstName(std::string);
		void setLastName(std::string);
		void setTeamName(std::string);
		void setJerseyNum(int);
		void setPosition(std::string);
		void setBatting(char);
		void setThrowing(char);
		void setAtBats(int);
		void setBattingAverage(double);
		void setHR(int);
		void setRBI(int);
		void setSB(int);
		void setOPS(double);
		void setERA(double);
		
		
		//accessor
		std::string getFirstName()const;
		std::string getLastName()const;
		std::string getTeamName()const;
		int getJerseyNum()const;
		std::string getPosition()const;
		int getAge()const;
		char getBatting()const;
		char getThrowing()const;
		int getAtBats()const;
		double getBattingAverage()const;
		int getHR()const;
		int getRBI()const;
		int getSB()const;
		double getOPS()const;
		double getERA()const;
		
		//prints a single statistic row to the terminal
		void print()const;
		
		
};

#endif
```
A Date.h and Date.o file are provided for you to use for "dob". The Date Class allows you to create a Date object the stores day, month, and year. You can also get age based on today's date. Use the Date.o file when compiling your project.
```
#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
	
	private:
		const int day,
				month,
				year;
	
	public:
		//Constructor accepts the date in the format YYYY, MM, DD
		//eg Date date(2019, 9, 27);
		explicit Date(int y, int m, int d):
			year(y), month(m), day(d){
				
			}
		
		int getDay()const; //Returns the day
		int getMonth()const; //Returns the month
		int getYear()const; //Returns the year
		std::string getDate()const; //Returns the date string (YYYY-MM-DD)
		int getAge()const; //Calculates age in years
};

#endif
```
Finally develop a Filter class which has your sort and search functions. These functions should be static. 
***Hint:  Each function should have a parameter that accepts a BaseballStatistic vector, passed by reference.**

Include both a H and CPP file for this class. Finally, you should have FilterDriver.cpp that contains main. In this file you should read the CSV file and control the menu options. The user should not be able to enter the same filter twice in a single search. The user input and search should be case insensitive. You are provided also with a StringHelper.h and StringHelper.o file. The program should run a loop until the user does not want search any more. There is a sample of the program included. Run with the command `./baseballstats`

***Hint: To filter by multiple values you could call your search function in loop searching for a different value on each iteration.**
```
#ifndef STRING_HELPER
#define STRING_HELPER

#include <string>
#include <sstream>
#include <vector>

class StringHelper{
	
	public:
		/**************************************************************
		 *                             parse                          *
		 *                                                            *
		 * Passed   : 2 arguments: a string, a character that is the  *
		 *            delimiter                                       *
		 * Purpose  : Split a given string by its delimiter           *
		 * Returns  : String vector                                   *
		 **************************************************************/
		static std::vector<std::string> parse(std::string , char );

		/**************************************************************
		 *                           toUpper                          *
		 *                                                            *
		 * Passed   : 1 argument: a string                            *
		 * Purpose  : Convert a string to all upper case              *
		 * Returns  : String                                          *
		 **************************************************************/
		static std::string toUpper(const std::string );

		/**************************************************************
		 *                          toString                          *
		 *                                                            *
		 * Passed   : 1 argument: a native  type value or a ADT       *
						with an output stream overload                *
		 * Purpose  : Convert a non-string value to a string          *
		 * Returns  : String                                          *
		 **************************************************************/
		template<typename T>
		static std::string toString(const T& value)
		{
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}

};
#endif
```
## Suggested/Not Required:

You may consider using a struct to keep track of your key/value pair for the search.
```
struct FilterOptions{
	string filter;
	string key;
};
```
## Documentation Requirements:
The documentation must include the follow:
1.	Cover Page (provided; fill in all information; each page should have the same header/footer)
2.	Table of Contents (last pages of document)
3.	Grade Sheet
4.	Flowchart (1 per function, not including accessors and mutators)
5.	Description of the major inputs, outputs, and processes.
6.	The code
	1.	Well commented code (follow function comments in the code provided)
	1.	The top of each file should include:
		1.	Name of the file
		1.	Group number and member names
		1.	Date last edited
		1.	Purpose of the program
