

1615804386.090686542  Node Startup
0.000000000 INFO /stageros [/tmp/binarydeb/ros-noetic-stage-ros-1.8.0/src/stageros.cpp:334(SubscribeModels)] [topics: /rosout, /tf] Subscribed to Stage position model "robot_1"
0.000000000 INFO /stageros [/tmp/binarydeb/ros-noetic-stage-ros-1.8.0/src/stageros.cpp:358(SubscribeModels)] [topics: /rosout, /tf] Robot robot_1 provided 0 rangers and 0 cameras
0.000000000 INFO /stageros [/tmp/binarydeb/ros-noetic-stage-ros-1.8.0/src/stageros.cpp:334(SubscribeModels)] [topics: /rosout, /tf, /robot_0/odom, /robot_0/base_pose_ground_truth] Subscribed to Stage position model "robot_2"
0.000000000 INFO /stageros [/tmp/binarydeb/ros-noetic-stage-ros-1.8.0/src/stageros.cpp:358(SubscribeModels)] [topics: /rosout, /tf, /robot_0/odom, /robot_0/base_pose_ground_truth] Robot robot_2 provided 0 rangers and 0 cameras
1042.940000000 ERROR /turtlebot_controller_274193_1615805571860 [topics.py:753(_SubscriberImpl._invoke_callback)] [topics: /robot_0/cmd_vel, /clock, /rosout, /robot_1/cmd_vel, /robot_0/odom, /new_stage_info, /GEPP_request, /robot_1/odom] bad callback: <function GEPP at 0x7ffb2f6568b0>
Traceback (most recent call last):
  File "/opt/ros/noetic/lib/python3/dist-packages/rospy/topics.py", line 750, in _invoke_callback
    cb(msg)
  File "control.py", line 58, in GEPP
    if resourceList.isPOrdered(tmp_state,fleet):
  File "/home/ljaniec/Documents/MMRS/repos/priority-mmrs/master/resourceList.py", line 17, in isPOrdered
    for j in range(state[i], len(self.stagesList[i])):
IndexError: list index out of range

1043.320000000 ERROR /turtlebot_controller_274193_1615805571860 [topics.py:753(_SubscriberImpl._invoke_callback)] [topics: /robot_0/cmd_vel, /clock, /rosout, /robot_1/cmd_vel, /robot_0/odom, /new_stage_info, /GEPP_request, /robot_1/odom] bad callback: <function GEPP at 0x7ffb2f6568b0>
Traceback (most recent call last):
  File "/opt/ros/noetic/lib/python3/dist-packages/rospy/topics.py", line 750, in _invoke_callback
    cb(msg)
  File "control.py", line 58, in GEPP
    if resourceList.isPOrdered(tmp_state,fleet):
  File "/home/ljaniec/Documents/MMRS/repos/priority-mmrs/master/resourceList.py", line 17, in isPOrdered
    for j in range(state[i], len(self.stagesList[i])):
IndexError: list index out of range

