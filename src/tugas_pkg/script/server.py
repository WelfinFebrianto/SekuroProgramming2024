#!/usr/bin/env python3

import rospy
from tugas_pkg.srv import magnitude, magnitudeResponse

def penghitung(req):
    # Mengolah & mencetak data
    result = ((req.komponenX)**2 + (req.komponenY)**2 + (req.komponenZ)**2)**0.5
    rospy.loginfo("Returning [%ld + %ld + %ld = %lf]" % (req.komponenX, req.komponenY, req.komponenZ, result))
    return magnitudeResponse(result)

def magnitude_server():
    # Inisialisasi Node
    rospy.init_node("server")
    
    # Insialisasi Server
    s = rospy.Service('magnitude_python', magnitude, penghitung)
    rospy.loginfo("Server siap melayani permintaan magnitude.")
    rospy.spin()

if __name__ == '__main__':
    magnitude_server()
