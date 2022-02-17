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

#include "ros/ros.h"

#include "fsm_bump_go/BumpGoEficiente.h"

namespace fsm_bump_go
{

BumpGoEficiente::BumpGoEficiente()
: BaseDetected(),
  pressed_(false),
  side_(0)
{
  sub_bumber_ = n_.subscribe("mobile_base/events/bumper", 1, &fsm_bump_go::BumpGoEficiente::bumperCallback, this);
}

void
BumpGoEficiente::bumperCallback(const kobuki_msgs::BumperEvent::ConstPtr& msg)
{
  pressed_ = msg->state == kobuki_msgs::BumperEvent::PRESSED;
  side_ = msg->bumper == kobuki_msgs::BumperEvent::LEFT;
}

void
BumpGoEficiente::step()
{
  geometry_msgs::Twist cmd;

  switch (state_)
  {
    case GOING_FORWARD:
    
      cmd.linear.x = fordward_vel;
      cmd.angular.z = 0;

      if (pressed_)
      {
        press_ts_ = ros::Time::now();
        state_ = GOING_BACK;
        ROS_INFO("GOING_FORWARD -> GOING_BACK");
      }

      break;
    case GOING_BACK:
      cmd.linear.x = back_vel;
      cmd.angular.z = 0;

      if ((ros::Time::now() - press_ts_).toSec() > backing_time )
      {
        turn_ts_ = ros::Time::now();
        if(side_ == 1)
        {
          state_ = TURNING_RIGHT;
          ROS_INFO("GOING_BACK -> TURNING_RIGHT");
        }
        else
        {
          state_ = TURNING_LEFT;
          ROS_INFO("GOING_BACK -> TURNING_LEFT");
        }
      }

      break;
    case TURNING_RIGHT:

      cmd.linear.x = 0;
      cmd.angular.z = turning_right_vel;

      if ((ros::Time::now()-turn_ts_).toSec() > turning_time )
      {
        state_ = GOING_FORWARD;
        ROS_INFO("TURNING_RIGHT -> GOING_FORWARD");
      }
      break;
    case TURNING_LEFT:
      cmd.linear.x = 0;
      cmd.angular.z = turning_left_vel;

      if ((ros::Time::now()-turn_ts_).toSec() > turning_time )
      {
        state_ = GOING_FORWARD;
        ROS_INFO("TURNING_LEFT -> GOING_FORWARD");
      }
      break;
    }

    pub_vel_.publish(cmd);
}

}  // namespace fsm_bump_go