#ifndef FILTER_H
#define FILTER_H
#include <string>
#include <vector>
#include <iostream>
#include "StringHelper.h"
#include "BaseballStatistic.h"

using namespace std;

class Filter {
  public:
  static void swap(vector<BaseballStatistic>&, int, int);
  static void namesort(vector<BaseballStatistic>&);
  static void teamsort(vector<BaseballStatistic>&);
  static int search(vector<BaseballStatistic>&, std::string);
  static int binarysearch(vector<BaseballStatistic>&, std::string);
};
#endif
