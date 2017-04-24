/*
 * help_functions.h
 *
 *  Created on: Apr 24, 2017
 *      Author: ramiz
 */

#ifndef HELP_FUNCTIONS_H_
#define HELP_FUNCTIONS_H_

#include <cmath>
#include <string>
#include "map.h"
#include "measurement_package.h"

class HelpFunctions {
public:

  //definition of one over square root of 2*pi:
  const float ONE_OVER_SQRT_2PI;

  //Constructor
  HelpFunctions();

  //definition square:
  float squared(float x);

  /*****************************************************************************
   * normpdf(X,mu,sigma) computes the probability function at values x using the
   * normal distribution with mean mu and standard deviation std. x, mue and
   * sigma must be scalar! The parameter std must be positive.
   * The normal pdf is y=f(x;mu,std)= 1/(sqrt(2pi * square(std)) * e ^ [ -(x−mu)^2 / 2*std^2 ]
  *****************************************************************************/
  float Normpdf(float x, float mu, float std);

  //function to normalize a vector:
  std::vector<float> NormalizeVector(std::vector<float> inputVector);


  /* Reads map data from a file.
   * @param filename Name of file containing map data.
   */
  bool ReadMapData(std::string filename, Map& map);


  /* Reads measurements from a file.
   * @param filename Name of file containing measurement  data.
   */
  bool ReadMeasurementData(std::string filename_control,
                             std::string filename_obs,
                             std::vector<MeasurementPackage>& measurement_pack_list);

  bool CompareData(std::string filename_gt,
                           std::vector<float>& result_vec);
};




#endif /* HELP_FUNCTIONS_H_ */
