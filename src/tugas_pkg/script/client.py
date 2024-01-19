#!/usr/bin/env python3

import rospy
from tugas_pkg.srv import magnitude, magnitudeResponse

def magnitude_client(x,y,z):
    # Inisialisasi Node
    rospy.init_node("client")

    rospy.wait_for_service("magnitude_python")
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        try:
            # Inisialisasi Client
            mag = rospy.ServiceProxy('magnitude_python',magnitude)
            response = mag(x,y,z)

            # Mencetak hasil response
            rospy.loginfo(response.magnitude)
            rate.sleep()
        except rospy.ServiceException as e:
            print("Service call failed %s",e)

if __name__ == '__main__':
    magnitude_client(10.0,10.0,10.0)