## **Fast-Drone-250-v2** 

This document is an extension of [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250), which is closer to the real experiment through Gazebo simulation. 

## The main updates are: 
1. Expanded the single drone to multiple drones and expressed them in the form of [MINCO](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2) curves 
2. Added the one-key takeoff function of the [controller](https://github.com/ZJU-FAST-Lab/Fast-Drone-250/tree/master/src/realflight_modules/px4ctrl)
3. Optimized the visual interface

## Reference Projects
1. [XTdroen](https://github.com/robin-shaun/XTDrone)   
The simulation platform of the experiment is modified based on this project. Interested readers can refer to the [document](https://www.yuque.com/xtdrone/manual_cn/install_scripts) for reproduction
2. [Fast-Drone-250](https://github.com/ZJU-FAST-Lab/Fast-Drone-250)   
The controller module comes from this project, but this project is only for real objects and a single drone
3. [EGO-Planner-v2](https://github.com/ZJU-FAST-Lab/EGO-Planner-v2)   
The cluster planning part comes from this project, but the simulation environment of this project is not consistent with reality