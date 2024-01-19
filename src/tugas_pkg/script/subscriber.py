#!/usr/bin/env python3

import rospy
from tugas_pkg.msg import pesan

def callback(data):
    rospy.loginfo("\n pesan 1:%ld"% data.usia)
    rospy.loginfo("\n pesan 2:%lf"% data.tinggi)
    rospy.loginfo("\n pesan 3:%s"% data.nama)
    rospy.loginfo("\n pesan 4:%s"% data.kehadiran)

def listener():
    rospy.init_node("subscriber", anonymous = True)
    rospy.Subscriber("topik_utama_python",pesan, callback)
    rospy.spin()

if __name__ == "__main__":
    listener()