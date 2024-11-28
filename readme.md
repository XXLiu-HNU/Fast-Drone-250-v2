## **Fast-Drone-250-v2** 

This document is an extension of [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250), which is closer to the real experiment through Gazebo simulation. 

## The main updates are: 
1. Expanded the single drone to multiple drones and expressed them in the form of [MINCO](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2) curves 
2. Added the one-key takeoff function of the [controller](https://github.com/ZJU-FAST-Lab/Fast-Drone-250/tree/master/src/realflight_modules/px4ctrl)
3. Optimized the visual interface

## Achieve results：
![ezgif-5-42c8026229](https://github.com/user-attachments/assets/75632834-749c-4a6a-b7a1-4f90fc709405)

And here is the [video](https://www.bilibili.com/video/BV1c4BRYtENh/?share_source=copy_web&vd_source=694800f4f1ae99186a15066decbc1bc2)(Bilibili)

## How to use: 
1. Follow this [link](https://www.yuque.com/xtdrone/manual_cn/install_scripts) to install the simulation platform. For details, please refer to this [project](https://github.com/robin-shaun/XTDrone)
2. Copy the [startup files](https://github.com/XXLiu-HNU/Fast-Drone-250-v2/blob/master/src/multi_vehicle.launch) and [environment files](https://github.com/XXLiu-HNU/Fast-Drone-250-v2/blob/master/src/forest.world) to the correct directories

   `mv multi_vehicle.launch  ~/Px4_firmare/launch`
   
   `mv forest.world  ~/Px4_firmare/Tools/sitl_gazebo/world`
3. Start Simulation：

   `roslaunch px4 multi_vbhicle.launch`

4. Follow this [link](https://www.yuque.com/xtdrone/manual_cn/pose_groundtruth) to set the location

5. Start planer

   `roslaunch ego_planer swarm_gazebo.launch`

   `roslaunch ego_planer rviz.launch`

5. Start Controller

   `roslaunch px4ctrl multi_run.launch`
   
## Reference Projects
1. [XTdroen](https://github.com/robin-shaun/XTDrone)   
The simulation platform of the experiment is modified based on this project. Interested readers can refer to the [document](https://www.yuque.com/xtdrone/manual_cn/install_scripts) for reproduction
2. [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250)   
The controller module comes from this project, but this project is only for real objects and a single drone
3. [EGO-Planner-v2](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2)   
The cluster planning part comes from this project, but the simulation environment of this project is not consistent with reality
