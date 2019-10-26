#include "BaseballStatistic.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

BaseballStatistic::BaseballStatistic()
{
   
}
BaseballStatistic::BaseballStatistic(string fname, string lname, string Tname, int Jnum, string p,int abat, int hr, int rbi,
                            char bat, char toss, int sb, double avgbat, int age,int ...  , int ... , double ops, double era)
 :firstname(fname), lastname(lname), position(p), jerseyNum(Jnum), TeamName(Tname), battingAverage(avgbat), atBats(abat),
    throwing(toss), batting(bat){
 }   

	

void BaseballStatistic::setFirstName(string fname){firstName = fname;}
void BaseballStatistic::setLastName(string lname){lastName = lname;}
void BaseballStatistic::BaseballStatistic::setTeamName(string Tname){teamName = Tname;}
void BaseballStatistic::BaseballStatistic::setJerseyNum(int Jnum){jerseyNum = Jnum;}
void BaseballStatistic::BaseballStatistic::setPosition(string p){position = p;}
void BaseballStatistic::BaseballStatistic::setBatting(char bat){batting = bat;}
void BaseballStatistic::BaseballStatistic::setThrowing(char toss){throwing = toss;}
void BaseballStatistic::BaseballStatistic::setAtBats(int abat){atBats = abat;}
void BaseballStatistic::BaseballStatistic::setBattingAverage(double avgbat){battingAverage = avgbat;}
void BaseballStatistic::BaseballStatistic::setHR(int hr){hr = hr;}
void BaseballStatistic::BaseballStatistic::setRBI(int rbi){rbi = rbi;}
void BaseballStatistic::BaseballStatistic::setSB(int sb){sb = sb;}
void BaseballStatistic::BaseballStatistic::setOPS(double ops){ops = ops;}
void BaseballStatistic::BaseballStatistic::setERA(double era){era = era;}
		
		
		//accessor
string BaseballStatistic::getFirstName()const {return firstName;}
string BaseballStatistic::getLastName()const {return lastName;}
string BaseballStatistic::getTeamName()const {return teamName;}
int BaseballStatistic::getJerseyNum()const {return jerseyNum;}
string BaseballStatistic::getPosition()const {return position;}
int BaseballStatistic::getAge()const 
*//{ int age; //tm=todays month, m=month y=year, d=day,  ty todays year
    if (tm > m)
    {
      age = ty - y;
    }
    else if(tm == m)
    {
        if (td < d)
      { 
        age = (ty - 1) - y;
      }
       else 
        age = ty - y;
    }   
    else
   age = (ty - 1) - y;
//*}
{return age;}
char BaseballStatistic::getBatting()const {return batting;}
char BaseballStatistic::getThrowing()const {return throwing;}
int BaseballStatistic::getAtBats()const {return atBats;}
double BaseballStatistic::getBattingAverage()const {return battingAverage;}
int BaseballStatistic::getHR()const {return hr;}
int BaseballStatistic::getRBI()const {return rbi;}
int BaseballStatistic::getSB()const {return sb;}
double BaseballStatistic::getOPS()const {return ops;}
double BaseballStatistic::getERA()const {return era;}
		
		//prints a single statistic row to the terminal
void BaseballStatistic::print()const 
		
		
}

