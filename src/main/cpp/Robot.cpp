/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

//#include <frc/smartdashboard/SmartDashboard.h>

//#include "cameraserver/CameraServer.h"

// Tells the drive to turn off after .1 seconds and starts a timer.
Robot::Robot() {
  
}
// Run on robot startup.
void Robot::RobotInit() {
  
}
// Run with every packet recieved from robot.
void Robot::RobotPeriodic() {

}
// Initializes autonomous specific items. Run on startup of autonomous.
void Robot::AutonomousInit() {
  // time.Reset();
}
// Run every .02 seconds during autonomous. May be overriden by the computer because .02 seconds is too slow.
void Robot::AutonomousPeriodic() {
  /*time.Start();
  
  if (time.Get() <= 1) {
    FLMotor.Set(ControlMode::PercentOutput, -0.7);
    RLMotor.Set(ControlMode::PercentOutput, -0.7);
    FRMotor.Set(ControlMode::PercentOutput, 0.7);
    RRMotor.Set(ControlMode::PercentOutput, 0.7);
  }
  else if (time.Get() > 1) {
    limelightauto();
  }*/
}
// Initializes teleop specific items. Run on startup of teleop.
void Robot::TeleopInit() {

}
// Run every .02 seconds during teleop. May be overriden by the computer because .02 seconds is too slow.
void Robot::TeleopPeriodic() {
  userControl();
  arcade_drive();
}
// Initializes disabled specific items. Run on start of disabled mode.
void Robot::DisabledInit() {

}
// Run every .02 seconds during disabled. May be overriden by the computer because .02 seconds is too slow.
void Robot::DisabledPeriodic() {
  
}
// Initializes test specific items. Run on startup of test mode.
void Robot::TestInit() {

}
// Run every .02 seconds during test mode. May be overriden by the computer because .02 seconds is too slow.
void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
