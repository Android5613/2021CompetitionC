#include "Robot.h"

void Robot::limelight() {
  
  // The angle offset to the target on the horizontal axis.
  double tx = limelighttable->GetNumber("tx",0.0);
  // The angle offset to the target on the vertical axis.
  double ty = limelighttable->GetNumber("ty",0.0);
  // The angle the camera is mounted at in degrees.
  int angle = 30;
  
  // The target height - the camera mount height / tangent of ty + angle.
  float distance = 64.25/(tan(ty+angle));
  // The error in the robot positioning.
  float heading_error = -tx;
  // The error in the robot's distance from the target.
  float distance_error = distance - 24;
  
  float steering_adjust = 0;
  
  if (tx > 0.5) {
    float steering_ajust = KpAim*heading_error - min_command;
  }
  else if (tx < -0.5) {
    float steering_adjust = KpAim*heading_error - min_command;
  }
  
  float distance_adjust = KpDistance * distance_error;

  double left = distance_adjust + steering_adjust;
  double right = distance_adjust - steering_adjust;

  // Moves the motors
  FLMotor.Set(ControlMode::PercentOutput, -left);
  RLMotor.Set(ControlMode::PercentOutput, -left);
  FRMotor.Set(ControlMode::PercentOutput, right);
  RRMotor.Set(ControlMode::PercentOutput, right);
}

void Robot::limelightauto() {
  double tv = limelighttable->GetNumber("tv", 0.0);
  
  // The angle offset to the target on the horizontal axis.
  double tx = limelighttable->GetNumber("tx",0.0);
  // The angle offset to the target on the vertical axis.
  double ty = limelighttable->GetNumber("ty",0.0);
  // The angle the camera is mounted at in degrees.
  int angle = 30;
  
  if (tv == 1) {
    // The target height - the camera mount height / tangent of ty + angle.
    float distance = 64.25/(tan(ty+angle));
    // The error in the robot positioning.
    float heading_error = -tx;
    // The error in the robot's distance from the target.
    float distance_error = distance - 24;
  
    float steering_adjust = 0;
  
    if (tx > 0.5) {
      float steering_ajust = KpAim*heading_error - min_command;
    }
    else if (tx < -0.5) {
      float steering_adjust = KpAim*heading_error - min_command;
    }
  
    float distance_adjust = KpDistance * distance_error;

    double left = distance_adjust + steering_adjust;
    double right = distance_adjust - steering_adjust;
  
    // Moves the motors
    FLMotor.Set(ControlMode::PercentOutput, -left);
    RLMotor.Set(ControlMode::PercentOutput, -left);
    FRMotor.Set(ControlMode::PercentOutput, right);
    RRMotor.Set(ControlMode::PercentOutput, right);
    if ( -0.5 < tx < 0.5 and -1 <= distance_error <= 1) {
      
    }

  }

  else {
    float left = 0.5;
    float right = 0.5;

    // Turns the robot at a safe speed to look for a target.
    FLMotor.Set(ControlMode::PercentOutput, left);
    RLMotor.Set(ControlMode::PercentOutput, left);
    FRMotor.Set(ControlMode::PercentOutput, right);
    RRMotor.Set(ControlMode::PercentOutput, right);
  }
}
