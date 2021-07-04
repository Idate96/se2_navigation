/*
 * dd_standalone_example.cpp
 *
 *  Created on: Jul 4, 2021
 *      Author: jelavice
 */



#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <pure_pursuit_ros/PurePursuitConfig.h>

void callback(pure_pursuit_ros::PurePursuitConfig &config, uint32_t level) {
	  ROS_INFO("Reconfigure Request: \n LookaheadDistance: %f ",
	             config.lookahead_fwd);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "dd_standalone_example");

  boost::recursive_mutex ddMutex;
  dynamic_reconfigure::Server<pure_pursuit_ros::PurePursuitConfig> server(ddMutex);
  dynamic_reconfigure::Server<pure_pursuit_ros::PurePursuitConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);


//  pure_pursuit_ros::PurePursuitConfig dummyCfg;
//
//  dummyCfg.int_param = 99;
//  server.updateConfig(dummyCfg);
//  ros::spinOnce();
//  ROS_INFO("Now the int param should be %d", dummyCfg.int_param);
//

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
