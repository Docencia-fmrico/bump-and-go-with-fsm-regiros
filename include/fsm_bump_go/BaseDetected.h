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

#ifndef FSM_BUMP_GO_BASEDETECTED_H
#define FSM_BUMP_GO_BASEDETECTED_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

namespace fsm_bump_go
{

class BaseDetected
{
public:
  BaseDetected()
  :n_("~"),
  state_(GOING_FORWARD)
   {
     pub_vel_ = n_.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 1);
   }
   
  virtual void step()=0;

protected:
  ros::NodeHandle n_;

  static const int GOING_FORWARD = 0;
  static const int GOING_BACK = 1;
  static const int TURNING_RIGHT = 2;
  static const int TURNING_LEFT = 3;

  double turning_time = n_.param("turning_time", 3.0);
  double backing_time = n_.param("backing_time", 3.0);

  double fordward_vel = n_.param("fordward_vel", 0.1);
  double back_vel = n_.param("back_vel", -0.1);
  double turning_right_vel = n_.param("turning_right_vel", -0.66);
  double turning_left_vel = n_.param("turning_left_vel", 0.66);

  int state_;

  ros::Time turn_ts_;

  ros::Publisher pub_vel_;
};

}  // namespace fsm_bump_go

#endif  // FSM_BUMP_GO_BASEDETECTED_H
