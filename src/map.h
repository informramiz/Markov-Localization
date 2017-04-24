/*
 * Map
 *
 *  Created on: Apr 24, 2017
 *      Author: ramiz
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>

class Map {
public:
  //definition of single landmark:
  struct SingleLandmark {
    int id;
    float x;
  };

  //list of landmarks
  std::vector<SingleLandmark> landmark_list_;
};



#endif /* MAP_H_ */
