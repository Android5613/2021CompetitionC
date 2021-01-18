#include "Robot.h"

// This is the drive function to drive the robot.
void Robot::arcade_drive() {
  //if (0.05 < DriveStick.GetX() or -0.05 > DriveStick.GetX() or 0.05 < DriveStick.GetZ() or -0.05 > DriveStick.GetZ()) 
  //{
    double speed = DriveStick.GetY();
    double turn = DriveStick.GetZ() * -.45;
  
    // Sets the motors to be the speed with the turn value.
    double left = speed+turn;
    double right = speed-turn;
  
    // Moves the motors
    FLMotor.Set(ControlMode::PercentOutput, -left);
    RLMotor.Set(ControlMode::PercentOutput, -left);
    FRMotor.Set(ControlMode::PercentOutput, right);
    RRMotor.Set(ControlMode::PercentOutput, right);
  //}
}

