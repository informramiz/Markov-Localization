/*
 * basian_filter.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: ramiz
 */

#include "bayesian_filter.h"

#include <iostream>

BayesianFilter::BayesianFilter() {
  is_initialized_ = false;
  control_std_ = 1.0f;

  belief_x_init_.resize(100, 0);
  belief_x.resize(100, 0);
}

BayesianFilter::~BayesianFilter() {

}

void BayesianFilter::init(const Map &map_1d, HelpFunctions &helpers) {
  //run over map, all landmark values in map_1d
  for (int l = 0; l < map_1d.landmark_list_.size(); ++l) {
    //get landmark l from map
    Map::SingleLandmark single_landmark = map_1d.landmark_list_[l];

    //check if landmark position x fits in map[0, 100]
    if (!(single_landmark.x >= 0 && single_landmark.x < 100)) {
      continue;
    }

    //set belief to 1 at position and +/- from position:
    int x = single_landmark.x;
    belief_x_init_[x] = 1;
    if (x > 0) {
      belief_x_init_[x - 1] = 1;
    }

    if (x < 99) {
      belief_x_init_[x + 1] = 1;
    }
  } //end for loop

  //normalize initial believe
  belief_x_init_ = helpers.NormalizeVector(belief_x_init_);

  is_initialized_ = true;
}

void BayesianFilter::ProcessMeasurement(const MeasurementPackage &measurements,
                                        const Map &map_1d,
                                        HelpFunctions &helpers) {

  /******************************************************************************
   *  Set init belief of state vector:
   ******************************************************************************/
  if (!is_initialized_) {
    init(map_1d, helpers);
  } //end if

  /******************************************************************************
   *  motion model and observation update
   ******************************************************************************/
  std::cout << "-->motion model for state x ! \n" << std::endl;

  //get current observations and control information:
  MeasurementPackage::Control controls = measurements.control_;
  MeasurementPackage::Observation observations = measurements.observation_;

  //run over all bel_x values (index represents the pose in x!):
  for (int i = 0; i < belief_x.size(); ++i) {

    float pose_i = float(i);

    /**************************************************************************
     *  posterior for motion model
     **************************************************************************/

    // motion posterior:
    // used to set up the convlution
    float posterior_motion = 0.0f;

    //loop over state space x_t-1 * same size as bel_x (Perform Convolution):
    for (int j = 0; j < belief_x_init_.size(); ++j) {

      float pose_j = float(j);
      float distance_ij = pose_i - pose_j;
      //Calculate transition probabilites using helpers.normpdf()
      // x: difference between bel_x index and state space index
      // mu: the movement from controls defined above
      // std: defined eariler
      float transition_model_probability = helpers.Normpdf(distance_ij,
          controls.delta_x, control_std_);

      //Calculate motion model
      // ADD the transition prob multiplied by the initial believe
      // at state space index

      posterior_motion += transition_model_probability * belief_x_init_[j];
    }

    //update = motion_model
    // set as the posterior_motion
    belief_x[i] = posterior_motion;
  }
  //normalize bel_x:
  belief_x = helpers.NormalizeVector(belief_x);

  //set initial believe to bel_x for next time
  belief_x_init_ = belief_x;
}
