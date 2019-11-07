#include "BaseballStatistic.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

//Constructor
BaseballStatistic::BaseballStatistic(std::string fname, std::string lname, std::string Tname, int Jnum, std::string p,int abat, int hr, int rbi,
                            char B, char T, int sb, double avgbat, int day, int month, int year, double ops, double era)
    :firstName(fname), lastName(lname), position(p), jerseyNum(Jnum), teamName(Tname), battingAverage(avgbat), atBats(abat),
    throwing(T), batting(B){
        Date b(year, month, day);
        dob = &b;
          
 }   

	
//mutator functions
void BaseballStatistic::setFirstName(string fname){ firstName = fname; }
void BaseballStatistic::setLastName(string lname){ lastName = lname; }
void BaseballStatistic::setTeamName(string Tname){ teamName = Tname; }
void BaseballStatistic::setJerseyNum(int Jnum){ jerseyNum = Jnum; }
void BaseballStatistic::setPosition(string p){ position = p; }
void BaseballStatistic::setBatting(char B){ batting = B; }
void BaseballStatistic::setThrowing(char T){ throwing = T; }
void BaseballStatistic::setAtBats(int abat){ atBats = abat; }
void BaseballStatistic::setBattingAverage(double avgbat){ battingAverage = avgbat; }
void BaseballStatistic::setHR(int hr){ hr = hr; }
void BaseballStatistic::setRBI(int rbi){ rbi = rbi; }
void BaseballStatistic::setSB(int sb){ sb = sb; }
void BaseballStatistic::setOPS(double ops){ ops = ops; }
void BaseballStatistic::setERA(double era){ era = era; }
		
		
//accessor functions
string BaseballStatistic::getFirstName()const { return firstName; }
string BaseballStatistic::getLastName()const { return lastName; }
string BaseballStatistic::getTeamName()const { return teamName; }
int BaseballStatistic::getJerseyNum()const { return jerseyNum; }
string BaseballStatistic::getPosition()const { return position; }
char BaseballStatistic::getBatting()const {return batting; }
char BaseballStatistic::getThrowing()const {return throwing; }
int BaseballStatistic::getAtBats()const {return atBats; }
double BaseballStatistic::getBattingAverage()const {return battingAverage; }
int BaseballStatistic::getHR()const {return hr; }
int BaseballStatistic::getRBI()const {return rbi; }
int BaseballStatistic::getSB()const {return sb; }
double BaseballStatistic::getOPS()const {return ops; }
double BaseballStatistic::getERA()const {return era; }
		

//Determines Age
int BaseballStatistic::getAge()const 
{ 
  int age, d, y, m, cday, cmonth, cyear;
 
  time_t year = time(NULL);
  tm * c = localtime(&year);
  
   Date db = *dob;
   d = db.getDay();
   m = db.getMonth();
   y = db.getYear();
   
   cyear = (c -> tm_year) + 1900;
   cmonth = (c -> tm_mon) + 1;
   cday = c -> tm_mday;
    
   age = cyear - y - 1;
   
   if (m < cmonth)
    age++;
    
    else 
      if(m = cmonth) 
      {
        if(d < cday)
        age++;
          
      }  
        
    
 return age;
}

//prints a single statistic row to the terminal
void BaseballStatistic::print()const {
    cout << getFirstName() << " " << getLastName() << " " << getTeamName() << " " << getJerseyNum() << " " << getPosition() << " " 
    << getAge() << " " << getBatting() << " " << getThrowing() << " " << getAtBats() << " " << getBattingAverage() << " " << 
    getHR() << " " << getRBI() << " " << getSB() << " " << getOPS() << " " << getERA();
}
int main()
{
    return 0;
}
