#ifndef FILTER_H
#define FILTER_H

#include "BaseballStatistic.h"
#include <string>

using namespace std;

class Filter {
  public:
  static void swap(vector<BaseballStatistic>&, int, int);
  static void namesort(vector<BaseballStatistic>&);
  static int search(vector<BaseballStatistic>&, std::string, std::string, std::string, std::string);
};
#endif
