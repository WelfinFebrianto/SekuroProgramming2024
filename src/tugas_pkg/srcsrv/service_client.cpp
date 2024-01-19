#include "ros/ros.h"
#include "tugas_pkg/magnitude.h"

int main(int argc, char ** argv){
    // Inisialisasi 
    ros::init(argc,argv,"client_server");
    
    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    // Inisialisasi client dari handler
    ros::ServiceClient client = nh.serviceClient<tugas_pkg::magnitude>("magnitude");

    // Inisialisasi variabel sesuai tipe data srv
    tugas_pkg::magnitude dataVariabel;

    // Memberi nilai kepada seluruh data request
    dataVariabel.request.komponenX = 10;
    dataVariabel.request.komponenY = 10;
    dataVariabel.request.komponenZ = 10;

    if (client.call(dataVariabel)){
        ROS_INFO("Jumlah variabel yang dicari adalah: %ld",dataVariabel.response.magnitude);
    }
    else {
        ROS_INFO("Service gagal dipanggil");
    }

}