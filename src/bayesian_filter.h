/*
 * basian_filter.h
 *
 *  Created on: Apr 26, 2017
 *      Author: ramiz
 */

#ifndef BAYESIAN_FILTER_H_
#define BAYESIAN_FILTER_H_

#include <vector>
#include <string>
#include <fstream>

#include "measurement_package.h"
#include "map.h"
#include "help_functions.h"

class BayesianFilter {
public:
  //constructor
  BayesianFilter();

  //destructor
  virtual ~BayesianFilter();

  //main public member function, which estimate the beliefs:
  void ProcessMeasurement(const MeasurementPackage &measurements,
                         const Map &map_1d,
                         HelpFunctions &helpers);

  std::vector<float> belief_x;

private:

  void init(const Map &map_1d, HelpFunctions &helpers);

  bool is_initialized_;
  std::vector<float> belief_x_init_;
  float control_std_;
};



#endif /* BAYESIAN_FILTER_H_ */
