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

#include "fsm_bump_go/Laser.h"
#include "ros/ros.h"

namespace fsm_bump_go
{

  Laser::Laser()
  : BaseDetected(),
  detected_(false)
  {
      sub_laser_ = n_.subscribe("/scan_filtered", 1, &fsm_bump_go::Laser::laserCallback, this);
  }
  
  void Laser::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
  {
    int start_detection = 0;

    int min_pos = 45*cte;
    int max_pos = 135*cte;

    //int end_detection = msg->ranges.size();

    int middle_position_ = 90*cte;

    int i = start_detection;
    detected_=false;

    std::cout << "tamaño: " << msg->ranges.size() << std::endl;

    for(int j = min_pos; j < max_pos; j++){
      if(msg->ranges[i] < DISTANCE_DETECT){
        detected_ = msg->ranges[i];
        object_position_ = j;
        break;
      }
    }
    /*while ((!detected_) && (min_pos < i < max_pos) && (msg->ranges[i] < msg->range_max) && (msg->ranges[i] > msg->range_min))
    {
      detected_ = msg->ranges[i] < fsm_bump_go::Laser::DISTANCE_DETECT;
      object_position_ = i;
      i++;
    } */
  }

  void Laser::step()
  {
    geometry_msgs::Twist cmd;

    switch (state_)
  {
    case GOING_FORWARD:
      cmd.linear.x = 0.1;
      cmd.angular.z = 0;

      if (detected_)
      {
        laserdetect_ts_ = ros::Time::now();
        state_ = GOING_BACK;
        ROS_INFO("GOING_FORWARD -> GOING_BACK");
      }

      break;
    case GOING_BACK:
      cmd.linear.x = -0.1;
      cmd.angular.z = 0;

      if ((ros::Time::now() - laserdetect_ts_).toSec() > BACKING_TIME )
      {
        turn_ts_ = ros::Time::now();
        std::cout << object_position_<<std::endl;
        if( object_position_ > middle_position_)
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
      cmd.angular.z = -0.66;

      if ((ros::Time::now()-turn_ts_).toSec() > TURNING_TIME )
      {
        state_ = GOING_FORWARD;
        ROS_INFO("TURNING_RIGHT -> GOING_FORWARD");
      }
      break;
    case TURNING_LEFT:
      cmd.linear.x = 0;
      cmd.angular.z = 0.66;

      if ((ros::Time::now()-turn_ts_).toSec() > TURNING_TIME )
      {
        state_ = GOING_FORWARD;
        ROS_INFO("TURNING_LEFT -> GOING_FORWARD");
      }
      break;
    }

    pub_vel_.publish(cmd);

  }

} // namespace fsm_bump_go