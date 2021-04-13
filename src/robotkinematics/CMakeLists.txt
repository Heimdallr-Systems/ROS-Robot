cmake_minimum_required(VERSION 3.0.2)
project(robotkinematics)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  std_msgs
  servo_control
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   MotorVector.msg
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   goToInit.srv
#   Service2.srv
 )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   servo_control
#   nav_msgs#   std_msgs
 )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
# double*, double*, double*)'
#/home/heimdallr/ros1_ws/devel/lib/librot##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES robotkinematics
#  CATKIN_DEPENDS nav_msgs roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  matlab_code
 include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/robotkinematics.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/robotkinematics_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_robotkinematics.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(kinematics_wrapper src/kinematics_wrapper.cpp)
add_library(Robot_Control include/Robot_Control.cpp)
target_link_libraries(kinematics_wrapper ${catkin_LIBRARIES})
target_link_libraries(kinematics_wrapper Robot_Control)
add_library(rotz include/rotz.cpp)
target_link_libraries(Robot_Control rotz)
add_library(find_pgon_goal include/find_pgon_goal.cpp)
target_link_libraries(Robot_Control find_pgon_goal)

add_library(b_sin include/sin.cpp)
target_link_libraries(rotz b_sin)
add_library(Leg_Controller include/Leg_Controller.cpp)
target_link_libraries(Robot_Control Leg_Controller)
add_library(Body_Pose_Controller include/Body_Pose_Controller.cpp)
target_link_libraries(Robot_Control Body_Pose_Controller)
add_library(CPos_wrt_I include/CPos_wrt_I.cpp)
target_link_libraries(Robot_Control CPos_wrt_I)
add_library(abs include/abs.cpp)
target_link_libraries(Robot_Control abs)
add_library(alllib include/all.cpp)
target_link_libraries(Robot_Control alllib)
add_library(centroid_codeGen include/centroid_codeGen.cpp)
target_link_libraries(Robot_Control centroid_codeGen)
add_library(roty include/roty.cpp)
target_link_libraries(Robot_Control roty)
add_library(manipulability include/manipulability.cpp)
target_link_libraries(Robot_Control manipulability)

add_library(prod include/prod.cpp)
target_link_libraries(manipulability prod)
add_library(svd include/svd.cpp)
target_link_libraries(manipulability svd)


#add_library(anyNonFinite include/anyNonFinite.cpp)
#target_link_libraries(svd anyNonFinite)
#target_link_libraries(svd rt_nonfinite)
add_library(svd1 include/svd1.cpp)
target_link_libraries(svd svd1)

add_library(Robot_Control_data include/Robot_Control_data.cpp)
target_link_libraries(Leg_Controller Robot_Control_data)
add_library(angle include/angle.cpp)
add_library(angle1 include/angle1.cpp)
target_link_libraries(angle angle1)

target_link_libraries(Leg_Controller angle)
add_library(atan2 include/atan2.cpp)
target_link_libraries(Leg_Controller atan2)
add_library(cos include/cos.cpp)
target_link_libraries(Leg_Controller cos)
add_library(exp include/exp.cpp)
target_link_libraries(Leg_Controller exp)
add_library(mldivide include/mldivide.cpp)
target_link_libraries(Leg_Controller mldivide)
add_library(norm include/norm.cpp)
target_link_libraries(Leg_Controller norm)
add_library(sqrt include/sqrt.cpp)
target_link_libraries(Leg_Controller sqrt)

#add_library(rt_nonfinite include/rt_nonfinite.cpp)
#target_link_libraries(exp rt_nonfinite)
#target_link_libraries(cos rt_nonfinite)
#add_library(vAllOrAny include/vAllOrAny.cpp)
#target_link_libraries(anyNonFinite vAllOrAny)

add_library(exp1 include/exp1.cpp)
target_link_libraries(exp exp1)
add_library(cos1 include/cos1.cpp)
target_link_libraries(cos cos1)

add_library(combineVectorElements include/combineVectorElements.cpp)
target_link_libraries(prod combineVectorElements)

add_library(abs1 include/abs1.cpp)
target_link_libraries(abs abs1)

#add_library(isinf include/isinf.cpp)
#target_link_libraries(exp1 isinf)
add_library(allOrAny include/allOrAny.cpp)
target_link_libraries(alllib allOrAny)
add_library(ifWhileCond include/ifWhileCond.cpp)
target_link_libraries(Robot_Control ifWhileCond)
add_library(atan21 include/atan21.cpp)
target_link_libraries(atan2 atan21)
add_library(rotx include/rotx.cpp)
target_link_libraries(Robot_Control rotx)
add_library(inpolygon include/inpolygon.cpp)
target_link_libraries(find_pgon_goal inpolygon)
add_library(cross include/cross.cpp)
target_link_libraries(find_pgon_goal cross)
add_library(circshift include/circshift.cpp)
target_link_libraries(centroid_codeGen circshift)
add_library(lusolve include/lusolve.cpp)
target_link_libraries(mldivide lusolve)
add_library(isnan include/isnan.cpp)
target_link_libraries(inpolygon isnan)
add_library(xzsvdc include/xzsvdc.cpp)
target_link_libraries(svd1 xzsvdc)
add_library(sign include/sign.cpp)
target_link_libraries(Robot_Control sign)
add_library(xaxpy include/xaxpy.cpp)
target_link_libraries(xzsvdc xaxpy)
add_library(xnrm2 include/xnrm2.cpp)
target_link_libraries(xzsvdc xnrm2)
add_library(xrot include/xrot.cpp)
target_link_libraries(xzsvdc xrot)
add_library(xdotc include/xdotc.cpp)
target_link_libraries(xzsvdc xdotc)
add_library(xscal include/xscal.cpp)
target_link_libraries(xzsvdc xscal)
add_library(sign1 include/sign1.cpp)
target_link_libraries(sign sign1)
add_library(xdot include/xdot.cpp)
target_link_libraries(xdotc xdot)
add_library(xswap include/xswap.cpp)
target_link_libraries(xzsvdc xswap)
add_library(sort include/sort.cpp)
target_link_libraries(Robot_Control sort)
add_library(sortIdx include/sortIdx.cpp)
target_link_libraries(sort sortIdx)
add_library(sum include/sum.cpp)
target_link_libraries(centroid_codeGen sum)
add_library(Leg_Controller_B include/Leg_Controller_B.cpp)
target_link_libraries(Robot_Control Leg_Controller_B)
#add_library(isfinite include/isfinite.cpp)
#target_link_libraries(vAllOrAny isfinite)
add_library(xrotg include/xrotg.cpp)
target_link_libraries(xzsvdc xrotg)
add_library(contactJacobians include/contactJacobians.cpp)
target_link_libraries(manipulability contactJacobians)
add_library(recursiveKin include/recursiveKin.cpp)
target_link_libraries(contactJacobians recursiveKin)
add_library(step_planner_intelligent include/step_planner_intelligent.cpp)
target_link_libraries(Robot_Control step_planner_intelligent)
add_library(eye include/eye.cpp)
target_link_libraries(Robot_Control eye)
add_library(isequal include/isequal.cpp)
target_link_libraries(Robot_Control isequal)
add_library(sqrt1 include/sqrt1.cpp)
target_link_libraries(sqrt sqrt1)
add_library(sin1 include/sin1.cpp)
target_link_libraries(b_sin sin1)
add_library(skew include/skew.cpp)
target_link_libraries(recursiveKin skew)

