#include <gtest/gtest.h>
#include "fsm_bump_go/BumpGo.h"
#include "ros/ros.h"

class TestBumpGo : public fsm_bump_go::BumpGo
{
public:
    const int & get_state(){return state_;}
    const bool & get_pressed(){return pressed_;}
    void set_state(const int & state ){state_=state;}
    void set_pressed(const bool & pressed){pressed_=pressed;} 
};

TEST(BumpGo_Test, test_states)
{
    TestBumpGo fsm_bump_go;
    fsm_bump_go.set_state(0);
    fsm_bump_go.set_pressed(false);
    fsm_bump_go.step();
    ASSERT_EQ(fsm_bump_go.get_state(), 0);
    fsm_bump_go.set_state(0);
    fsm_bump_go.set_pressed(true);
    fsm_bump_go.step();
    ASSERT_EQ(fsm_bump_go.get_state(), 1);
    fsm_bump_go.step();
    sleep(4);
    fsm_bump_go.step();
    ASSERT_EQ(fsm_bump_go.get_state(), 2);
    fsm_bump_go.step();
    sleep(4);
    fsm_bump_go.step();
    ASSERT_EQ(fsm_bump_go.get_state(), 0);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "fsm_bump_go");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}