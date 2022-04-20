#!/usr/bin/env python3

import rospy 
from std_msgs.msg import String

def callback_data(msg):
	pub = rospy.Publisher("/filtered-gps", String, queue_size=10)
	pub.publish("Message recieved:")	
	pub.publish(msg)

if __name__ == '__main__':

	rospy.init_node('sub-pub-script')
	
	sub = rospy.Subscriber("/gps-data", String, callback_data)
	
	rospy.spin()
