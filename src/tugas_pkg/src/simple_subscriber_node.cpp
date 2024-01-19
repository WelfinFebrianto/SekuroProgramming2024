#include "ros/ros.h"
#include "tugas_pkg/pesan.h"

void callbackHandler(const tugas_pkg::pesan::ConstPtr &msg){
    ROS_INFO("\n Saya mendengar :\n");
    ROS_INFO("Pesan 1 :%ld\n", msg->usia);
    ROS_INFO("Pesan 2 :%lf\n", msg->tinggi);
    ROS_INFO("Pesan 3 :%s\n", msg->nama.c_str());
    ROS_INFO("Pesan 4 :%s\n",msg->kehadiran ? "true":"false" );
}

int main(int argc, char ** argv){
    ros::init(argc, argv,"simple_subscriber_node");
    ros::NodeHandle nh;
    ros::Subscriber data_subscriber = nh.subscribe("topik_utama",1000,callbackHandler);
    ros::spin();
    return 0;
}