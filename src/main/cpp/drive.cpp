#include "Robot.h"

// This is the drive function to drive the robot.
void Robot::arcade_drive() {

  // Grabs values from the joysticks, multiplies them by a constant, and stores them in a variable.
  // To change the sensitivity, change the constant.
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
  
}

