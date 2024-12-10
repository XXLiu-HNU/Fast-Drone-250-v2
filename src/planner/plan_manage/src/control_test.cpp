#include <nav_msgs/Odometry.h>
#include <traj_utils/PolyTraj.h>
#include <optimizer/poly_traj_utils.hpp>
#include <quadrotor_msgs/PositionCommand.h>
#include <std_msgs/Empty.h>
#include <visualization_msgs/Marker.h>
#include <ros/ros.h>


using namespace Eigen;
ros::Publisher pos_cmd_pub;

quadrotor_msgs::PositionCommand cmd;
Eigen::Vector3d last_pos_;
// Function to calculate a figure-8 trajectory
void publish_cmd(Vector3d p, Vector3d v, Vector3d a, Vector3d j, double y, double yd)
{

  cmd.header.stamp = ros::Time::now();
  cmd.header.frame_id = "world";
  cmd.trajectory_flag = quadrotor_msgs::PositionCommand::TRAJECTORY_STATUS_READY;
  cmd.trajectory_id = 1;

  cmd.position.x = p(0);
  cmd.position.y = p(1);
  cmd.position.z = p(2);
  cmd.velocity.x = v(0);
  cmd.velocity.y = v(1);
  cmd.velocity.z = v(2);
  cmd.acceleration.x = a(0);
  cmd.acceleration.y = a(1);
  cmd.acceleration.z = a(2);
  cmd.jerk.x = j(0);
  cmd.jerk.y = j(1);
  cmd.jerk.z = j(2);
  cmd.yaw = y;
  cmd.yaw_dot = yd;
  pos_cmd_pub.publish(cmd);

  last_pos_ = p;
}
void calculateFigure8(double t, Vector3d& pos, Vector3d& vel, 
                      Vector3d& acc, Vector3d& jer, 
                      double& yaw, double& yawdot) {
    // Trajectory parameters
    double a = 5.0; // Amplitude of the figure-8
    double omega = 0.5; // Frequency

    // Position
    pos.x() = a * sin(omega * t);
    pos.y() = a * sin(2 * omega * t);
    pos.z() = 1.0; // Fixed height

    // Velocity
    vel.x() = a * omega * cos(omega * t);
    vel.y() = 2 * a * omega * cos(2 * omega * t);
    vel.z() = 0.0;

    // Acceleration
    acc.x() = -a * omega * omega * sin(omega * t);
    acc.y() = -4 * a * omega * omega * sin(2 * omega * t);
    acc.z() = 0.0;

    // Jerk
    jer.x() = -a * omega * omega * omega * cos(omega * t);
    jer.y() = -8 * a * omega * omega * omega * cos(2 * omega * t);
    jer.z() = 0.0;

    // Yaw and Yaw Rate
    yaw = atan2(vel.y(), vel.x());
    yawdot = 0.0; // Yaw rate can be adjusted based on specific needs
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "figure8_trajectory");
    ros::NodeHandle nh;

    // Define the publishing rate
    ros::Rate rate(50); // 50 Hz

    // Define publisher (replace with your topic)
    pos_cmd_pub = nh.advertise<quadrotor_msgs::PositionCommand>("/iris_1/position_cmd", 50);

    // Variables to store trajectory commands
    Vector3d pos, vel, acc, jer;
    double yaw, yawdot;

    double t = 0.0; // Time variable
    double dt = 1.0 / 50.0; // Time step (corresponding to 50 Hz)

    while (ros::ok()) {
        // Compute the trajectory
        calculateFigure8(t, pos, vel, acc, jer, yaw, yawdot);

        // Publish the trajectory command
        // Assume publish_cmd is your publishing function
        publish_cmd(pos, vel, acc, jer, yaw, yawdot);

        // Increment time
        t += dt;

        // Sleep to maintain the loop rate
        rate.sleep();
    }

    return 0;
}
