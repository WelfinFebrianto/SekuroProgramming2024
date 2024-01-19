#include "ros/ros.h"
#include "tugas_pkg/pesan.h"

int main (int argc, char ** argv){
    ros::init(argc,argv,"simple_publisher_cpp");

    ros::NodeHandle nh;

    ros::Publisher data_publisher = nh.advertise<tugas_pkg::pesan>("topik_utama",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()){
        tugas_pkg::pesan pesanMauDikirim;

        pesanMauDikirim.usia = 17;
        pesanMauDikirim.tinggi = 170;
        pesanMauDikirim.nama = "Welfin";
        pesanMauDikirim.kehadiran = true ;

        ROS_INFO("Pesan 1 :%ld", pesanMauDikirim.usia);
        ROS_INFO("Pesan 2 :%lf", pesanMauDikirim.tinggi);
        ROS_INFO("Pesan 3 :%s", pesanMauDikirim.nama.c_str());
        ROS_INFO("Pesan 4 :%s", pesanMauDikirim.kehadiran ? "true" : "false");

        data_publisher.publish(pesanMauDikirim);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}