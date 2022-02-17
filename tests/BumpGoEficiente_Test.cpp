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

#include <gtest/gtest.h>
#include "ros/ros.h"
#include "fsm_bump_go/BumpGoEficiente.h"

class TestBumpGoEficiente: public fsm_bump_go::BumpGoEficiente
{
    public:
        const bool & get_pressed_(){ return pressed_; }
        const int & get_side_(){ return side_; }
};

TEST(BumpGoEficiente_Test, test_init)
{
    TestBumpGoEficiente fsm_bump_go;

    ASSERT_EQ(fsm_bump_go.get_pressed_(), false);
    ASSERT_EQ(fsm_bump_go.get_side_(), 0);
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"tests");

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}