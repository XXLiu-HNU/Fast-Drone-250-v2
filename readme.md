## **Fast-Drone-250-v2** 

This document is an extension of [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250), which is closer to the real experiment through Gazebo simulation. 

## 🚀 Key Features
1. Expanded the single drone to multiple drones and expressed them in the form of [MINCO](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2) curves 
2. Added the one-key takeoff function of the [controller](https://github.com/ZJU-FAST-Lab/Fast-Drone-250/tree/master/src/realflight_modules/px4ctrl)
3. Optimized the visual interface

## 📸 Demo & Results
![ezgif-5-42c8026229](https://github.com/user-attachments/assets/75632834-749c-4a6a-b7a1-4f90fc709405)

📺 ​Full Demo Video: [video](https://www.bilibili.com/video/BV1c4BRYtENh/?share_source=copy_web&vd_source=694800f4f1ae99186a15066decbc1bc2)(Bilibili)

## 🛠️ Getting Started
1. Follow this [link](https://www.yuque.com/xtdrone/manual_cn/install_scripts) to install the simulation platform. For details, please refer to this [project](https://github.com/robin-shaun/XTDrone)
2. Copy the [startup files](https://github.com/XXLiu-HNU/Fast-Drone-250-v2/blob/master/src/multi_vehicle.launch) and [environment files](https://github.com/XXLiu-HNU/Fast-Drone-250-v2/blob/master/src/forest.world) to the correct directories

   `mv multi_vehicle.launch  ~/Px4_firmware/launch`
   
   `mv forest.world  ~/Px4_firmware/Tools/sitl_gazebo/world`
3. Start Simulation：

   `roslaunch px4 multi_vehicle.launch`

4. Follow this [link](https://www.yuque.com/xtdrone/manual_cn/pose_groundtruth) to set the location
5. Clone the code and compile
   ```
   cd {work_space}
   git clone https://github.com/XXLiu-HNU/Fast-Drone-250-v2.git
   catkin_make
   ```

7. Start planer

   In Terminal 1 
   ```
   cd ${work_space}
   source devel/setup.bash
   roslaunch ego_planner swarm_gazebo.launch
   ```
   In Terminal 2
   ```
   cd ${work_space}
   source devel/setup.bash
   roslaunch ego_planner rviz.launch
   ```

8. Start Controller

   `roslaunch px4ctrl multi_run.launch`

## Monitoring UAV State 
You can use this [tools](https://github.com/XXLiu-HNU/uav-monitor) to monitor the UAV's state and the mode of the planer and controller.

<img src="https://github.com/user-attachments/assets/99abd26d-ba97-4fdd-9e58-1f276fb70bf8" alt="image_00000" width="600"/>

## ⚠️ Known Limitations

 1. The **drone position detection module** was not added, which resulted in other drones being modeled as obstacles when building the map, resulting in mediocre planning results.

 2. The performance of the linear controller is average, and the tracking effect of the drone is average. The drone trajectory does not overlap with the planned trajectory, and the drone is **prone to collision when the speed is high**.

## Reference Projects
1. [XTDroen](https://github.com/robin-shaun/XTDrone)   
The simulation platform of the experiment is modified based on this project. Interested readers can refer to the [document](https://www.yuque.com/xtdrone/manual_cn/install_scripts) for reproduction
2. [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250)   
The controller module comes from this project, but this project is only for real objects and a single drone
3. [EGO-Planner-v2](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2)   
The cluster planning part comes from this project, but the simulation environment of this project is not consistent with reality
