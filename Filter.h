#ifndef FILTER_H
#define FILTER_H

#include "BaseballStatistic.h"
#include <string>
#include <vector> 

using namespace std;

class Filter {
  public:
  static void swap(vector<BaseballStatistic>&, int, int);
  static void namesort(vector<BaseballStatistic>&);
  static void teamsort(vector<BaseballStatistic>&);
  static int search(vector<BaseballStatistic>&,std::string);
  static int binarysearch(vector<Employee>&, std::string);
};
#endif
