#!/usr/bin/env python3

import rospy
from tugas_pkg.msg import pesan

def talker():
    message_pub = rospy.Publisher("topik_utama_python", pesan, queue_size = 10)
    rospy.init_node('publsher', anonymous = True)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        dataVariabel = pesan()
        dataVariabel.usia =17
        dataVariabel.tinggi = 170
        dataVariabel.nama = "Welfin"
        dataVariabel.kehadiran = True

        rospy.loginfo("\n pesan 1:%ld"% dataVariabel.usia)
        rospy.loginfo("\n pesan 2:%lf"% dataVariabel.tinggi)
        rospy.loginfo("\n pesan 3:%s"% dataVariabel.nama)
        rospy.loginfo("\n pesan 4:%s"% dataVariabel.kehadiran)

        message_pub.publish(dataVariabel)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
