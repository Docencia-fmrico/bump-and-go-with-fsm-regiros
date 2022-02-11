cmake_minimum_required(VERSION 2.8.3)
project(fsm_bump_go)

set(CMAKE_CXX_STANDARD 17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  kobuki_msgs
  roslint
  geometry_msgs
)

catkin_package(
CATKIN_DEPENDS roscpp std_msgs kobuki_msgs sensor_msgs geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_library(${PROJECT_NAME}
  src/fsm_bump_go/BumpGo.cpp
  src/fsm_bump_go/BumpGoEficiente.cpp
)

add_executable(bumpgo_node src/bumpgo_node.cpp)
target_link_libraries(bumpgo_node ${catkin_LIBRARIES} ${PROJECT_NAME})

add_executable(bumpgoeficiente_node src/bumpgoeficiente_node.cpp)
target_link_libraries(bumpgoeficiente_node ${catkin_LIBRARIES} ${PROJECT_NAME})

roslint_cpp(
 src/bumpgo_node.cpp
 src/bumpgoeficiente_node.cpp
 src/fsm_bump_go/BumpGo.cpp
 src/fsm_bump_go/BumpGoEficiente.cpp
 include/fsm_bump_go/BumpGo.h
 include/fsm_bump_go/BaseDetected.h
 include/fsm_bump_go/BumpGoEficiente.h
)
catkin_add_gtest(BumpGo_Test tests/BumpGo_Test.cpp)
add_dependencies(BumpGo_Test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
if(TARGET BumpGo_Test)
  target_link_libraries(BumpGo_Test ${catkin_LIBRARIES} ${PROJECT_NAME})
endif()