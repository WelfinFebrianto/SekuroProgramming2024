#include "ros/ros.h"
#include "tugas_pkg/magnitude.h"
#include <cmath> 
bool add(tugas_pkg::magnitude::Request &req, tugas_pkg::magnitude::Response &resp){
    resp.magnitude = std::sqrt((req.komponenX * req.komponenX) + (req.komponenY * req.komponenY) + (req.komponenZ * req.komponenZ));

    ROS_INFO("\nNilai komponen X: %lf", static_cast<double>(req.komponenX));
    ROS_INFO("\nNilai komponen Y: %lf", static_cast<double>(req.komponenY));
    ROS_INFO("\nNilai komponen Z: %lf", static_cast<double>(req.komponenZ));
    ROS_INFO("\nNilai magnitude: %lf", static_cast<double>(resp.magnitude));
    
    return true;
}

int main(int argc, char**argv){
    ros::init(argc, argv, "service_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("magnitude", add);
    ROS_INFO("Masukkan Komponen X Y dan Z");
    ros::spin();
    return 0;
}
