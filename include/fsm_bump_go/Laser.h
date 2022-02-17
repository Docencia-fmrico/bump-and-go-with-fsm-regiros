// Copyright 2022 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef FSM_BUMP_GO_LASER_H
#define FSM_BUMP_GO_LASER_H

#include "BaseDetected.h"
#include "sensor_msgs/LaserScan.h"

namespace fsm_bump_go
{
  class Laser : public BaseDetected
  {
    public:
      Laser();

      void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
      void step();
    
    private:

      bool detected_;
      float DISTANCE_DETECT = 0.5;

      float cte = 760 / 360;
      //float angle_min = 3.14/4
      //float angle_max = 3.14*3/4

      int middle_position_;
      int object_position_;

      ros::Time laserdetect_ts_;
      ros::Subscriber sub_laser_;
  };
} // namespace fsm_bump_go

#endif  // FSM_BUMP_GO_LASER_H