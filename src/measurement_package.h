/*
 * measurement_package.h
 *
 *  Created on: Apr 24, 2017
 *      Author: ramiz
 */

#ifndef MEASUREMENT_PACKAGE_H_
#define MEASUREMENT_PACKAGE_H_

#include <vector>

class MeasurementPackage {
public:
  struct Control {
    float delta_x; // move to successor along x-axis
  };

  struct Observation {
    std::vector<float> distances; //distances to observed landmarks
  };

  Control control_;
  Observation observation_;
};


#endif /* MEASUREMENT_PACKAGE_H_ */
