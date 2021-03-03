#include "Robot.h"

// This is the drive function to drive the robot.
void Robot::arcade_drive() {
  
  double speed = 0;
  double turn = 0;
  
  if (DriveStick.GetY() >=0.05) {
    double speed = DriveStick.GetY();
  } 
  if (DriveStick.GetZ() >=0.05) {
    double turn = DriveStick.GetZ() * -.45;
  } 
  
  // Sets the motors to be the speed with the turn value.
  double left = speed+turn;
  double right = speed-turn;
  
  // Moves the motors
  FLMotor.Set(ControlMode::PercentOutput, -left);
  RLMotor.Set(ControlMode::PercentOutput, -left);
  FRMotor.Set(ControlMode::PercentOutput, right);
  RRMotor.Set(ControlMode::PercentOutput, right);
  
}

